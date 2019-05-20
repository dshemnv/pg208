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
    centre->setPosition(x, y);
}

void Cercle::setRadius(int r)
{
    rayon = r;
}

void Cercle::setColor(Color color, int transparence)
{
    trace->setColor(color, transparence);
}

void Cercle::drawCircle(CImage *img, CImage *plan)
{
    double xo = centre->getPosX();
    double yo = centre->getPosY();
    int R = rayon;

    for (double x = (xo - R); x < xo + R + 1; x++)
    {
        for (double y = (yo - R); y < yo + R + 1; y++)
        {
            double R2 = pow((x - xo), 2) + pow((y - yo), 2);
            if (R2 / pow(R, 2) >= 0.95 && R2 / pow(R, 2) <= 1.1)
            {
                trace->setPosition(x, y);
                trace->drawPoint(img, plan);
            }
        }
    }
}

void Cercle::drawCircles(CImage *img, CImage *plan)
{
    double xo = centre->getPosX();
    double yo = centre->getPosY();
    int R = rayon;

    for (double x = (xo - R); x < xo + R + 1; x++)
    {
        for (double y = (yo - R); y < yo + R + 1; y++)
        {
            double R2 = pow((x - xo), 2) + pow((y - yo), 2);
            if (R2 / pow(R, 2) <= 1)
            {
                trace->setPosition(x, y);
                trace->drawPoint(img, plan);
            }
        }
    }
}

void Cercle::setPlan(int plan)
{
    trace->setPlan(plan);
}

int Cercle::getPlan()
{
    return trace->getPlan();
}

int Cercle::getPosY()
{
    return centre->getPosY();
}
int Cercle::getPosX()
{
    return centre->getPosX();
}
int Cercle::getRadius()
{
    return rayon;
}