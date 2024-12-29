#include "led.h"



LED::LED(int id)
    : m_id{id}, m_enabled(true)
{

}

LED::~LED(){

}

bool LED::setEnabled(bool enabled)
{
    if(m_enabled == enabled){
        return false;
    }

    m_enabled = enabled;
    return true;
}

bool LED::setName(QString name)
{
    if(m_name == name){
        return false;
    }
    m_name = name;
    return true;
}

bool LED::setWaveLength(int waveLength)
{
    if(m_clr.getWaveLength() == waveLength){
        return false;
    }

    m_clr.setWaveLength(waveLength);
    return true;
}

bool LED::setX(double x)
{
    return m_clr.setX(x);
}


bool LED::setY(double y)
{
    return m_clr.setY(y);
}

bool LED::setDistance(double distance)
{
    if(m_distance == distance){
        return false;
    }
    m_distance = distance;
    m_percent = 1.0-distance;
    return true;
}

