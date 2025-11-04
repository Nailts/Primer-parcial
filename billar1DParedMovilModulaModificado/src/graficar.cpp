#include <fstream>
#include <cstdlib>
#include <iostream>
#include "../include/funciones.h"
using namespace std;

void graficarDatos(const string &nombreArchivo, const string &nombreImagen) {
    ofstream gp("scripts/graficar_box1D.gp");
    gp << "set terminal pngcairo size 1000,700 enhanced font 'Arial,12'\n";
    gp << "set output '" << nombreImagen << "'\n";
    gp << "set grid\n";
    gp << "set multiplot layout 2,1 title 'Simulación: Partícula en caja 1D'\n";

    gp << "set title 'Posición de la partícula y pared móvil'\n";
    gp << "set xlabel 'Tiempo (s)'\nset ylabel 'Posición (m)'\n";
    gp << "plot '" << nombreArchivo
       << "' using 1:2 with lines lw 2 lc rgb 'blue' title 'Partícula', "
       << "'" << nombreArchivo
       << "' using 1:4 with lines lw 2 lc rgb 'gray' title 'Pared móvil'\n";

    gp << "set title 'Energía cinética de la partícula'\n";
    gp << "set xlabel 'Tiempo (s)'\nset ylabel 'Energía (J)'\n";
    gp << "plot '" << nombreArchivo
       << "' using 1:5 with lines lw 2 lc rgb 'red' title 'E_k(t)'\n";

    gp << "unset multiplot\nunset output\n";
    gp.close();

    if(system("gnuplot scripts/graficar_box1D.gp") == 0)
        cout << "✅ Gráfico PNG generado: " << nombreImagen << endl;
    else
        cerr << "⚠️ Error al generar PNG." << endl;
}
