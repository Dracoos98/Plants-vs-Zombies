#include "Plantas.h"

Plantas::Plantas()
{
}

Plantas::~Plantas()
{
}

Plantas::Plantas(int px, int py) 
{
	System::Random^ r = gcnew System::Random();
	x = px;
	y = py;
	max_col = 8;
	max_fil = 1;
	col = r->Next(0,8);
	fil = 0;

	dx = r->Next(12, 21);
	dy = r->Next(12, 21);

	
}

void Plantas::Dibujar_desImagen(Graphics^ g, Bitmap^ bmp)
{
	w = bmp->Width / max_col;
	h = bmp->Height / max_fil;
	Rectangle porcion = Rectangle(col * w, fil * h, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

}

