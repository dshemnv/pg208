#include "Ligne.h"

Ligne::Ligne()
{
    origine = new Point();
    fin = new Point();
    trace = new Point();
}

Ligne::~Ligne()
{

}

void Ligne::setCoordinates(int x1, int y1, int x2, int y2)
{
    if (x1 < x2)
    {
        if (y1 < y2)
        {
            origine->setPosition(x1,y1);
            fin->setPosition(x2,y2);
        }
        else
        {
            origine->setPosition(x2,y2);
            fin->setPosition(x1,y1);
        }
    }
    else
    {
        if (y2 < y1)
        {
            origine->setPosition(x2,y2);
            fin->setPosition(x1,y1);
        }
        else
        {
            origine->setPosition(x1,y1);
            fin->setPosition(x2,y2);    
        }   
            
    }
    trace->setPosition(origine->getPosX(),origine->getPosY());
}

void Ligne::setColorLine(Color color)
{
    trace->setColor(color);
}

void Ligne::drawLigne(CImage *img)
{
    double xo = (double) origine->getPosX();
    double yo = (double) origine->getPosY();

    double xf = (double) fin->getPosX();
    double yf = (double) fin->getPosY();

    double coef = (yf - yo)/(xf - xo);

    while(trace->getPosX() != xf && trace->getPosY() != yf)
    {
        trace->setPosition((int)xo,(int)yo);
        trace->drawPoint(img);
        xo++;
        yo += coef;
    }
}