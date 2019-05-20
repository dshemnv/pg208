#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;

#ifndef VECFILES_H_
#define VECFILES_H_

#include "Cercle.h"
#include "Ligne.h"
#include "Point.h"
#include "Rectangle.h"


void openfile(string filename, CImage *img, CImage* plan, int scale);
Point* convert_point(string str_pt, int scale); // i = 0, pas plein, i = 1 plein;
Ligne* convert_line(string str_lin, int scale);
Carre* convert_square(string str_sqr, int i, int scale);
Rectangle* convert_rectangle(string str_rec, int i, int scale);
Cercle* convert_circle(string str_cir, int i, int scale);
Color convert_color(string color);
bool is_comment(string lines);
int* max_lengths(string filename, int scale);

#endif