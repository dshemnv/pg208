#include "Point.h"

Point::Point(int X, int Y)
{
    pixel = new CPixel();
    setPosition(X,Y);
}

Point::Point()
{
    pixel = new CPixel();
}

Point::~Point()
{
}
 
void Point::setColor(Color color)
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
        pixel->RGB(0,255,0);
        break;
    case cyan:
        pixel->RGB(0,255,255);
        break;

    case olive:
        pixel->RGB(128,128,0);
        break;

    default:
        break;
    }       
}

void Point::setPosition(int x, int y)
{
    posX = x;
    posY = y;
}

void Point::drawPoint(CImage *img)
{
  CPixel *pi = img->getPixel(posX,posY);
  pi->RGB(pixel->Red(), pixel->Green(), pixel->Blue());
}

int Point::getPosX()
{
    return posX;
}

int Point::getPosY()
{
    return posY;
}