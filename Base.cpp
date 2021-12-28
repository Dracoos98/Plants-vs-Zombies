#include "Base.h"
Base::Base()
{
    eliminar = false;
    dx = dy = 0;
}

Base::Base(int px, int py, int pw, int ph)
{
    x = px;
    y = py;
    w = pw;
    h = ph;
    eliminar = false;
    dx = dy = 0;
    orientacion = direccion::ninguno;
}
void Base::cambiar_direccion() {
    orientacion = direccion::ninguno;
    if (dx < 0) {
        x += 26;
    }
    if (dx > 0) {
        x -= 26;
    }
    if (dy < 0) {
        y += 26;

    }
    if (dy > 0) {
        y -= 26;
    }
    dx = 0;
    dy = 0;
    
}
Base::Base(int px, int py, int pw, int ph, int pmaxfil, int pmaxcol, int pfil, int pcol)
{
    x = px;
    y = py;
    w = pw;
    h = ph;
    eliminar = false;
    dx = dy = 0;
    orientacion = direccion::ninguno;
    max_fil = pmaxfil;
    max_col = pmaxcol;
    col = pcol;
    fil = pfil;
}

Base::~Base() {}

void Base::cambiar_x(int nuevo) { x = nuevo; }

void Base::cambiar_y(int nuevo) { y = nuevo; }

void Base::cambiar_w(int nuevo) { w = nuevo; }

void Base::cambiar_dx(int nuevo)
{
    dx = nuevo;
}

void Base::cambiar_dy(int nuevo)
{
    dy = nuevo;
}



void Base::cambiar_h(int nuevo) { h = nuevo; }

void Base::cambiar_max_fil(int nuevo) { max_fil = nuevo; }

void Base::cambiar_max_col(int nuevo) { max_col = nuevo; }

void Base::cambiar_fil(int nuevo) { fil = nuevo; }

void Base::cambiar_col(int nuevo) { col = nuevo; }

void Base::cambiar_eliminar(bool nuevo) { eliminar = nuevo; }

void Base::Desplazamiento(direccion nuevo)
{
    orientacion = nuevo;
    dx = dy = 0;
    if (orientacion == direccion::ninguno) {
        dx = 0;  dy = 0;
    }
    if (orientacion == direccion::arriba) {
        dy = -25; fil = 0;
    }
    if (orientacion == direccion::abajo) {
        dy = 25; fil = 2;
    }
    if (orientacion == direccion::izquierda) {
        dx = -25; fil = 3;
    }
    if (orientacion == direccion::derecha) {
        dx = 25; fil = 1;
    }
}
 

void Base::cambiar_fraccion_movimientoY(int nuevo) {
    fraccion_movimientoY = nuevo;
}
void Base::cambiar_fraccion_movimientoX(int nuevo) {
    fraccion_movimientoX = nuevo;
}
int Base::retornar_fraccion_movimientoY() {
    return fraccion_movimientoY;
}
int Base::retornar_fraccion_movimientoX() {
    return fraccion_movimientoX;
}
int Base::retornar_x() { return x; }

int Base::retornar_y() { return y; }

int Base::retornar_w() { return w; }

int Base::retornar_h() { return h; }

int Base::retornar_dx() { return dx; }

int Base::retornar_dy() { return dy; }

int Base::retornar_max_fil() { return max_fil; }

int Base::retornar_max_col() { return max_col; }

int Base::retornar_fil() { return fil; }

int Base::retornar_col() { return col; }

bool Base::retornar_eliminar() { return eliminar; }

Rectangle Base::retonar_rectangle() { return Rectangle(x, y, w, h); }

void Base::Mover(Graphics^ g)
{
    if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) dx = dx * -1;
    if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height) dy = dy * -1;
    x += dx;
    y += dy;
}

void Base::Dibujar(Graphics^ g)
{}

void Base::Borrar(Graphics^ g)
{}

void Base::Dibujar_desImagen(Graphics^ g, Bitmap^ bmp)
{
    w = bmp->Width / max_col;
    h = bmp->Height / max_fil;
    Rectangle porcion = Rectangle(col * w, fil * h, w, h);
    g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
    col++;
    if (col >= max_col)
    {
        col = 0;
    }
}
vector<string> Base::LeerArchivo()
{
    string linea;
    vector<string> resultado;
    ifstream miarchivo("INPUT.TXT");
    if (!miarchivo.fail())
    {
        while (!miarchivo.eof())
        {
            getline(miarchivo, linea);
            resultado.push_back(linea);
        }
        miarchivo.close();
    }

    return resultado;
}
void Base::GrabarArchivo(vector<string> datos)
{
    //ofstream miarchivo("OUTPUT.TXT");  // BORRA EL ARCHIVO ANTES DE GRABAR EL NUEVO DATO
    ofstream miarchivo("PUNTAJE.TXT",std::ofstream::app);  // NO BORRA EL ARCHIVO ANTES DE GRABAR EL NUEVO DATO
    if (!miarchivo.fail())
    {
        for (int i = 0; i < datos.size(); i++)
            miarchivo << datos.at(i) << "\n";

        miarchivo.flush();
        miarchivo.close();
    }
}

void Base::Dibujar_desFigura(Graphics^ g)
{
    Pen^ p = gcnew Pen(Color::Red); //Color de contorno
    p->Width = 5; //Contorno de la figura(No tiene colisión)
    w = 20; //ancho
    h = 20; //largo
    SolidBrush^ br = gcnew SolidBrush(Color::Blue); //Color de relleno
    g->DrawRectangle(p, x, y, w, h);
    g->FillRectangle(br, x, y, w, h);
}

