#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "CBitmap.h"
#include "Ligne.h"
#include "Cercle.h"
#include "Rectangle.h"

int main(int argc, char *argv[])
{

    cout << "(II) P_Bitmap execution start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "(II) + Number of arguments = " << argc << endl;

    cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    Ligne *line = new Ligne();
    Point *pt = new Point();
    Cercle *circ = new Cercle();
    Cercle *circ2 = new Cercle();
    Rectangle *rect = new Rectangle();

    string filename2 = "Sortie.bmp";

    cout << "(II) CImage pointer extraction" << endl;
    CImage *img = new CImage(200, 200);

    line->setColorLine(olive);
    line->setCoordinates(100,10,20,60);
    line->drawLigne(img);
    pt->setPosition(30,40);
    pt->setColor(red);
    pt->drawPoint(img);

    circ->setPosition(150,30);
    circ->setColor(blue);
    circ->setRadius(20);
    circ->drawCircle(img);

    circ2->setPosition(150,30);
    circ2->setColor(red);
    circ2->setRadius(18);
    circ2->drawCircles(img);


    rect->setPosition(20,50);
    rect->setColor(red);
    rect->setLengths(40,20);
    rect->drawRectangles(img);

    
    image->setImage(img);
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);

    return 1;
}
