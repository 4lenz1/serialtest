#ifndef READDATA_H
#define READDATA_H
#include <QSerialPort>
#include <QObject>
class readData
{
public:
    readData();

private slots:
    void receiveData();
};

#endif // READDATA_H
