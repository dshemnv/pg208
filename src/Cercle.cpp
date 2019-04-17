#include "Cercle.h"


Cercle::Cercle()
{
    trace = new Point();
    centre = new Point();
}

Cercle::~Cercle()
{
}

void Cercle::setPosition(int x, int y)
{
    centre->setPosition(x,y);
}

void Cercle::setRadius(int r)
{
    rayon = r;
}

void Cercle::setColor(Color color)
{
    trace->setColor(color);
}

void Cercle::drawCircle(CImage *img)
{
    double xo = centre->getPosX();
    double yo = centre->getPosY();

    double x =  xo;
    double y =  yo;

    double R = (double) rayon;

    double xf = -xo;
    double yf = sqrt((R - xf + xo)*(R + xf - xo)) + yo;
    
    while (x != xf && y != yf)
    {
        trace->setPosition(x,y);
        trace->drawPoint(img);

        x = sqrt((R - y + yo)*(R + y - yo)) + xo;
        y = sqrt((R - x + xo)*(R + x - xo)) + yo;
    }
    
}