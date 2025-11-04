#include <iostream>
#include "Include/funcionesParcial.h"   // <--- ¡Este include es vital!
using namespace std;

int main() {
    double y0, y, x, xf, H, h, VH, v, t0, t, tf, dt, z;

    solicitarDatos(y0, y, x, xf, H, h, VH, v, t0, t, tf, dt, z);
    validarDatos(y0, y, x, xf, H, h, VH, v, t0, t, tf, dt, z);
    simularMovimiento(y0, y, x, xf, H, h, VH, v, t0, t, tf, dt, z);
    graficarDatos("Resultados/datos_colisión.dat", "Resultados/torpedo_cazador.png",
                  "Resultados/Video_colisión.gif", xf, H);
    return 0;
}
