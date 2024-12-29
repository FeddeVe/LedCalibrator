#ifndef COLOR_H
#define COLOR_H

#include <QObject>
#include <QColor>

class Color
{
public:

    struct XY{
        float x;
        float y;
    };

    struct RGB{
        uint8_t R;
        uint8_t G;
        uint8_t B;
    };

    Color();
    Color(float x, float y);
    Color(uint8_t R, uint8_t G, uint8_t B);

    QColor qColor();



private:
    XY m_xy;
    RGB m_rgb;

    void XYToRGB();
    void RGBToXY();

signals:
};

#endif // COLOR_H
