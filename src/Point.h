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
    Point(int X, int Y);
    Point();
    ~Point();
    void setColor(Color color);
    void setPosition(double x, double y);
    void drawPoint(CImage *img);
    double getPosX();
    double getPosY();
};
