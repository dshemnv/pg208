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
    Rectangle();
    ~Rectangle();
    void setPosition(int x, int y);
    void setLengths(int length, int width);
    void setColor(Color color, int transparence);
    void drawSide(int coordX, int coordY, CImage *img, CImage *plan);
    void drawRectangle(CImage *img, CImage *plan);
    void drawRectangles(CImage *img, CImage *plan);
    void setPlan(int p);
    int getPlan();
    int getLength();
    int getWidth();
    int getPosX();
    int getPosY();
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
    Carre();
    ~Carre();
    void setLengths(int width);
};


#endif