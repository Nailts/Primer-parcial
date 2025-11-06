#ifndef FUNCIONESPARCIAL_H
#define FUNCIONESPARCIAL_H

#include <string>
using namespace std;

void solicitarDatos(double &y0, double &y, double &x, double &xf, double &H, double &h,
                    double &VH, double &v, double &t0, double &t, double &tf, double &dt, double &z);

void validarDatos(double &y0, double &y, double &x, double &xf, double &H, double &h,
                  double &VH, double &v, double &t0, double &t, double &tf, double &dt, double &z);

void simularMovimiento(double &y0, double &y, double &x, double &xf, double &H, double &h,
                       double &VH, double &v, double &t0, double &t, double &tf, double &dt, double &z);

void graficarDatos(const string& nombreArchivo, const string& nombreImagen,
                   const string &nombreGif, double xf, double H);

#endif
