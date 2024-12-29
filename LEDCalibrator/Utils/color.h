#ifndef COLOR_H
#define COLOR_H

#include <QObject>
#include <QColor>
#include <math.h>

class Color
{
public:

    struct XY{
        double x;
        double y;
    };

    struct RGB{
        uint8_t R;
        uint8_t G;
        uint8_t B;
    };

    Color();
    Color(double x, double y);
    Color(uint8_t R, uint8_t G, uint8_t B);

    QColor qColor();

    int getWaveLength()const {return m_waveLength;};
    bool setWaveLength(int waveLength);

    double getX() const{return m_xy.x;};
    double getY() const{return m_xy.y;};

    bool setX(double x);
    bool setY(double y);

    uint8_t getR() const{return m_rgb.R;};
    uint8_t getG() const{return m_rgb.G;};
    uint8_t getB() const{return m_rgb.B;};


private:
    XY m_xy;
    RGB m_rgb;
    int m_waveLength;

    void XYToRGB();
    void RGBToXY();

    void cie1931WavelengthToXYZFit(double wavelength);

signals:
};

#endif // COLOR_H
