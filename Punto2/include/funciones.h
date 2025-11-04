#ifndef FUNCIONES_H
#define FUNCIONES_H

// Aquí van las declaraciones de las funciones
void solicitarDatos(double &Rint, double &Rext, double &x0, double &y0,
                    double &vx0, double &vy0,
                    double &t0, double &tf, double &dt);

void validarDatos(double &Rint, double &Rext, double &x0, double &y0,
                  double &vx0, double &vy0,
                  double &t0, double &tf, double &dt);

void simularMovimiento(double Rint, double Rext, double x0, double y0,
                       double vx0, double vy0,
                       double t0, double tf, double dt);

#endif