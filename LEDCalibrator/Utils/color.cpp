#include "color.h"

Color::Color(){
    m_xy.x = 0;
    m_xy.y = 0;
    m_rgb.R = 0;
    m_rgb.G = 0;
    m_rgb.B = 0;
}

Color::Color(float x, float y)
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

void Color::XYToRGB()
{
    float z = 1.0f - m_xy.x - m_xy.y;
    float Y = 1.0f;
    float X =(Y/m_xy.y) * m_xy.x;
    float Z = (Y/m_xy.y) * z;

    float r = X * 1.656492f - Y * 0.354851f - Z * 0.255038f;
    float g = -X * 0.707196f + Y * 1.655397f + Z * 0.036152f;
    float b = X * 0.051713f - Y * 0.121364f + Z * 1.011530f;

    r = r <= 0.0031308f ? 12.92f * r : (1.0f + 0.055f) * pow(r, (1.0f / 2.4f)) - 0.055f;
    g = g <= 0.0031308f ? 12.92f * g : (1.0f + 0.055f) * pow(g, (1.0f / 2.4f)) - 0.055f;
    b = b <= 0.0031308f ? 12.92f * b : (1.0f + 0.055f) * pow(b, (1.0f / 2.4f)) - 0.055f;

    if(r<0){
        r = 0;
    }
    if(r > 1.0){
        r = 1.0;
    }
    if(g<0){
        g = 0;
    }
    if(g > 1.0){
        g = 1.0;
    }
    if(b<0){
        b = 0;
    }
    if(b > 1.0){
        b = 1.0;
    }

    m_rgb.R = 255 * r;
    m_rgb.G = 255 * g;
    m_rgb.B = 255 * b;
}
