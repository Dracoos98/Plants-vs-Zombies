#pragma once
#include "Base.h"
#include <iostream>
using namespace std;
class Plantas :
    public Base
{
public:
    Plantas();
    ~Plantas();
    Plantas(int px, int py);
    void Dibujar_desImagen(Graphics^ g, Bitmap^ bmp);
};

