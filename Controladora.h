#pragma once
#include "Fichas.h"
#include "Zombie.h"
#include "Plantas.h"
#include "Obstaculo.h"
#include <vector>

using namespace std;
using namespace System;
class Controladora
{
private:
	time_t Inicio_f;
	time_t Inicio_i;
	Zombie* objZ;
	vector<Plantas*>plantas;
	vector<Base*>fichas;
	vector<Base*>obstaculos;
	int cplantas;
	int escudo;
	bool esinmune;
public:
	Controladora();
	~Controladora();
	void Dibujar_Zombie(Graphics^ G, Bitmap^ bmp);
	void Desplazar_Zombie(direccion nuevo);
	bool Colision();
	void Disparar();
	void Inmunidad();
	void Dibujar_Bala(Graphics^ g);
	void Crear_Fichas();
	void Dibujar_Fichas(Graphics^ g);
	void Dibujar_Plantas(Graphics^ g, Bitmap^ bmp);
	void Dibujar_Obstaculos(Graphics^ g, Bitmap^ bmp);
	bool Gano();
	bool Perdio();
	int retornar_vidas();
	int retornar_numbalas();
	bool retornar_invulneravilidad();
	

};

