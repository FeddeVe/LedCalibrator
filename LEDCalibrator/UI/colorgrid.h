#ifndef COLORGRID_H
#define COLORGRID_H

#include <QWidget>
#include <QPainter>
#include <QBrush>

#include "Utils/color.h"

class ColorGrid : public QWidget
{
    Q_OBJECT
public:
    explicit ColorGrid(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:

signals:
};

#endif // COLORGRID_H
