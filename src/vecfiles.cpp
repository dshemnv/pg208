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
Cercle *convert_circle(string str_cir, int i, int scale)
{
	int x, y, r, transparence, plan_i;
	char str[20];
	char plan[5];
	Cercle *c = new Cercle();
	if (i == 0)
	{
		sscanf(str_cir.c_str(), "[CERCLE : %d, %d, %d, %[^,],%[^,], %d ;]", &x, &y, &r, str, plan, &transparence);
	}
	else
	{
		sscanf(str_cir.c_str(), "[CERCLES : %d, %d, %d, %[^,],%[^,], %d ;]", &x, &y, &r, str, plan, &transparence);
	}
	c->setPosition(scale * x, scale * y);
	c->setRadius(scale * r);
	c->setColor(convert_color((string)str), transparence);
	plan_i = atoi(plan);
	c->setPlan(plan_i);
	return c;
}

//[RECTANGLE : X, Y, LONGUEUR, HAUTEUR, COULEUR, TRANSPARENCE;]
Rectangle *convert_rectangle(string str_rec, int i, int scale)
{
	int x, y, L, h, transparence, plan_i;
	char col[20];
	char plan[5];
	Rectangle *r = new Rectangle();
	if (i == 0)
	{
		sscanf(str_rec.c_str(), "[RECTANGLE : %d, %d, %d, %d, %[^,],%[^,], %d ;]", &x, &y, &L, &h, col, plan, &transparence);
	}
	else
	{
		sscanf(str_rec.c_str(), "[RECTANGLES : %d, %d, %d, %d, %[^,],%[^,], %d ;]", &x, &y, &L, &h, col, plan, &transparence);
	}
	r->setPosition(scale * x, scale * y);
	r->setLengths(scale * L, scale * h);
	r->setColor(convert_color((string)col), transparence);
	plan_i = atoi(plan);
	r->setPlan(plan_i);
	return r;
}

//[CARRE : X, Y, LONGUEUR, HAUTEUR, COULEUR, TRANSPARENCE;]
Carre *convert_square(string str_sqr, int i, int scale)
{
	int x, y, c, transparence, plan_i;
	char col[20];
	char plan[5];
	Carre *ca = new Carre();
	if (i == 0)
	{
		sscanf(str_sqr.c_str(), "[CARRE : %d, %d, %d, %[^,],%[^,], %d ;]", &x, &y, &c, col, plan, &transparence);
	}
	else
	{
		sscanf(str_sqr.c_str(), "[CARRES : %d, %d, %d, %[^,],%[^,], %d ;]", &x, &y, &c, col, plan, &transparence);
	}
	ca->setPosition(scale * x, scale * y);
	ca->setLengths(scale * c);
	ca->setColor(convert_color((string)col), transparence);
	plan_i = atoi(plan);
	ca->setPlan(plan_i);
	return ca;
}

//[LIGNE : X1, Y1, X2, Y2, COULEUR, TRANSPARENCE;]
Ligne *convert_line(string str_lin, int scale)
{
	int x1, y1, x2, y2, transparence, plan_i;
	char plan[5];
	char col[20];
	Ligne *lin = new Ligne();
	sscanf(str_lin.c_str(), "[LIGNE : %d, %d, %d, %d, %[^,],%[^,], %d ;]", &x1, &y1, &x2, &y2, col, plan, &transparence);
	lin->setCoordinates(scale * x1, scale * y1, scale * x2, scale * y2);
	lin->setColor(convert_color((string)col), transparence);
	plan_i = atoi(plan);
	lin->setPlan(plan_i);
	return lin;
}
//[POINT : X, Y, COULEUR, TRANSPARENCE;]
Point *convert_point(string str_pt, int scale)
{
	int x, y, transparence, plan_i;
	char col[20];
	char plan[5];
	Point *pt = new Point();
	sscanf(str_pt.c_str(), "[POINT : %d, %d, %[^,],%[^,], %d ;]", &x, &y, col, plan, &transparence);
	pt->setPosition(scale * x, scale * y);
	pt->setColor(convert_color((string)col), transparence);
	plan_i = atoi(plan);
	pt->setPlan(plan_i);
	return pt;
}

