#include "Rectangle.h"

Rectangle::Rectangle()
{
    ligne = new Ligne();
}

Rectangle::~Rectangle()
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

void Rectangle::setColor(Color color)
{
    ligne->setColorLine(color);
}

void Rectangle::drawSide(int coordX, int coordY, CImage *img)
{
    double Xo = ligne->getPosX();
    double Yo = ligne->getPosY();

    int i = coordX + coordY;

    switch (i)
    {
    case 0:
        ligne->setCoordinates(Xo, Yo, Xo, Yo + (double)largeur);
        break;
    case 1:
        if (coordY)
        {
            ligne->setCoordinates(Xo, Yo, Xo + (double)longeur, Yo);
            break;
        }
        else
        {
            ligne->setCoordinates(Xo, Yo, Xo - (double)longeur, Yo);
            break;
        }
    case 2:
        ligne->setCoordinates(Xo, Yo, Xo , Yo - (double)largeur);
        break;
    default:
        break;
    }
    ligne->drawLigne(img);
}

void Rectangle::drawRectangle(CImage *img)
{
    drawSide(0, 0, img);

    /*

    *
    * 
    * 

    */


    drawSide(0, 1, img);

    /*

    * * * *
    *     
    *     

    */

   drawSide(1, 1, img);

    /*

    * * * *
    *     *
    *     *

    */

   drawSide(1, 0, img);

   /*

    * * * *
    *     *
    * * * *

    */

}
