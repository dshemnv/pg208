#include "Point.h"

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
    void setColor(Color color);
    void setCoordinates(int x1, int y1, int x2, int y2);
};
