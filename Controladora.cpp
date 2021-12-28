#include "Controladora.h"

Controladora::Controladora()
{
	System::Random^ r = gcnew System::Random();
	objZ = new Zombie(0, 500);
	System::String^ auxplantas = gcnew System::String(objZ->LeerArchivo().at(1).c_str());
	cplantas = System::Convert::ToInt32(auxplantas);
	for (int i = 1; i <= cplantas;i++)
	{
		plantas.push_back(new Plantas(r->Next(0, 1201), r->Next(0, 501)));
		plantas.at(plantas.size() - 1)->cambiar_col(r->Next(0, 8));
	}
	for (int i = 1; i <= 6; i++)
	{
		obstaculos.push_back(new Obstaculo(r->Next(0, 1201), r->Next(0, 501)));
	}
	Inicio_f = time(0);
	esinmune = false;
}

Controladora::~Controladora()
{
	for (int i = 0; i < plantas.size(); i++)
	{
		delete plantas.at(i);
	}
	for (int i = 0; i < fichas.size(); i++)
	{
		delete fichas.at(i);
	}
	for (int i = 0; i < obstaculos.size(); i++)
	{
		delete obstaculos.at(i);
	}
	delete objZ;
}

void Controladora::Dibujar_Zombie(Graphics^ G, Bitmap^ bmp)
{
	objZ->Mover(G);
	objZ->Dibujar_desImagen(G, bmp);
	Inmunidad();
}

void Controladora::Desplazar_Zombie(direccion nuevo)
{
	objZ->Desplazamiento(nuevo);
}

bool Controladora::Colision()
{
	System::Random^ r = gcnew System::Random();
	bool resultado_colision = false;
	Rectangle rZombie = objZ->retonar_rectangle();
	for (int i = 0; i<objZ->retornar_cant_balas() && !resultado_colision; i++)
	{
		Rectangle rBalas = objZ->retornar_bala_eninidice(i)->retonar_rectangle();
		
		for (int j = 0; j < plantas.size() && !resultado_colision; j++)
		{
			Rectangle rPlantas = plantas.at(j)->retonar_rectangle();
			if (rBalas.IntersectsWith(rPlantas))
			{
				
				
					resultado_colision = true;
					objZ->retornar_bala_eninidice(i)->cambiar_eliminar(true);
					plantas.at(j)->cambiar_eliminar(true);
			}
		}
	}
	for (int i=0; i < plantas.size()&&!resultado_colision ; i++)
	{
		Rectangle rPlantas = plantas.at(i)->retonar_rectangle();
		if (rZombie.IntersectsWith(rPlantas))
		{
			if (esinmune == false)
			{
				resultado_colision = true;
				objZ->cambiar_x(0);
				objZ->cambiar_y(500);
				objZ->cambiar_vidas(objZ->retornar_vidas()-1);
				
			}
			
		}
	}
	for (int i = 0; i < obstaculos.size() && !resultado_colision; i++)
	{
		Rectangle rObstaculo = obstaculos.at(i)->retonar_rectangle();
		if (rZombie.IntersectsWith(rObstaculo))
		{
			resultado_colision = true;
				objZ->cambiar_x(0);
				objZ->cambiar_y(500);
		}
	}
	for (int i = 0; i < fichas.size() && !resultado_colision; i++)
	{
		Rectangle rFicahas = fichas.at(i)->retonar_rectangle();
		if (rZombie.IntersectsWith(rFicahas))
		{
			resultado_colision = true;
			fichas.at(i)->cambiar_eliminar(true);
			int bonus=r->Next(0,2);
			if (bonus == 0) {
				esinmune = true;
				Inicio_i = time(0);
				escudo = r->Next(6, 13);
				
			}
			else if (bonus == 1) {
				objZ->cambiar_numbalas(objZ->retornar_numbalas() + 10);
			}
		}
	}
	return resultado_colision;
}

void Controladora::Disparar()
{
	objZ->Disparar();
}

void Controladora::Inmunidad()
{
	if (difftime(time(0), Inicio_i) > escudo)
	{
		esinmune = false;
	}
}

void Controladora::Dibujar_Bala(Graphics^ g)
{
	objZ->Mover_balas(g);
}

void Controladora::Crear_Fichas()
{
	System::Random^ r = gcnew System::Random();
	if (difftime(time(0), Inicio_f) > 5)
	{
		fichas.push_back(new Fichas(r->Next(0, 1201), r->Next(0, 501)));
		Inicio_f = time(0);
	}
}

void Controladora::Dibujar_Fichas(Graphics^ g)
{
	for (int i = 0; i < fichas.size(); i++)
	{
		fichas.at(i)->Mover(g);
		fichas.at(i)->Dibujar_desFigura(g);
	}
	for (int i = 0; i < fichas.size(); i++)
	{
		if (fichas.at(i)->retornar_eliminar() == true)
		{
			fichas.erase(fichas.begin() + i);
		}
	}
}

void Controladora::Dibujar_Plantas(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < plantas.size(); i++)
	{
		plantas.at(i)->Mover(g);
		plantas.at(i)->Dibujar_desImagen(g,bmp);
	}
	for (int i = 0; i < plantas.size(); i++)
	{
		if (plantas.at(i)->retornar_eliminar() == true)
		{
			plantas.erase(plantas.begin() + i);
		}
	}
}

void Controladora::Dibujar_Obstaculos(Graphics^ g, Bitmap ^bmp)
{
	for (int i = 0; i < obstaculos.size(); i++)
	{
		obstaculos.at(i)->Dibujar_desImagen(g, bmp);
	}
	for (int i = 0; i < obstaculos.size(); i++)
	{
		if (obstaculos.at(i)->retornar_eliminar() == true)
		{
			obstaculos.erase(obstaculos.begin() + i);
		}
	}
}

bool Controladora::Gano()
{
	return objZ->retornar_ganador()==true;
}

bool Controladora::Perdio()
{
	return objZ->retornar_vidas()==0;
}

int Controladora::retornar_vidas()
{
	return objZ->retornar_vidas();
}

int Controladora::retornar_numbalas()
{
	return objZ->retornar_numbalas();
}

bool Controladora::retornar_invulneravilidad()
{
	return esinmune;
}
