#include "vecfiles.h"



Color convert_color(string color)
{
	return red;
}


bool is_comment(string lines)
{
	if(lines[0] == '#' && lines[1] == '#')
		{
			return true;
		} 
	return false;
}

Cercle* convert_circle(string str_cir)
{
	int x,y,r,transparence;
	char str[20];
	Cercle *c = new Cercle();
	sscanf(str_cir.c_str(),"[CERCLE : %d, %d, %d, %[^,], %d;]",&x,&y,&r,str,&transparence);
	c->setPosition(x,y);
	c->setRadius(r);
	//c->setColor(color);
	return c;
}

void openfile(string filename)
{
	ifstream vecfile;
	string lines;
	vecfile.open(filename.c_str(), std::ifstream::in);   
	if(!vecfile.is_open())
	{
		cout << "Not open" << endl;
	}
	while(!vecfile.eof())
	{
		getline(vecfile,lines);
		if(!is_comment(lines))
		{            
		if((lines.find("CERCLE")!=lines.npos))
		{
			  cout<<lines<<endl;
			  convert_circle(lines);          
		}
		else if((lines.find("LIGNE")!=lines.npos))
		{
			
		}
		else if((lines.find("RECTANGLE")!=lines.npos))
		{
			
		}
		else if((lines.find("POINT")!=lines.npos))
		{
			
		}
		else if((lines.find("CARRE")!=lines.npos))
		{
			
		}
		}        
	}
	vecfile.close();
}

//[RECTANGLES : 0, 0, 399, 449, vert pomme, 1, 70 ;]