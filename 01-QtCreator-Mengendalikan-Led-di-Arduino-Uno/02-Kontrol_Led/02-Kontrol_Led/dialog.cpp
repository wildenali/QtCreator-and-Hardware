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

    arduino_is_available = false;
    arduino_port_name = "";
    arduinoPort = new QSerialPort;


//    // Setelah di dapet vendor id dan product id nya, ini boleh di comment
//    qDebug() << "number of available ports" << QSerialPortInfo::availablePorts().length();
//    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
//        qDebug() << "Has Vendor ID: " << serialPortInfo.hasVendorIdentifier();
//        if(serialPortInfo.hasVendorIdentifier()) {
//            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
//        }
//        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
//        if(serialPortInfo.hasProductIdentifier()) {
//            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
//        }
//    }
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
        arduinoPort->open(QSerialPort::WriteOnly);
        arduinoPort->setBaudRate(QSerialPort::Baud9600);
        arduinoPort->setDataBits(QSerialPort::Data8);
        arduinoPort->setParity(QSerialPort::NoParity);
        arduinoPort->setStopBits(QSerialPort::OneStop);
        arduinoPort->setFlowControl(QSerialPort::NoFlowControl);
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

void Dialog::on_horizontalSlider_Led1_valueChanged(int value)
{
//    ui->label_Led1_Value->setText(QString("%1%2%3").arg(value));
    ui->label_Led1_Value->setText(QString("%1").arg(value));
    Dialog::updateLed(QString("a%1").arg(value));
    qDebug() << value;
}

void Dialog::on_horizontalSlider_Led2_valueChanged(int value)
{
    ui->label_Led2_Value->setText(QString("%1").arg(value));
    Dialog::updateLed(QString("b%1").arg(value));
    qDebug() << value;
}

void Dialog::on_horizontalSlider_Led3_valueChanged(int value)
{
    ui->label_Led3_Value->setText(QString("%1").arg(value));
    Dialog::updateLed(QString("c%1").arg(value));
    qDebug() << value;
}

void Dialog::updateLed(QString command) {
    if(arduinoPort->isWritable()){
        arduinoPort->write(command.toStdString().c_str());
    } else{
        qDebug() << "Couldn't write to serial";
    }
}
