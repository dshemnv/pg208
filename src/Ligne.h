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
    void setColor(Color color, int transparence);
    void setCoordinates(double x1, double y1, double x2, double y2);
    double getPosX();
    double getPosY();
    void setPlan(int p);
    int getPlan();
};

#endif