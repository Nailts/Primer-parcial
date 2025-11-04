#include <iostream>
#include "../include/funciones.h"
using namespace std;

int main() {
    double L0, x0, v0, u, e, t0, tf, dt;
    string archivoDatos  = "results/datos_box1D.dat";
    string imagenGrafica = "results/grafica_box1D.png";
    string gifAnimacion  = "results/anim_simulacion.gif";

    solicitarDatos(L0, x0, v0, u, e, t0, tf, dt);
    validarDatos(L0, x0, v0, u, e, t0, tf, dt);
    simularMovimiento(L0, x0, v0, u, e, t0, tf, dt, archivoDatos);
    graficarDatos(archivoDatos, imagenGrafica);
    generarAnimacion(archivoDatos, gifAnimacion);

    cout << "\nSimulación completada correctamente.\n";
    cout << "Resultados: " << archivoDatos << endl;
    cout << "Gráfica PNG: " << imagenGrafica << endl;
    cout << "Animación GIF: " << gifAnimacion << endl;
    return 0;
}
