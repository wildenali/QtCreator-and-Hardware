#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_horizontalSlider_Led1_valueChanged(int value);

    void on_horizontalSlider_Led2_valueChanged(int value);

    void on_horizontalSlider_Led3_valueChanged(int value);

    void updateLed(QString);

private:
    Ui::Dialog *ui;
    QSerialPort *arduinoPort;
    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;
    QString arduino_port_name;
    bool arduino_is_available;
};

#endif // DIALOG_H
