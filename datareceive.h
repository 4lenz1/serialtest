#ifndef DATARECEIVE_H
#define DATARECEIVE_H

#include <QObject>
#include <QSerialPort>
class dataReceive : public QObject
{
    Q_OBJECT
public:
    explicit dataReceive(QObject *parent = 0);
    void serialport();
signals:

public slots:
    void getData();
};

#endif // DATARECEIVE_H
