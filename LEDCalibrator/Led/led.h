#ifndef LED_H
#define LED_H

#include <QObject>
#include "Utils/color.h"

class LED
{

public:
    LED();
    ~LED();

private:
    int m_id;
    QString m_name;
    int m_waveLength;
    Color m_clr;

signals:
};

#endif // LED_H
