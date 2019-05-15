#include "vecfiles.h"

Color convert_color(string color)
{
	unsigned int i;
	for (i = 0; i < Col_str.size(); i++)
	{
		if (color.compare(Col_str[i]) == 0)
		{
			return (Color)i;
		}
	}
	cout << "Couleur non définie" << endl
		 << "Par défaut rouge" << endl;
	return red;
}

bool is_comment(string lines)
{
	if (lines[0] == '#' && lines[1] == '#')
	{
		return true;
	}
	return false;
}

//[CERCLE : X, Y, RAYON, COULEUR, TRANSPARENCE;]
Cercle* convert_circle(string str_cir, int i, int scale)
{
	int x, y, r, transparence, plan;
	char str[20];
	Cercle *c = new Cercle();
	if(i == 0)
	{
		sscanf(str_cir.c_str(), "[CERCLE : %d, %d, %d, %[^,], %d, %d;]", &x, &y, &r, str, &transparence, &plan);
	}
	else
	{
		sscanf(str_cir.c_str(), "[CERCLES : %d, %d, %d, %[^,], %d, %d;]", &x, &y, &r, str, &transparence, &plan);
	}
	c->setPosition(scale*x, scale*y);
	c->setRadius(scale*r);
	c->setColor(convert_color((string)str),transparence);
	c->setPlan(plan);
	return c;
}

//[RECTANGLE : X, Y, LONGUEUR, HAUTEUR, COULEUR, TRANSPARENCE;]
Rectangle* convert_rectangle(string str_rec, int i, int scale)
{
	int x, y, L, h, transparence, plan;
	char col[20];
	Rectangle *r = new Rectangle();
	if(i == 0)
	{
		sscanf(str_rec.c_str(), "[RECTANGLE : %d, %d, %d, %d, %[^,], %d, %d;]", &x, &y, &L, &h, col, &transparence, &plan);
	}
	else
	{
		sscanf(str_rec.c_str(), "[RECTANGLES : %d, %d, %d, %d, %[^,], %d, %d;]", &x, &y, &L, &h, col, &transparence, &plan);
	}	
	r->setPosition(scale*x, scale*y);
	r->setLengths(scale*L,scale*h);
	r->setColor(convert_color((string)col), transparence);
	r->setPlan(plan);
	return r;
}

//[CARRE : X, Y, LONGUEUR, HAUTEUR, COULEUR, TRANSPARENCE;]
Carre* convert_square(string str_sqr, int i, int scale)
{
	int x, y, c, transparence, plan;
	char col[20];
	Carre *ca = new Carre();
	if(i == 0)
	{
		sscanf(str_sqr.c_str(), "[CARRE : %d, %d, %d, %[^,], %d, %d;]", &x, &y, &c, col, &transparence, &plan);
	}
	else
	{
		sscanf(str_sqr.c_str(), "[CARRES : %d, %d, %d, %[^,], %d, %d;]", &x, &y, &c, col, &transparence, &plan);
	}	
	ca->setPosition(scale*x, scale*y);
	ca->setLengths(scale*c);
	ca->setColor(convert_color((string)col), transparence);
	ca->setPlan(plan);
	return ca;
}

//[LIGNE : X1, Y1, X2, Y2, COULEUR, TRANSPARENCE;]
Ligne* convert_line(string str_lin, int scale)
{
	int x1, y1, x2, y2, transparence, plan;
	char col[20];
	Ligne *lin = new Ligne();
	sscanf(str_lin.c_str(), "[LIGNE : %d, %d, %d, %d, %[^,], %d, %d;]", &x1, &y1, &x2, &y2, col, &transparence, &plan);
	lin->setCoordinates(scale*x1, scale*y1, scale*x2, scale*y2);
	lin->setColor(convert_color((string)col), transparence);
	lin->setPlan(plan);
	return lin;
}
//[POINT : X, Y, COULEUR, TRANSPARENCE;]
Point* convert_point(string str_pt, int scale)
{
	int x, y, transparence, plan;
	char col[20];
	Point *pt = new Point();
	sscanf(str_pt.c_str(), "[POINT : %d, %d, %[^,], %d, %d;]", &x, &y, col, &transparence, &plan);
	pt->setPosition(scale*x,scale*y);
	pt->setColor(convert_color((string)col), transparence);
	pt->setPlan(plan);
	return pt;
}

void openfile(string filename, CImage *img, CImage *plan)
{
	Cercle *c = new Cercle();
	Carre *ca = new Carre();
	Rectangle *rec = new Rectangle();
	Ligne *lin = new Ligne();
	Point *pt = new Point();
	ifstream vecfile;
	string lines;
	vecfile.open(filename.c_str(), std::ifstream::in);
	if (!vecfile.is_open())
	{
		cout << "Not open" << endl;
	}
	while (!vecfile.eof())
	{
		getline(vecfile, lines);
		if (!is_comment(lines))
		{
			if ((lines.find("CERCLE") != lines.npos))
			{				
				if ((lines.find("CERCLES") != lines.npos))
				{					
					c = convert_circle(lines,1);				
				}
				else
				{
					c = convert_circle(lines,0);
				}
			}
			else if ((lines.find("LIGNE") != lines.npos))
			{
				lin = convert_line(lines);
				
			}
			else if ((lines.find("RECTANGLE") != lines.npos))
			{
				if ((lines.find("RECTANGLES") != lines.npos))
				{
					rec = convert_rectangle(lines,1);
				}
				else
				{
					rec = convert_rectangle(lines,0);

				}
			}
			else if ((lines.find("POINT") != lines.npos))
			{
				pt = convert_point(lines);
			}
			else if ((lines.find("CARRE") != lines.npos))
			{
				if ((lines.find("CARRES") != lines.npos))
				{
					ca = convert_square(lines,1);
				}
				else
				{
					ca = convert_square(lines,0);
				}
			}
		}
	}
	vecfile.close();
}
