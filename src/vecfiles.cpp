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

Cercle *convert_circle(string str_cir)
{
	int x, y, r, transparence;
	char str[20];
	Cercle *c = new Cercle();
	sscanf(str_cir.c_str(), "[CERCLE : %d, %d, %d, %[^,], %d;]", &x, &y, &r, str, &transparence);
	c->setPosition(x, y);
	c->setRadius(r);
	c->setColor(convert_color((string)str),transparence);
	return c;
}

void openfile(string filename, CImage *img)
{
	Cercle *c = new Cercle();
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
				if ((lines.find("CERCLE") != lines.npos))
					c = convert_circle(lines);
				c->drawCircle(img);
			}
			else if ((lines.find("LIGNE") != lines.npos))
			{
			}
			else if ((lines.find("RECTANGLE") != lines.npos))
			{
			}
			else if ((lines.find("POINT") != lines.npos))
			{
			}
			else if ((lines.find("CARRE") != lines.npos))
			{
			}
		}
	}
	vecfile.close();
}

//[RECTANGLES : 0, 0, 399, 449, vert pomme, 1, 70 ;]