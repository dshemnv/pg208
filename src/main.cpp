#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "CBitmap.h"
#include "Point.h"

int main(int argc, char *argv[])
{

    cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "(II) + Number of arguments = " << argc << endl;

    cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    Point *point = new Point();
    string filename2 = "Sortie.bmp";

    cout << "(II) CImage pointer extraction" << endl;
    CImage *img = new CImage(200, 200);
    
    point->setColor(olive);
    point->setPosition(20, 30);
    point->drawPoint(img);

    image->setImage(img);
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);

    return 1;
}
