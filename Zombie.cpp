#include "Zombie.h"
Zombie::Zombie() {

}
Zombie::Zombie(int px, int py)  {
	vector<string>parametros = LeerArchivo();
	System::String^ auxlifes = gcnew System::String(parametros.at(0).c_str());
	vidas = System::Convert::ToInt32(auxlifes);
	dx = 4;
	dy = 4;
	vidas = 5 + rand() % (8 + 1 - 5);
	Desplazamiento(direccion::derecha);
	max_col = 3;
	max_fil = 4;
	col = 0;
	fil = 0;
	x = px;
	y = py;
	ganador = false;
	num_balas = 0;
}
Zombie::~Zombie() {
	for (int i = 0; i < balas.size(); i++)
	{
		delete balas.at(i);
	}
}
void Zombie::Mover(Graphics^ g) {
	if (x + dx < 1 || x + dx + w>g->VisibleClipBounds.Width) dx = 0;
	if (y + dy < 1 || y + dy + h>g->VisibleClipBounds.Height) dy = 0;
	if (y + dy < 30) ganador = true;
	x += dx;
	y += dy;
}
vector<Bala*> Zombie::retornar_bala()
{
	return balas;
}

int Zombie::retornar_cant_balas()
{
	return balas.size();
}

Bala* Zombie::retornar_bala_eninidice(int indice)
{
	return balas.at(indice);
}

bool Zombie::retornar_ganador()
{
	return ganador;
}

void Zombie::cambiar_vidas(int nuevo)
{
	vidas = nuevo;
}

int Zombie::retornar_vidas()
{
	return vidas;
}

void Zombie::Disparar()
{
	System::Random^ r = gcnew System::Random();
	if (num_balas > 0) {
	balas.push_back(new Bala(x + w / 2, y));
	
		if (dx > 1)
			balas.at(balas.size() - 1)->cambiar_dx(r->Next(15, 20));

		if (dx < -1)
			balas.at(balas.size() - 1)->cambiar_dx(-(r->Next(15, 20)));
		if (dy > 1)
			balas.at(balas.size() - 1)->cambiar_dy(r->Next(15, 20));
		if (dy < -1)
			balas.at(balas.size() - 1)->cambiar_dy(-(r->Next(15, 20)));
		num_balas--;
	}
}

void Zombie::Mover_balas(Graphics^ g)
{
	for (int i = 0; i < balas.size(); i++)
	{
		balas.at(i)->Dibujar_desFigura(g);
		balas.at(i)->Mover(g);
	}
	for (int i = 0; i < balas.size(); i++)
	{
		if (balas.at(i)->retornar_eliminar() == true)
			balas.erase(balas.begin() + i);
	}
}

void Zombie::cambiar_numbalas(int nuevo)
{
	num_balas = nuevo;
}

int Zombie::retornar_numbalas()
{
	return num_balas;
}
