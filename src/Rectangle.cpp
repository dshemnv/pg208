#include "Rectangle.h"

Rectangle::Rectangle()
{
    ligne = new Ligne();
}

Rectangle::~Rectangle()
{
}

Carre::Carre()
{
}

Carre::~Carre()
{
}

void Rectangle::setPosition(int x, int y)
{
    double Xo = (double)x;
    double Yo = (double)y;

    posX = x;
    posY = y;

    ligne->setCoordinates(Xo, Yo, Xo, Yo);
}

void Rectangle::setLengths(int length, int width)
{
    longeur = length;
    largeur = width;
}

void Carre::setLengths(int width)
{
    Rectangle::setLengths(width, width);
}

void Rectangle::setColor(Color color, int transparence)
{
    ligne->setColor(color, transparence);
}

void Rectangle::drawSide(int coordX, int coordY, CImage *img, CImage *plan)
{
    double Xo = ligne->getPosX();
    double Yo = ligne->getPosY();

    int i = coordX + coordY;

    switch (i)
    {
    case 0:
        ligne->setCoordinates(Xo, Yo, Xo, Yo + (double)largeur - 1);
        break;
    case 1:
        if (coordY)
        {
            ligne->setCoordinates(Xo, Yo + 1, Xo + (double)longeur - 1, Yo + 1);
            break;
        }
        else
        {
            ligne->setCoordinates(Xo, Yo - 1, Xo - (double)longeur + 1, Yo - 1);
            break;
        }
    case 2:
        ligne->setCoordinates(Xo + 1, Yo, Xo + 1, Yo - (double)largeur + 1);
        break;
    default:
        break;
    }
    ligne->drawLigne(img, plan);
}

void Rectangle::drawRectangle(CImage *img, CImage *plan)
{
    drawSide(0, 0, img, plan);

    /*

    *
    * 
    * 

    */

    drawSide(0, 1, img, plan);

    /*

    * * * *
    *     
    *     

    */

    drawSide(1, 1, img, plan);

    /*

    * * * *
    *     *
    *     *

    */

    drawSide(1, 0, img, plan);

    /*

    * * * *
    *     *
    * * * *

    */
}

void Rectangle::drawRectangles(CImage *img, CImage *plan)
{

    drawRectangle(img, plan);
    for (int i = 1; i < largeur; i++)
    {
        ligne->setCoordinates((double)posX + 1, (double)posY + i, (double)posX + longeur - 1, (double)posY + i);
        ligne->drawLigne(img, plan);
    }
}

void Rectangle::setPlan(int p)
{
    ligne->setPlan(p);
}

int Rectangle::getLength()
{
    return longeur;
}

int Rectangle::getPosX()
{
    return posX;
}
int Rectangle::getPosY()
{
    return posY;
}

int Rectangle::getWidth()
{
    return largeur;
}

int Rectangle::getPlan()
{
    return ligne->getPlan();
}