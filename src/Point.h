#ifndef POINT_H
#define POINT_H
#include "CPixel.h"
#include "CImage.h"
#include <vector>

enum Color { red, green, blue, cyan, magenta, olive, crimson, lightcoral};
const vector<string> Col_str={"red", "green", "blue", "cyan", "magenta", "olive", "crimson", "lightcoral"};

class Point
{
private:
   int posX;
   int posY;
   CPixel *pixel;
   int transparence;
   int plan;
public:
    Point(int X, int Y);
    Point();
    ~Point();
    void setColor(Color color, int transparence);
    void setPosition(double x, double y);
    void setTransparency(int transp);
    void setPlan(int plan);
    CPixel* drawTransparency(CPixel *oldp);
    void drawPoint(CImage *img);
    double getPosX();
    double getPosY();
    int getPlan();
};
#endif