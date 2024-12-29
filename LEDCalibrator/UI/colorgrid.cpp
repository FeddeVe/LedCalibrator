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

        }
    }

    painter.drawPoint(0,0);
painter.drawPoint(1,1);
painter.drawPoint(4,4);

    painter.end();
}
