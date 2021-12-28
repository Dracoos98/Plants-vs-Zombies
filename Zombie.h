#pragma once
#include "Base.h"
#include "Bala.h"
#include <iostream>
using namespace std;
class Zombie :
    public Base
{
private:
	vector<Bala*>balas;
	int num_balas;
	bool ganador;
	
public:
	Zombie();
	Zombie(int px, int py);
	~Zombie();
	void Mover(Graphics^ g);
	void Disparar();
	void Mover_balas(Graphics^ g);
	void cambiar_numbalas(int nuevo);
	int retornar_numbalas();
	vector<Bala*> retornar_bala();
	int retornar_cant_balas();
	Bala* retornar_bala_eninidice(int indice);
	bool retornar_ganador();
	void cambiar_vidas(int nuevo);
	int retornar_vidas();
};

