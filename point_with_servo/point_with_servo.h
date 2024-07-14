#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_point_with_servo.h"
#include <QSerialPort.h>
#include <QSerialPortInfo.h>
#include <QTimer>



class SerialCom
{
protected:
    const char* portName = "COM3";
    QSerialPort serial;

public:
    SerialCom();

    void send(const QByteArray& data);
    void send(const QString& data);
    void send(const char data);
    void send(const int data);
    void send(const char direction, const char data);
    void send(const char direction, const int data);
    
};




class point_with_servo : public QMainWindow
{
    Q_OBJECT

public:
    SerialCom* serial;
    int horizontalAngle = 90;
    int verticalAngle = 90;

public:
    point_with_servo(SerialCom* serial, QWidget* parent = nullptr);
    ~point_with_servo();
    void sendData();



private slots:
    void on_upBtn_clicked();
    void on_downBtn_clicked();
    void on_leftBtn_clicked();
    void on_rightBtn_clicked();


 


private:
    Ui::point_with_servoClass ui;

    QTimer* sendDataTimer;
};
