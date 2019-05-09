#include "vecfiles.h"
#include <iostream>

bool is_comment(string lines)
{
    if(lines[0] == '#' && lines[1] == '#')
        {
            return true;
        } 
    return false;
}

// void convert_ligne(string str_lin)
// {
//     int a, b, c, d;
//     sscanf(str_lin.c_str(),"",)
// }

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
            cout<<lines<<endl;
        // if((lines.find("CERCLE")!=lines.npos))
        // {
        //       convert_line(lines);          
        // }
        // else if((lines.find("LIGNE")!=lines.npos))
        // {
            
        // }
        // else if((lines.find("RECTANGLE")!=lines.npos))
        // {
            
        // }
        // else if((lines.find("POINT")!=lines.npos))
        // {
            
        // }
        // else if((lines.find("CARRE")!=lines.npos))
        // {
            
        // }
        }        
    }
    vecfile.close();
}

//[RECTANGLES : 0, 0, 399, 449, vert pomme, 1, 70 ;]