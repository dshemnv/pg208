#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;

#ifndef VECFILES_H_
#define VECFILES_H_


void openfile(string filename);
void convert_point(string str_rec);
void convert_line(string str_lin);
void convert_square(string str_sqr);
void convert_rectangle(string str_rec);
void convert_circle(string str_cir);
bool is_comment(string lines);





#endif