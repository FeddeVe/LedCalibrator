#ifndef LED_H
#define LED_H

#include <QObject>
#include "Utils/color.h"

class LED
{

public:
    LED(int id);
    ~LED();

    int getID() const {return m_id;};
    bool getEnabled() const {return m_enabled;};
    bool setEnabled(bool enabled);

    bool setName(QString name);
    QString getName() const{return m_name;};

    int getWaveLength() const {return m_clr.getWaveLength();};
    bool setWaveLength(int waveLength);

    double getX() const{return m_clr.getX();};
    bool setX(double x);

    double getY() const{return m_clr.getY();};
     bool setY(double y);

    uint8_t getR() const{return m_clr.getR();};
    uint8_t getG() const{return m_clr.getG();};
    uint8_t getB() const{return m_clr.getB();};

    bool setDistance(double distance);
    double getDistance() const{return m_distance;};

    double getPercent() const{return m_percent;};

private:
    int m_id;
    bool m_enabled;
    QString m_name;
    Color m_clr;
    double m_distance;
    double m_percent;
    uint16_t output;


signals:
};

#endif // LED_H
