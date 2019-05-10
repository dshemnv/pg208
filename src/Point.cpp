#include "Point.h"

Point::Point(int X, int Y)
{
    pixel = new CPixel();
    setPosition(X, Y);
}

Point::Point()
{
    pixel = new CPixel();
}

Point::~Point()
{
}

void Point::setColor(Color color, int transparence)
{
    switch (color)
    {
    case blue:
        pixel->RGB(0, 0, 255);
        break;

    case red:
        pixel->RGB(255, 0, 0);
        break;

    case green:
        pixel->RGB(0, 255, 0);
        break;
    case cyan:
        pixel->RGB(0, 255, 255);
        break;

    case olive:
        pixel->RGB(128, 128, 0);
        break;

    default:
        break;
    }

    setTransparency(transparence);   
    
}

void Point::setPosition(double x, double y)
{
    posX = (int)x;
    posY = (int)y;
}

void Point::setTransparency(int transp)
{
    transparence = transp;
}

CPixel* Point::drawTransparency(CPixel *oldp)
{
    CPixel *tr_pix = new CPixel();
    int red = ((100 - transparence) * oldp->Red() + transparence * pixel->Red()) / 100;
    int green = ((100 - transparence) * oldp->Green() + transparence * pixel->Green()) / 100;
    int blue = ((100 - transparence) * oldp->Blue() + transparence * pixel->Blue()) / 100;
    tr_pix->RGB(red, green, blue);
    return tr_pix;
}

void Point::drawPoint(CImage *img)
{
    CPixel *pi = img->getPixel(posX, posY);
    pi->RGB(drawTransparency(pi)->Red(), drawTransparency(pi)->Green(), drawTransparency(pi)->Blue());
}

double Point::getPosX()
{
    return (double)posX;
}

double Point::getPosY()
{
    return (double)posY;
}