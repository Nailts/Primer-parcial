#include <iostream>
#include <cstdlib> 
#include "include/funciones.h"
#include "include/gnuplot.h"
using namespace std;

int main() {
    double Rint, Rext, x0, y0, vx0, vy0, t0, tf, dt;

    cout << "SIMULACION 2D DE PARTICULA EN UNA ROSQUILLA\n";
    solicitarDatos(Rint, Rext, x0, y0, vx0, vy0, t0, tf, dt);
    validarDatos(Rint, Rext, x0, y0, vx0, vy0, t0, tf, dt);

    cout << "\nSimulando movimiento...\n";
    simularMovimiento(Rint, Rext, x0, y0, vx0, vy0, t0, tf, dt);
    cout << "Archivo de datos generado: results/datos_rosquilla.dat\n";

    cout << "\nCreando script de Gnuplot...\n";
    crearScriptGnuplot(Rint, Rext);
    cout << "Generando animacion con Gnuplot...\n";

    system("gnuplot results/plot_rosquilla2D.gp");

    cout << "\n✅ Listo: results/trayectoria_rosquilla.gif generada correctamente.\n";
    return 0;
}
