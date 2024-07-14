#include "point_with_servo.h"
#include <QtWidgets/QApplication>
#include <QDebug.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialCom serial;
    point_with_servo w(&serial);
    w.show();
    return a.exec();
}
