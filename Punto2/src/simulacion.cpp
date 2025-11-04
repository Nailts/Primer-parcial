#include "../include/funciones.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

const double EPSILON = 1.0e-9;

// Aquí copias las funciones: solicitarDatos, validarDatos, simularMovimiento
void solicitarDatos(double &Rint, double &Rext, double &x0, double &y0,
                    double &vx0, double &vy0,
                    double &t0, double &tf, double &dt) {

    cout << "Radio interno (m): ";
    cin  >> Rint;
    cout << "Radio externo (m): ";
    cin  >> Rext;
    cout << "Posicion inicial x0 (m): ";
    cin  >> x0;
    cout << "Posicion inicial y0 (m): ";
    cin  >> y0;
    cout << "Velocidad inicial vx0 (m/s): ";
    cin  >> vx0;
    cout << "Velocidad inicial vy0 (m/s): ";
    cin  >> vy0;
    cout << "Tiempo inicial t0 (s): ";
    cin  >> t0;
    cout << "Tiempo final tf (s): ";
    cin  >> tf;
    cout << "Paso de tiempo dt (s): ";
    cin  >> dt;
}

void validarDatos(double &Rint, double &Rext, double &x0, double &y0,
                  double &vx0, double &vy0,
                  double &t0, double &tf, double &dt) {

    while (Rint <= 0.0) {
        cout << "El radio interno debe ser positivo. Ingrese Rint: ";
        cin >> Rint;
    }

    while (Rext <= Rint) {
        cout << "El radio externo debe ser mayor que el interno. Ingrese Rext: ";
        cin >> Rext;
    }

    double r0 = sqrt(x0*x0 + y0*y0);
    while (r0 <= Rint || r0 >= Rext) {
        cout << "La posicion inicial debe estar entre los dos radios.\nIngrese x0 y y0: ";
        cin >> x0 >> y0;
        r0 = sqrt(x0*x0 + y0*y0);
    }

    while (vx0 == 0.0 && vy0 == 0.0) {
        cout << "La partícula no puede estar en reposo total. Ingrese vx0 y vy0: ";
        cin >> vx0 >> vy0;
    }

    while (tf <= t0) {
        cout << "tf debe ser mayor que t0. Ingrese tf: ";
        cin >> tf;
    }

    while (dt <= 0.0 || dt >= (tf - t0)) {
        cout << "dt debe ser positivo y menor que (tf - t0). Ingrese dt: ";
        cin >> dt;
    }
}

void simularMovimiento(double Rint, double Rext, double x0, double y0,
                       double vx0, double vy0,
                       double t0, double tf, double dt) {

    ofstream myfile("results/datos_rosquilla.dat");
    myfile << fixed << setprecision(5);
    myfile << setw(12) << "t"
           << setw(15) << "x"
           << setw(15) << "y"
           << setw(15) << "vx"
           << setw(15) << "vy" << '\n';

    double t = t0, x = x0, y = y0, vx = vx0, vy = vy0;
    int i = 0;

    while (t <= tf + EPSILON) {
        myfile << setw(12) << t
               << setw(15) << x
               << setw(15) << y
               << setw(15) << vx
               << setw(15) << vy << '\n';

        // Actualizar posición
        x += vx * dt;
        y += vy * dt;
        i++;
        t = t0 + i * dt;

        // Calcular distancia radial
        double r = sqrt(x*x + y*y);

        // Rebote en el radio externo
        if (r >= Rext) {
            double nx = x / r;
            double ny = y / r;
            double vn = vx * nx + vy * ny;
            vx -= 2 * vn * nx;
            vy -= 2 * vn * ny;
            x = nx * (Rext - EPSILON);
            y = ny * (Rext - EPSILON);
        }

        // Rebote en el radio interno
        if (r <= Rint) {
            double nx = -x / r; // dirección hacia el centro
            double ny = -y / r;
            double vn = vx * nx + vy * ny;
            vx -= 2 * vn * nx;
            vy -= 2 * vn * ny;
            x = (x / r) * (Rint + EPSILON);
            y = (y / r) * (Rint + EPSILON);
        }
    }
    myfile.close();
}