#include "Bala.h"
void Bala::Dibujar_desFigura(Graphics^ g)
{
    Pen^ p = gcnew Pen(Color::Red); //Color de contorno
    p->Width = 1; //Contorno de la figura(No tiene colisión)
    w = 10; //ancho
    h = 10; //largo
    SolidBrush^ br = gcnew SolidBrush(Color::Blue); //Color de relleno
    g->DrawEllipse(p, x, y, w, h);
    g->FillEllipse(br, x, y, w, h);
}

Bala::Bala()
{
}

Bala::~Bala()
{
}

Bala::Bala(int px, int py)
{
    x = px;
    y = py;

}

void Bala::Mover(Graphics^ g)
{
    if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) { eliminar = true; x = 0; }
    if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height) { eliminar = true; y = 0; }
    x += dx;
    y += dy;
}
