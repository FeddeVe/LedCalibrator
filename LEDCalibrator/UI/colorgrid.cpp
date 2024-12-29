#include "colorgrid.h"

ColorGrid::ColorGrid(LEDS *leds, QWidget *parent)
    : m_leds{leds}, QWidget{parent}, m_mouseX{0.5}, m_mouseY{0.5}
{}

void ColorGrid::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int width = this->width();
    int height = this->height();
    QBrush backgroundBrush;
    backgroundBrush.setColor(QColor::fromRgb(0,0,0));
    backgroundBrush.setStyle(Qt::SolidPattern);
    painter.fillRect(0,0,width, height, backgroundBrush);

    QBrush colorBrush;
    colorBrush.setColor(QColor::fromRgb(0,255,0));
    QPen pointPen;
    pointPen.setColor(QColor::fromRgb(0,255,0));
    pointPen.setWidth(5);
    painter.setPen(pointPen);


    for(int x = 0; x < width; x = x + 5){
        for(int y = 0; y < height; y = y + 5){
            float gridX = static_cast<float>(x)/width;
            float gridY = static_cast<float>(y)/height;
            Color c(gridX, 1.0-gridY);
            pointPen.setColor(c.qColor());
            painter.setPen(pointPen);
            painter.drawPoint(x,y);
        }
    }

    paintLeds(painter);

    QPen LEDPen;
    LEDPen.setColor(QColor::fromRgb(255,255,255));
    LEDPen.setWidth(2);
    painter.setPen(LEDPen);
    int arcWidth = 30;
    int centerX = this->width() * m_mouseX;
    int centerY = this->height() * m_mouseY;
    QRect r;
    r.setRect(centerX-arcWidth/2, centerY - arcWidth/2, arcWidth, arcWidth);
    painter.drawArc(r, 0, 360*16);

    for(size_t i = 0; i < m_leds->m_leds.size(); i++){
        LED *l = m_leds->m_leds[i];
        painter.drawLine(m_mouseX * this->width(), m_mouseY * this->height(), l->getX()* this->width(), (1.0 - l->getY()) *this->height());
    }


    painter.end();
}

void ColorGrid::mouseMoveEvent(QMouseEvent *event)
{
    int mouseX = event->pos().x();
    int mouseY = event->pos().y();
    m_mouseX = static_cast<double>(mouseX) / this->width();
    m_mouseY = static_cast<double>(mouseY) / this->height();

    m_leds->calcOutput(m_mouseX, 1.0 - m_mouseY);

    this->repaint();

    emit this->colorChanged();
}

void ColorGrid::paintLeds(QPainter &painter)
{
    QPen LEDPen;
    LEDPen.setColor(QColor::fromRgb(128,128,128));
    LEDPen.setWidth(2);
    painter.setPen(LEDPen);
    int arcWidth = 10;

    for(size_t i = 0; i < m_leds->m_leds.size(); i++){
        LED *l = m_leds->m_leds[i];
        int centerX = this->width() * l->getX();
        int centerY = this->height() * (1.0 - l->getY());
        QRect r;
        r.setRect(centerX-arcWidth/2, centerY - arcWidth/2, arcWidth, arcWidth);
        painter.drawArc(r, 0, 360*16);
    }

}
