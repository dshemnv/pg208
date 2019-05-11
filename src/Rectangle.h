#include "Ligne.h"

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle
{
private:
    Ligne *ligne;
    int longeur;
    int largeur;
    int posX;
    int posY;
public:
    Rectangle(/* args */);
    ~Rectangle();
    void setPosition(int x, int y);
    void setLengths(int length, int width);
    void setColor(Color color, int transparence);
    void drawSide(int coordX, int coordY, CImage *img);
    void drawRectangle(CImage *img);
    void drawRectangles(CImage *img);
    void setPlan(int plan);
    int getPlan();
};

class Carre : public Rectangle
{
private:
    Ligne *ligne;
    int largeur;
    int longeur;
    int posX;
    int posY;
public:
    Carre(/* args */);
    ~Carre();
    void setLengths(int width);
};


#endif