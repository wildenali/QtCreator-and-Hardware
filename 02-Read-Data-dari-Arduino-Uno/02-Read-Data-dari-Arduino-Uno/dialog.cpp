#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->lcd_Temp->display("--------");

    arduinoPort = new QSerialPort;
    arduino_is_available = false;
    arduino_port_name = "";

    serialBuffer = "";

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
            if(serialPortInfo.hasVendorIdentifier() &&  serialPortInfo.hasProductIdentifier()){
                if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                    if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                        arduino_port_name = serialPortInfo.portName();
                        arduino_is_available = true;
                    }
                }
            }
    }

    if(arduino_is_available) {
        // open and configure the serialport
        arduinoPort->setPortName(arduino_port_name);
//        arduinoPort->open(QSerialPort::WriteOnly);
        arduinoPort->open(QSerialPort::ReadOnly);
        arduinoPort->setBaudRate(QSerialPort::Baud9600);
        arduinoPort->setDataBits(QSerialPort::Data8);
        arduinoPort->setParity(QSerialPort::NoParity);
        arduinoPort->setStopBits(QSerialPort::OneStop);
        arduinoPort->setFlowControl(QSerialPort::NoFlowControl);
        QObject::connect(arduinoPort, SIGNAL(readyRead()), this, SLOT(readSerial()));
    } else {
        // give error message if not available
        QMessageBox::warning(this, "Port nya Error", "Tidak menemukan arduino");
    }


}

Dialog::~Dialog()
{
    if(arduinoPort->isOpen()) {
        arduinoPort->close();
    }
    delete ui;
}

void Dialog::readSerial() {
//    serialData = arduinoPort->readAll();
//    QString data = QString::fromStdString(serialData.toStdString());
//    qDebug() << data;

    QStringList bufferSplit = serialBuffer.split(",");
    if(bufferSplit.length() < 3) {
        serialData = arduinoPort->readAll();
        serialBuffer += QString::fromStdString(serialData.toStdString());
    } else {
        qDebug() << bufferSplit;
        Dialog::updateLCD(bufferSplit[1]);
        serialBuffer = "";
    }
}

void Dialog::updateLCD(const QString baca_data) {
    ui->lcd_Temp->display(baca_data);
}
