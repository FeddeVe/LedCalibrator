#ifndef LEDS_H
#define LEDS_H

#include <QObject>
#include <QApplication>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include "Led/led.h"

class LEDS : public QObject
{
    Q_OBJECT
public:
    explicit LEDS(QObject *parent = nullptr);
    ~LEDS();

    LED *addLed();
    LED *getLed(int id);

    void save();
    void load();

    std::vector<LED*> m_leds;

    void calcOutput(double x, double y);

private:


signals:
};

#endif // LEDS_H
