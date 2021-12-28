#pragma once
#include "Base.h"
class Bala :
    public Base
{
public:
    Bala();
    ~Bala();
    Bala(int px, int py);
    void Mover(Graphics^ g);
    void Dibujar_desFigura(Graphics^ g);
};

