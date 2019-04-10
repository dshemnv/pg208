#include "CPixel.h"
#include "CImage.h"


enum Color { red, green, blue, cyan, magenta, olive, crimson, lightcoral };
class Point
{
private:
   int posX;
   int posY;
   CPixel *pixel;
public:
    Point(/* args */);
    ~Point();
    void setColor(Color);
    void setPosition(int x, int y);
    void drawPoint(CImage *img);
    int getPosX();
    int getPosY();
};


