#ifndef POINT_H
#define POINT_H
#include "CPixel.h"
#include "CImage.h"

enum Color { red, green, blue, cyan, magenta, olive, crimson, lightcoral };
const vector<string> Col_str={"red", "green", "blue", "cyan", "magenta", "olive", "crimson", "lightcoral"};

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
#endif