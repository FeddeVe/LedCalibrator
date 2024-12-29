#ifndef LEDS_H
#define LEDS_H

#include <QObject>
#include "Led/led.h"

class LEDS : public QObject
{
    Q_OBJECT
public:
    explicit LEDS(QObject *parent = nullptr);



private:
    std::vector<LED> m_leds;

signals:
};

#endif // LEDS_H
