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

    cout << "(II) P_Bitmap execution start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "(II) + Number of arguments = " << argc << endl;

    cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();

    string filename2 = "Sortie.bmp";

    int scale = atoi(argv[1]);
    string input_file = argv[2];

    cout << "(II) CImage pointer extraction" << endl;
    int *tab = max_lengths(input_file, scale);
    CImage *img = new CImage(tab[1], tab[0]);
    CImage *plan = new CImage(tab[1], tab[0]);

    cout << "(II) Opening file ..." << endl;
    openfile(input_file, img, plan, scale);
    cout << "(II) File drawn" << endl;

    image->setImage(img);
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);
    return 1;
}
