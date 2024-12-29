#include "colorgrid.h"

ColorGrid::ColorGrid(QWidget *parent)
    : QWidget{parent}
{}

void ColorGrid::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int width = this->width();
    int height = this->height();
    QBrush backgroundBrush;
    backgroundBrush.setColor(QColor::fromRgb(255,0,255));
    backgroundBrush.setStyle(Qt::SolidPattern);
    painter.fillRect(0,0,width, height, backgroundBrush);

    QBrush colorBrush;
    colorBrush.setColor(QColor::fromRgb(0,255,0));
    QPen pointPen;
    pointPen.setColor(QColor::fromRgb(0,255,0));
    pointPen.setWidth(1);
    painter.setPen(pointPen);

    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            float gridX = static_cast<float>(x)/width;
            float gridY = static_cast<float>(y)/height;

            Color c(gridX, 1.0-gridY);
            pointPen.setColor(c.qColor());
            painter.setPen(pointPen);
            painter.drawPoint(x,y);
        }
    }

    painter.end();
}
