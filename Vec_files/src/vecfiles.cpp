#include "vecfiles.h"
#include <iostream>

string is_comment(string lines)
{
    int i = 0, flag = 1;
    while(flag!=0)
    {
        i++;
        if(lines[i-1] == '#' && lines[i] == '#')
        {
            flag = 0;
        }

    }
    // lines=lines.erase(i-1,(lines.length()-1-i-1));
    cout << i << endl; 
    return lines;
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
        lines=is_comment(lines);    
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
    vecfile.close();
}

//[RECTANGLES : 0, 0, 399, 449, vert pomme, 1, 70 ;]