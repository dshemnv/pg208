#include "Point.h"

#ifndef LIGNE_H_
#define LIGNE_H_

class Ligne
{
private:
    Point *origine;
    Point *fin;
    Point *trace;
public:
    Ligne();
    ~Ligne();
    void drawLigne(CImage *img);
    void setColorLine(Color color);
    void setCoordinates(double x1, double y1, double x2, double y2);
    double getPosX();
    double getPosY();

};

#endif