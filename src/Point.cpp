#include "Point.h"

Point::Point(int X, int Y)
{
    pixel = new CPixel();
    setPosition(X, Y);
}

Point::Point()
{
    pixel = new CPixel();
}

Point::~Point()
{
}

void Point::setColor(Color color, int transparence)
{
    color = this->color;
    switch (color)
    {
    case blue:
        pixel->RGB(0, 0, 255);
        break;

    case red:
        pixel->RGB(255, 0, 0);
        break;

    case green:
        pixel->RGB(0, 255, 0);
        break;
    case cyan:
        pixel->RGB(0, 255, 255);
        break;

    case olive:
        pixel->RGB(128, 128, 0);
        break;

    case crimson:
        pixel->RGB(153,0,0);
        break;
        
    case lightcoral:
        pixel->RGB(240,128,128);
        break;
    
    case vertpomme:
        pixel->RGB(141,182,0);
        break;

    case azur:
        pixel->RGB(0,127,255);
        break;
        
    case gris:
        pixel->RGB(178,190,181);
        break;
    
    case orange:
        pixel->RGB(247,127,0);
        break;

    case noir:
        pixel->RGB(0,0,0);
        break;
    
    case indigo:
        pixel->RGB(75,0,130);
        break;
    
    case canard:
        pixel->RGB(0,128,128);
        break;

    case bordeaux:
        pixel->RGB(172,30,68);
        break;
    
    case jaune:
        pixel->RGB(255,225,53);
        break;
    
    case sangdeboeuf:
        pixel->RGB(128, 0, 32);
        break;
    
    case aiguemarine:
        pixel->RGB(121, 248, 248);
        break;
    
    case violet:
        pixel->RGB(136,6,206);
        break;

    default:
        break;
    }
//"indigo", "canard", "bordeaux", "jaune", "sang de boeuf","aigue-marine","violet"};
    setTransparency(transparence);   
    
}

void Point::setPosition(double x, double y)
{
    posX = (int)x;
    posY = (int)y;
}

void Point::setTransparency(int transp)
{
    transparence = transp;
}

CPixel* Point::drawTransparency(CPixel *oldp)
{
    CPixel *tr_pix = new CPixel();
    int red = ((100 - transparence) * oldp->Red() + transparence * pixel->Red()) / 100;
    int green = ((100 - transparence) * oldp->Green() + transparence * pixel->Green()) / 100;
    int blue = ((100 - transparence) * oldp->Blue() + transparence * pixel->Blue()) / 100;
    tr_pix->RGB(red, green, blue);
    return tr_pix;
}

void Point::drawPoint(CImage *img, CImage *plan)
{
    CPixel *pl = plan->getPixel(posX,posY);
    if( this->getPlan() >= pl->Red() )
    {
    pl->Red(pl->Red()+1);
    CPixel *pi = img->getPixel(posX, posY);
    pi->RGB(drawTransparency(pi)->Red(), drawTransparency(pi)->Green(), drawTransparency(pi)->Blue());
    }
}

double Point::getPosX()
{
    return (double)posX;
}

double Point::getPosY()
{
    return (double)posY;
}

void Point::setPlan(int p)
{
    plan = p;
}

int Point::getPlan()
{
    return plan;
}