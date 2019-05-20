#include "Point.h"
#include <math.h>


#ifndef CERCLE_H_
#define CERCLE_H_

class Cercle
{
private:
    Point *trace;
    Point *centre;
    int rayon;
public:
    Cercle();
    ~Cercle();
    void setPosition(int x, int y);
    void setRadius(int r);
    void setColor(Color color, int transparence);
    void drawCircle(CImage *img, CImage *plan);
    void drawCircles(CImage *img, CImage *plan);
    void setPlan(int plan);

    int getPlan();
    int getPosY();
    int getPosX();
    int getRadius();
};

#endif