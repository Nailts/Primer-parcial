#include <iostream>
#include "Include/funcionesParcial.h"   // <--- ¡Este include es vital!
using namespace std;

  // ======================== MAIN =========================
    int main() {
        double y0, y, x, xf, H, h, VH, v,t0, t, tf, dt, z;

        solicitarDatos(y0, y, x, xf, H, h, VH, v,t0, t, tf, dt, z);
        validarDatos(y0, y, x, xf, H, h, VH, v,t0, t, tf, dt, z);
        simularMovimiento(y0, y, x, xf, H, h, VH, v,t0, t, tf, dt, z);

        // Generar PNG y abrir ventana interactiva con Gnuplot
        graficarDatos("datos_colisión.dat", "torpedo_cazador.png","Video_colisión.gif",xf,H);

        return 0; // solo mensajes informativos de graficarDatos
    }

