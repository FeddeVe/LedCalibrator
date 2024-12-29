#include "color.h"

Color::Color(){
    m_xy.x = 0;
    m_xy.y = 0;
    m_rgb.R = 0;
    m_rgb.G = 0;
    m_rgb.B = 0;
}

Color::Color(double x, double y)
{
    m_xy.x = x;
    m_xy.y = y;
    XYToRGB();
}

Color::Color(uint8_t R, uint8_t G, uint8_t B)
{
    m_rgb.R = R;
    m_rgb.G = G;
    m_rgb.B = B;
}

QColor Color::qColor()
{
    return QColor::fromRgb(m_rgb.R, m_rgb.G, m_rgb.B);
}

bool Color::setWaveLength(int waveLength)
{
    if(m_waveLength == waveLength){
        return false;
    }
    m_waveLength = waveLength;
   // cie1931WavelengthToXYZFit(waveLength);
    return true;
}

bool Color::setX(double x)
{
    if(m_xy.x == x){
        return false;
    }
    m_xy.x = x;
    XYToRGB();
    return true;
}


bool Color::setY(double y)
{
    if(m_xy.y == y){
        return false;
    }
    m_xy.y = y;
    XYToRGB();
    return true;
}

void Color::XYToRGB()
{
    double z = 1.0f - m_xy.x - m_xy.y;
    double Y = 1.0f;
    double X =(Y/m_xy.y) * m_xy.x;
    double Z = (Y/m_xy.y) * z;

    double r = X * 1.656492f - Y * 0.354851f - Z * 0.255038f;
    double g = -X * 0.707196f + Y * 1.655397f + Z * 0.036152f;
    double b = X * 0.051713f - Y * 0.121364f + Z * 1.011530f;

    // sRGB D65 conversion
    r = X  * 3.2406f - Y * 1.5372f - Z * 0.4986f;
    g = -X * 0.9689f + Y * 1.8758f + Z * 0.0415f;
    b = X  * 0.0557f - Y * 0.2040f + Z * 1.0570f;

    /*
    if (r > b && r > g && r > 1.0f) {
        // red is too big
        g = g / r;
        b = b / r;
        r = 1.0f;
    }
    else if (g > b && g > r && g > 1.0f) {
        // green is too big
        r = r / g;
        b = b / g;
        g = 1.0f;
    }
    else if (b > r && b > g && b > 1.0f) {
        // blue is too big
        r = r / b;
        g = g / b;
        b = 1.0f;
    }
*/

    // Apply gamma correction
     r = r <= 0.0031308f ? 12.92f * r : (1.0f + 0.055f) * pow(r, (1.0f / 2.4f)) - 0.055f;
     g = g <= 0.0031308f ? 12.92f * g : (1.0f + 0.055f) * pow(g, (1.0f / 2.4f)) - 0.055f;
     b = b <= 0.0031308f ? 12.92f * b : (1.0f + 0.055f) * pow(b, (1.0f / 2.4f)) - 0.055f;


    if (r > b && r > g) {
        // red is biggest
        if (r > 1.0f) {
            g = g / r;
            b = b / r;
            r = 1.0f;
        }
    }
    else if (g > b && g > r) {
        // green is biggest
        if (g > 1.0f) {
            r = r / g;
            b = b / g;
            g = 1.0f;
        }
    }
    else if (b > r && b > g) {
        // blue is biggest
        if (b > 1.0f) {
            r = r / b;
            g = g / b;
            b = 1.0f;
        }
    }

    if(r<0){
        r=0;
    }
    if(g<0){
        g=0;
    }
    if(b<0){
        b=0;
    }

    m_rgb.R = 255 * r;
    m_rgb.G = 255 * g;
    m_rgb.B = 255 * b;
}

void Color::cie1931WavelengthToXYZFit(double wavelength)
{
    double wave = wavelength;

    double x;
    {
        double t1 = (wave - 442.0) * ((wave < 442.0) ? 0.0624 : 0.0374);
        double t2 = (wave - 599.8) * ((wave < 599.8) ? 0.0264 : 0.0323);
        double t3 = (wave - 501.1) * ((wave < 501.1) ? 0.0490 : 0.0382);


        x =   0.362 * std::exp(-0.5 * t1 * t1)
            + 1.056 * std::exp(-0.5 * t2 * t2)
            - 0.065 * std::exp(-0.5 * t3 * t3);
    }

    double y;
    {
        double t1 = (wave - 568.8) * ((wave < 568.8) ? 0.0213 : 0.0247);
        double t2 = (wave - 530.9) * ((wave < 530.9) ? 0.0613 : 0.0322);

        y =   0.821 * std::exp(-0.5 * t1 * t1)
            + 0.286 * std::exp(-0.5 * t2 * t2);
    }

    double z;
    {
        double t1 = (wave - 437.0) * ((wave < 437.0) ? 0.0845 : 0.0278);
        double t2 = (wave - 459.0) * ((wave < 459.0) ? 0.0385 : 0.0725);

        z =   1.217 * std::exp(-0.5 * t1 * t1)
            + 0.681 * std::exp(-0.5 * t2 * t2);
    }

    m_xy.x = x;
    m_xy.y = y;
    XYToRGB();
}
