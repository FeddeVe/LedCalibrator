#include "leds.h"

LEDS::LEDS(QObject *parent)
    : QObject{parent}
{
    load();
}

LEDS::~LEDS(){
    for(size_t i = 0; i < m_leds.size();i++){
        delete m_leds[i];
    }
}

LED *LEDS::addLed()
{
    int id = 0;
    for(size_t i = 0; i < m_leds.size(); i++){
        if(m_leds[i]->getID() >= id){
            id = m_leds[i]->getID() + 1;
        }
    }

    LED *l = new LED(id);
    m_leds.push_back(l);

    return l;
}

LED *LEDS::getLed(int id)
{
    for(size_t i = 0; i < m_leds.size(); i++){
        if(m_leds[i]->getID() == id){
            return m_leds[i];
        }
    }
    return nullptr;
}

void LEDS::save()
{
    QString filename =QCoreApplication::applicationDirPath() + "/LedConfig.txt";
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        for(size_t i = 0; i < m_leds.size(); i++){
            stream << m_leds[i]->getID() << ";" << m_leds[i]->getName() << ";" << m_leds[i]->getWaveLength() << ";" << m_leds[i]->getX() << ";" << m_leds[i]->getY() << '\n';
        }
        file.close();
    }

}

void LEDS::load()
{
    QString filename =QCoreApplication::applicationDirPath() + "/LedConfig.txt";
    QFile file(filename);
    if(file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);
        while(!stream.atEnd()){
            QString line = stream.readLine();
            QStringList tmp = line.split(";");
            if(tmp.size() < 5){
                continue;
            }
            int id = tmp[0].toInt();
            LED *l = new LED(id);
            l->setName(tmp[1]);
            l->setWaveLength(tmp[2].toInt());
            l->setX(tmp[3].toDouble());
            l->setY(tmp[4].toDouble());
            m_leds.push_back(l);
        }
        file.close();
    }
}

void LEDS::calcOutput(double x, double y)
{
    for(size_t i = 0; i < m_leds.size(); i++){
        LED *l = m_leds[i];
        double deltaX = x - l->getX();
        double deltaY = y - l->getY();
        l->setDistance(sqrt(deltaX * deltaX + deltaY * deltaY));
    }

}
