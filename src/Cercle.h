#include "Point.h"
#include <math.h>

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
