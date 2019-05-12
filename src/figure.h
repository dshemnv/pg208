#ifndef FIGURE_H_
#define FIGURE_H_

enum Forme_t{Pt,Lin,Car,Rec,Cer};

class Forme
{
private:
    int plan;
    Forme_t type;
public:
    Forme();
    Forme(Forme_t type, int plan);
    ~Forme();

    void setPlan(int plan);
    void setType(Forme_t type);
    int getPlan();
    Forme_t getType();
};


#endif