#ifndef COLOR_H
#define COLOR_H

#include <QObject>

class Color : public QObject
{
    Q_OBJECT
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

    explicit Color(QObject *parent = nullptr);




private:
    XY m_xy;
    RGB m_rgb;

signals:
};

#endif // COLOR_H
