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
Cercle *convert_circle(string str_cir, int i)
{
	int x, y, r, transparence;
	char str[20];
	Cercle *c = new Cercle();
	if(i == 0)
	{
		sscanf(str_cir.c_str(), "[CERCLE : %d, %d, %d, %[^,], %d;]", &x, &y, &r, str, &transparence);
	}
	else
	{
		sscanf(str_cir.c_str(), "[CERCLES : %d, %d, %d, %[^,], %d;]", &x, &y, &r, str, &transparence);
	}
	c->setPosition(x, y);
	c->setRadius(r);
	c->setColor(convert_color((string)str),transparence);
	return c;
}

//[RECTANGLE : X, Y, LONGUEUR, HAUTEUR, COULEUR, TRANSPARENCE;]
Rectangle* convert_rectangle(string str_rec,int i)
{
	int x, y, L, h, transparence;
	char col[20];
	Rectangle *r = new Rectangle();
	if(i == 0)
	{
		sscanf(str_rec.c_str(), "[RECTANGLE : %d, %d, %d, %d, %[^,], %d;]", &x, &y, &L, &h, col, &transparence);
	}
	else
	{
		sscanf(str_rec.c_str(), "[RECTANGLES : %d, %d, %d, %d, %[^,], %d;]", &x, &y, &L, &h, col, &transparence);
	}	
	r->setPosition(x, y);
	r->setLengths(L,h);
	r->setColor(convert_color((string)col), transparence);
	cout<<x<<" "<<y<<" "<<" "<<col<<" "<<L<<" "<<h<<" "<<transparence<<endl;
	return r;
}

//[CARRE : X, Y, LONGUEUR, HAUTEUR, COULEUR, TRANSPARENCE;]
Carre* convert_square(string str_sqr, int i)
{
	int x, y, c, transparence;
	char col[20];
	Carre *ca = new Carre();
	if(i == 0)
	{
		sscanf(str_sqr.c_str(), "[CARRE : %d, %d, %d, %[^,], %d;]", &x, &y, &c, col, &transparence);
	}
	else
	{
		sscanf(str_sqr.c_str(), "[CARRES : %d, %d, %d, %[^,], %d;]", &x, &y, &c, col, &transparence);
	}	
	ca->setPosition(x, y);
	ca->setLengths(c);
	ca->setColor(convert_color((string)col), transparence);
	return ca;
}

//[LIGNE : X1, Y1, X2, Y2, COULEUR, TRANSPARENCE;]
Ligne* convert_line(string str_lin)
{
	int x1, y1, x2, y2, transparence;
	char col[20];
	Ligne *lin = new Ligne();
	sscanf(str_lin.c_str(), "[LIGNE : %d, %d, %d, %d, %[^,], %d;]", &x1, &y1, &x2, &y2, col, &transparence);
	lin->setCoordinates(x1, y1, x2, y2);
	lin->setColor(convert_color((string)col), transparence);
	return lin;
}
//[POINT : X, Y, COULEUR, TRANSPARENCE;]
Point* convert_point(string str_pt)
{
	int x, y, transparence;
	char col[20];
	Point *pt = new Point();
	sscanf(str_pt.c_str(), "[POINT : %d, %d, %[^,], %d;]", &x, &y, col, &transparence);
	pt->setPosition(x,y);
	pt->setColor(convert_color((string)col), transparence);
	return pt;
}

void openfile(string filename, CImage *img)
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
					c->drawCircles(img);
				}
				else
				{
					c = convert_circle(lines,0);
					c->drawCircle(img);
				}
			}
			else if ((lines.find("LIGNE") != lines.npos))
			{
				lin = convert_line(lines);
				lin->drawLigne(img);
			}
			else if ((lines.find("RECTANGLE") != lines.npos))
			{
				if ((lines.find("RECTANGLES") != lines.npos))
				{
					rec = convert_rectangle(lines,1);
					rec->drawRectangles(img);
				}
				else
				{
					rec = convert_rectangle(lines,0);
					rec->drawRectangle(img);
				}
			}
			else if ((lines.find("POINT") != lines.npos))
			{
				pt = convert_point(lines);
				pt->drawPoint(img);
			}
			else if ((lines.find("CARRE") != lines.npos))
			{
				if ((lines.find("CARRES") != lines.npos))
				{
					ca = convert_square(lines,1);
					ca->drawRectangles(img);
				}
				else
				{
					ca = convert_square(lines,0);
					ca->drawRectangle(img);
				}
			}
		}
	}
	vecfile.close();
}

