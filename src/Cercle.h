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
    void setColor(Color color);
    void drawCircle(CImage *img);
};
#endif