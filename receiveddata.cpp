#include "receiveddata.h"
#include <QSerialPort>
QSerialPort *serial ;
receivedData::receivedData()
{
    serial = new QSerialPort(this);

    //serial = new QSerialPort(this);
    serial.setPortName("COM5");
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setParity(QSerialPort::NoParity);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);
    serial.readyRead();
    //serial.write("ok");
    connect(serial,SIGNAL(readyRead()) , this , SLOT(serialRecieced()) );
    while(true){
        serial.write("yoo");
        QByteArray array;
        array = serial.readAll();
        qDebug()<< array ;
    }
}
void receivedData::serialRecieced(){
    qDebug() << serial.readAll();
}
