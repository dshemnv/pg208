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

void Rectangle::setColor(Color color, int transparence)
{
    ligne->setColor(color, transparence);
}

void Rectangle::drawSide(int coordX, int coordY, CImage *img)
{
    double Xo = ligne->getPosX();
    double Yo = ligne->getPosY();

    int i = coordX + coordY;

    switch (i)
    {
    case 0:
        ligne->setCoordinates(Xo, Yo , Xo, Yo + (double)largeur - 1);
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
        ligne->setCoordinates(Xo + 1 , Yo, Xo + 1 , Yo - (double)largeur + 1);
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

void Rectangle::drawRectangles(CImage *img)
{
    // while (longeur && largeur != 0)
    // {
    //     longeur--;
    //     largeur--;
    //     drawRectangle(img);
    // }
    drawRectangle(img);
    for (int i = 1; i < largeur; i++)
    {
        ligne->setCoordinates((double)posX + 1, (double)posY + i, (double)posX + longeur - 1, (double)posY + i);
        ligne->drawLigne(img);
    }
    
}