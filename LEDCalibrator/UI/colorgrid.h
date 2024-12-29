#ifndef COLORGRID_H
#define COLORGRID_H

#include <QWidget>
#include <QPainter>
#include <QBrush>
#include <QMouseEvent>

#include "Utils/color.h"
#include "Utils/triangle.h"
#include "Led/leds.h"

class ColorGrid : public QWidget
{
    Q_OBJECT
public:
    explicit ColorGrid(LEDS *leds, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


private:

    LEDS *m_leds;
    void paintLeds(QPainter &painter);

    double m_mouseX;
    double m_mouseY;

signals:
    void colorChanged();
};

#endif // COLORGRID_H
