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



void openfile(string filename, CImage *img);
Point* convert_point(string str_pt);
Ligne* convert_line(string str_lin);
Carre* convert_square(string str_sqr);
Rectangle* convert_rectangle(string str_rec);
Cercle* convert_circle(string str_cir);
Color convert_color(string color);
bool is_comment(string lines);

#endif