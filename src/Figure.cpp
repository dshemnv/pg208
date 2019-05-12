#include "figure.h"

Forme::Forme(/* args */)
{
}

Forme::~Forme()
{
}

Forme::Forme(Forme_t type, int plan)
{
    type = type;
    plan = plan;
}

void Forme::setPlan(int plan)
{
    plan = plan;
}

void Forme::setType(Forme_t type)
{
    type = type;
}

Forme_t Forme::getType()
{
    return type;
}

int Forme::getPlan()
{
    return plan;
}