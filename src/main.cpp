#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


#include "vecfiles.h"
#include "CBitmap.h"



int main(int argc, char *argv[])
{

    // cout << "(II) P_Bitmap execution start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    // cout << "(II) + Number of arguments = " << argc << endl;

    // cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    // Ligne *line = new Ligne();
    // Point *pt = new Point();
    // Cercle *circ = new Cercle();
    // Cercle *circ2 = new Cercle();
    // Rectangle *rect = new Rectangle();

    string filename2 = "Sortie.bmp";

    int scale = atoi(argv[1]);
    string input_file = argv[2];

    cout << "(II) CImage pointer extraction" << endl;
    int* tab = max_lengths(input_file, scale);
    tab[0] +=2;
    tab[1] +=2;
    CImage *img = new CImage(tab[1], tab[0]);
    CImage *plan = new CImage(tab[1], tab[0]);

    // // line->setColor(olive, 30);
    // // line->setCoordinates(100,10,20,60);
    // // line->drawLigne(img);
    // // pt->setPosition(30,40);
    // // pt->setColor(red, 10);
    // // pt->drawPoint(img);

    // circ->setPosition(150,30);
    // circ->setColor(blue, 100);
    // circ->setRadius(20);
    // // circ->drawCircle(img);

    // // circ2->setPosition(150,30);
    // // circ2->setColor(red, 70);
    // // circ2->setRadius(18);
    // // circ2->drawCircles(img);


    // // rect->setPosition(20,50);
    // // rect->setColor(red, 70);
    // // rect->setLengths(40,20);
    // // rect->drawRectangles(img);

    openfile(input_file, img, plan,scale);

    
    image->setImage(img);
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);    
    return 1;
}
