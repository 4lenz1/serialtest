#include "datareceive.h"
#include <QDebug>

QSerialPort serial;

dataReceive::dataReceive(QObject *parent) : QObject(parent)
{
    serial.setPortName("COM5");
    serial.open(QIODevice::ReadWrite);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::HardwareControl);

    connect(&serial, SIGNAL(readyRead()) , this  , SLOT(getData()));

}


void dataReceive::getData(){
    QByteArray byteArray;
    byteArray = serial.readAll();
    qDebug() << byteArray  ;
}
