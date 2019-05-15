#ifndef POINT_H
#define POINT_H
#include "CPixel.h"
#include "CImage.h"
#include <vector>

enum Color { red, green, blue, cyan, magenta, olive, crimson, lightcoral, vertpomme, azur, gris, orange, noir, indigo, canard, bordeaux, jaune, sangdeboeuf,aiguemarine,violet};
const vector<string> Col_str={"red", "green", "blue", "cyan", "magenta", "olive", "crimson", "lightcoral","vert pomme","azur","gris", "orange", "noir", "indigo", "canard", "bordeaux", "jaune", "sang de boeuf","aigue-marine","violet"};

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
    CPixel* drawTransparency(CPixel *oldp);
    void drawPoint(CImage *img, CImage *plan);
    double getPosX();
    double getPosY();
    void setPlan(int p);
    int getPlan();
};
#endif