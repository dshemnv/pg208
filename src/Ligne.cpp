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

void Ligne::setCoordinates(double x1, double y1, double x2, double y2)
{
    origine->setPosition(x1, y1);
    fin->setPosition(x2, y2);
    trace->setPosition(origine->getPosX(), origine->getPosY());
}

void Ligne::setColor(Color color, int transparence)
{
    trace->setColor(color, transparence);
}

void Ligne::drawLigne(CImage *img, CImage *plan)
{
    double xo = origine->getPosX();
    double yo = origine->getPosY();

    double xf = fin->getPosX();
    double yf = fin->getPosY();

    double coef = (yf - yo) / (xf - xo);

    if (yf == yo)
    {
        if (xf < xo)
        {
            while (trace->getPosX() > xf)
            {
                trace->setPosition(xo, yo);
                trace->drawPoint(img, plan);
                xo--;
            }
        }
        else
        {
            while (trace->getPosX() < xf)
            {
                trace->setPosition(xo, yo);
                trace->drawPoint(img, plan);
                xo++;
            }
        }
    }
    else if (xf == xo)
    {
        if (yf < yo)
        {
            while (trace->getPosY() > yf)
            {
                trace->setPosition(xo, yo);
                trace->drawPoint(img, plan);
                yo--;
            }
        }
        else
        {
            while (trace->getPosY() < yf)
            {
                trace->setPosition(xo, yo);
                trace->drawPoint(img, plan);
                yo++;
            }
        }
    }
    else
    {
        while (trace->getPosX() != xf && trace->getPosY() != yf)
        {
            trace->setPosition(xo, yo);
            trace->drawPoint(img, plan);
            xo++;
            yo += coef;
        }
    }
}

double Ligne::getPosX()
{
    return fin->getPosX();
}

double Ligne::getPosY()
{
    return fin->getPosY();
}

int Ligne::getPosXo()
{
    return origine->getPosX();
}
int Ligne::getPosYo()
{
    return origine->getPosY();
}

void Ligne::setPlan(int p)
{
    trace->setPlan(p);
}

int Ligne::getPlan()
{
    return trace->getPlan();
}
