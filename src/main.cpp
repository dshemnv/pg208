#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "CBitmap.h"
#include "Ligne.h"
#include "Cercle.h"

int main(int argc, char *argv[])
{

    cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "(II) + Number of arguments = " << argc << endl;

    cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    Ligne *line = new Ligne();
    Point *pt = new Point();
    Cercle *circ = new Cercle();

    string filename2 = "Sortie.bmp";

    cout << "(II) CImage pointer extraction" << endl;
    CImage *img = new CImage(200, 200);

    line->setColorLine(olive);
    line->setCoordinates(30,10,150,60);
    line->drawLigne(img);
    pt->setPosition(30,40);
    pt->setColor(red);
    pt->drawPoint(img);

    // circ->setPosition(30,20);
    // circ->setColor(red);
    // circ->setRadius(10);

    
    image->setImage(img);
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);

    return 1;
}
