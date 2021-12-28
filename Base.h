#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace System::Drawing;
using namespace std;
public enum direccion{arriba, abajo, izquierda, derecha, ninguno};
class Base
{
protected:
	int x, y, w, h, dx, dy;
	int vidas;
	bool eliminar;
	direccion orientacion;
	int max_fil, max_col, col, fil;
	int fraccion_movimientoY, fraccion_movimientoX;
public:
	Base();
	Base(int px, int py, int pw, int ph);
	Base(int px, int py, int pw, int ph, int pmaxfil, int pmaxcol, int pfil, int pcol);
	~Base();
	void cambiar_x(int nuevo);
	void cambiar_y(int nuevo);
	void cambiar_h(int nuevo);
	void cambiar_w(int nuevo);
	void cambiar_dx(int nuevo);
	void cambiar_dy(int nuevo);

	void cambiar_direccion();
	void cambiar_max_fil(int nuevo);
	void cambiar_max_col(int nuevo);
	void cambiar_col(int nuevo);
	void cambiar_fil(int nuevo);
	void cambiar_eliminar(bool nuevo);
	void cambiar_fraccion_movimientoY(int nuevo);
	void cambiar_fraccion_movimientoX(int nuevo);
	void Desplazamiento(direccion nuevo);
	
	int retornar_x();
	int retornar_y();
	int retornar_h();
	int retornar_w();
	int retornar_dx();
	int retornar_dy();
	int retornar_max_fil();
	int retornar_max_col();
	int retornar_col();
	int retornar_fil();
	bool retornar_eliminar();
	int retornar_fraccion_movimientoY();
	int retornar_fraccion_movimientoX();
	Rectangle retonar_rectangle();
	virtual void Mover(Graphics ^g);
	void Dibujar(Graphics^ g);
	virtual void Dibujar_desImagen(Graphics^ g, Bitmap^ bmp);
	void Borrar(Graphics^ g);
	vector<string> LeerArchivo();
	void GrabarArchivo(vector<string> datos);
	virtual void Dibujar_desFigura(Graphics^ g);
};

