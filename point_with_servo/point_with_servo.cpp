#include "point_with_servo.h"

point_with_servo::point_with_servo(SerialCom* serial, QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	this->serial = serial;

	connect(ui.upBtn, &QPushButton::clicked, this, &point_with_servo::on_upBtn_clicked);


	sendDataTimer = new QTimer(this);
	connect(sendDataTimer, &QTimer::timeout, this, &point_with_servo::sendData);
	sendDataTimer->start(1000);
}

point_with_servo::~point_with_servo()
{}

void point_with_servo::sendData()
{
	serial->send(horizontalAngle);
	serial->send(verticalAngle);
	
}

void point_with_servo::on_upBtn_clicked()
{
	verticalAngle++;
	if (verticalAngle > 180)
		verticalAngle = 180;
	sendData();
}

void point_with_servo::on_downBtn_clicked()
{
	verticalAngle--;
	if (verticalAngle < 0)
		verticalAngle = 0;
	sendData();
}

void point_with_servo::on_leftBtn_clicked()
{
	horizontalAngle--;
	if (horizontalAngle < 0)
		horizontalAngle = 0;
	sendData();
}

void point_with_servo::on_rightBtn_clicked()
{
	horizontalAngle++;
	if (horizontalAngle > 180)
		horizontalAngle = 180;
	sendData();
}









SerialCom::SerialCom()
{
	serial.setPortName(portName);

	if (serial.open(QIODevice::ReadWrite))
	{
		serial.setBaudRate(QSerialPort::Baud9600);
		serial.setDataBits(QSerialPort::Data8);
	}
	else 
	{
		throw std::runtime_error("Failed to open serial port");
	}
}


void SerialCom::send(const QByteArray& data)
{
	serial.write(data);
}

void SerialCom::send(const QString& data)
{
	serial.write(data.toUtf8());
}

void SerialCom::send(const char data)
{
	serial.write(&data, 1);
}

void SerialCom::send(const int data)
{
	send(static_cast<char>(data));
}

void SerialCom::send(const char direction, const char data)
{
	QByteArray dataToSend(2, '\0');
	dataToSend[0] = direction;
	dataToSend[1] = data;

	serial.write(dataToSend);
}


void SerialCom::send(const char direction, const int data)
{
	send(direction, static_cast<char>(data));
}

