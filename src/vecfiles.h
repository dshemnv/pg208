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
#include "Figure.h"


void openfile(string filename, CImage *img);
Point* convert_point(string str_pt); // i = 0, pas plein, i = 1 plein;
Ligne* convert_line(string str_lin);
Carre* convert_square(string str_sqr, int i);
Rectangle* convert_rectangle(string str_rec, int i);
Cercle* convert_circle(string str_cir, int i);
Color convert_color(string color);
bool is_comment(string lines);
int max_plan(int plan1, int plan2);
// void display_vector();
#endif