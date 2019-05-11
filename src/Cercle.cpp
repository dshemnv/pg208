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

void Cercle::drawCircle(CImage *img)
{
    double xo = centre->getPosX();
    double yo = centre->getPosY();
    int R = rayon;

    for (double x = (xo - R); x < xo + R + 1; x++)
    {
        for (double y = (yo - R); y < yo + R + 1; y++)
        {
            double R2 = pow((x - xo), 2) + pow((y - yo), 2);
            if (R2 / pow(R, 2) >= 0.95 && R2 / pow(R, 2) <= 1.05)
            {
                trace->setPosition(x, y);
                trace->drawPoint(img);
            }
        }
    }
}

void Cercle::drawCircles(CImage *img)
{
    double xo = centre->getPosX();
    double yo = centre->getPosY();
    int R = rayon;

    for (double x = (xo - R); x < xo + R + 1; x++)
    {
        for (double y = (yo - R); y < yo + R + 1; y++)
        {
            double R2 = pow((x - xo), 2) + pow((y - yo), 2);
            if (R2 / pow(R, 2) <= 1.02)
            {
                trace->setPosition(x, y);
                trace->drawPoint(img);
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