#pragma once
#include <string>
using namespace std;

// Solicita los datos iniciales al usuario
void solicitarDatos(double &L0, double &x0, double &v0,
                    double &u, double &e, double &t0, double &tf, double &dt);

// Valida los datos ingresados
void validarDatos(double &L0, double &x0, double &v0,
                  double &u, double &e, double &t0, double &tf, double &dt);

// Simula el movimiento de la partícula
void simularMovimiento(double L0, double x0, double v0, double u, double e,
                       double t0, double tf, double dt,
                       const string &nombreArchivo);

// Genera un PNG con dos subgráficos (posición y energía)
void graficarDatos(const string &nombreArchivo, const string &nombreImagen);

// Genera un GIF animado combinando posición y energía
void generarAnimacion(const string &nombreArchivo, const string &nombreGif);