int *max_lengths(string filename, int scale)
{
	Cercle *c = new Cercle();
	Carre *ca = new Carre();
	Rectangle *rec = new Rectangle();
	Ligne *lin = new Ligne();
	Point *pt = new Point();
	ifstream vecfile;
	string lines;
	int *lengths = new int[2];

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
					c = convert_circle(lines, 1, scale);
					lengths[1] = (c->getPosY() + c->getRadius() > lengths[1]) ? c->getPosY() + c->getRadius() : lengths[1];
					lengths[0] = (c->getPosX() + c->getRadius() > lengths[0]) ? c->getPosX() + c->getRadius() : lengths[0];
				}
				else
				{
					c = convert_circle(lines, 0, scale);
					lengths[1] = (c->getPosY() + c->getRadius() > lengths[1]) ? c->getPosY() + c->getRadius() : lengths[1];
					lengths[0] = (c->getPosX() + c->getRadius() > lengths[0]) ? c->getPosX() + c->getRadius() : lengths[0];
				}
			}
			else if ((lines.find("LIGNE") != lines.npos))
			{
				lin = convert_line(lines, scale);
				if ((int)lin->getPosY() > lin->getPosYo())
				{
					lengths[1] = ((int)lin->getPosY() - lin->getPosYo() > lengths[1]) ? (int)lin->getPosY() : lengths[1];
				}
				if ((int)lin->getPosX() > lin->getPosXo())
				{
					lengths[0] = ((int)lin->getPosX() - lin->getPosXo() > lengths[0]) ? (int)lin->getPosY() : lengths[0];
				}
			}
			else if ((lines.find("RECTANGLE") != lines.npos))
			{
				if ((lines.find("RECTANGLES") != lines.npos))
				{
					rec = convert_rectangle(lines, 1, scale);
					lengths[1] = (rec->getPosY() + rec->getWidth() > lengths[1]) ? rec->getPosY() + rec->getWidth() : lengths[1];
					lengths[0] = (c->getPosX() + rec->getLength() > lengths[0]) ? rec->getPosX() + rec->getLength() : lengths[0];
				}
				else
				{
					rec = convert_rectangle(lines, 0, scale);
					lengths[1] = (rec->getPosY() + rec->getWidth() > lengths[1]) ? rec->getPosY() + rec->getWidth() : lengths[1];
					lengths[0] = (c->getPosX() + rec->getLength() > lengths[0]) ? rec->getPosX() + rec->getLength() : lengths[0];
				}
			}
			else if ((lines.find("POINT") != lines.npos))
			{
				pt = convert_point(lines, scale);
				lengths[1] = (pt->getPosY() > lengths[1]) ? pt->getPosY() : lengths[1];
				lengths[0] = (pt->getPosX() > lengths[0]) ? pt->getPosX() : lengths[0];
			}
			else if ((lines.find("CARRE") != lines.npos))
			{
				if ((lines.find("CARRES") != lines.npos))
				{
					ca = convert_square(lines, 1, scale);
					lengths[1] = (rec->getPosY() + rec->getWidth() > lengths[1]) ? rec->getPosY() + rec->getWidth() : lengths[1];
					lengths[0] = (c->getPosX() + rec->getLength() > lengths[0]) ? rec->getPosX() + rec->getLength() : lengths[0];
				}
				else
				{
					ca = convert_square(lines, 0, scale);
					lengths[1] = (rec->getPosY() + rec->getWidth() > lengths[1]) ? rec->getPosY() + rec->getWidth() : lengths[1];
					lengths[0] = (c->getPosX() + rec->getLength() > lengths[0]) ? rec->getPosX() + rec->getLength() : lengths[0];
				}
			}
		}
	}
	vecfile.close();
	lengths[0]++;
	lengths[1]++;
	return lengths;
}

void openfile(string filename, CImage *img, CImage *plan, int scale)
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
					c = convert_circle(lines, 1, scale);
					c->drawCircles(img, plan);
				}
				else
				{
					c = convert_circle(lines, 0, scale);
					c->drawCircle(img, plan);
				}
			}
			else if ((lines.find("LIGNE") != lines.npos))
			{
				lin = convert_line(lines, scale);
				lin->drawLigne(img, plan);
			}
			else if ((lines.find("RECTANGLE") != lines.npos))
			{
				if ((lines.find("RECTANGLES") != lines.npos))
				{
					rec = convert_rectangle(lines, 1, scale);
					rec->drawRectangles(img, plan);
				}
				else
				{
					rec = convert_rectangle(lines, 0, scale);
					rec->drawRectangle(img, plan);
				}
			}
			else if ((lines.find("POINT") != lines.npos))
			{
				pt = convert_point(lines, scale);
				pt->drawPoint(img, plan);
			}
			else if ((lines.find("CARRE") != lines.npos))
			{
				if ((lines.find("CARRES") != lines.npos))
				{
					ca = convert_square(lines, 1, scale);
					ca->drawRectangles(img, plan);
				}
				else
				{
					ca = convert_square(lines, 0, scale);
					ca->drawRectangle(img, plan);
				}
			}
		}
	}
	vecfile.close();
}
