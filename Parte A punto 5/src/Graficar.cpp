#include "../Include/funcionesParcial.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;


void graficarDatos(const string& nombreArchivo, const string& nombreImagen, double xf, double H) {
    ofstream gp("Resultados/plot_png.gp", ios::trunc);

   // ====== 1) GENERAR PNG CORRECTAMENTE ======
    gp << "set terminal pngcairo size 900,700\n";
    gp << "set output 'Resultados/" << nombreImagen << "'\n";
    gp << "set title 'Torpedo - Submarino'\n";
    gp << "set xlabel 'x (m)'\n";
    gp << "set ylabel 'y (m)'\n";
    gp << "set grid\n";
    gp << "set key outside\n";

    gp << "plot 'Resultados/" << nombreArchivo
       << "' using 2:3 with lines lw 2 lc rgb 'black' title 'Torpedo (y vs x)', "
       << "'Resultados/" << nombreArchivo
       << "' using 5:4 with lines lw 2 lc rgb 'red' title 'Submarino (h vs H)', "
       << "'-' using 1:2 with points pt 7 ps 2 lc rgb 'blue' title 'Impacto'\n";
    gp << xf << " " << H << "\n";
    gp << "e\n";

    // Cerrar correctamente la imagen
    gp << "unset output\n\n";


    // ====== 2) MOSTRAR VENTANA INTERACTIVA ======
    gp << "set terminal wxt size 900,700\n";
    gp << "set title 'Torpedo - Submarino (Vista Interactiva)'\n";
    gp << "plot 'Resultados/" << nombreArchivo
       << "' using 2:3 with lines lw 2 lc rgb 'black' title 'Torpedo', "
       << "'Resultados/" << nombreArchivo
       << "' using 5:4 with lines lw 2 lc rgb 'red' title 'Submarino', "
       << "'-' using 1:2 with points pt 7 ps 2 lc rgb 'blue' title 'Impacto'\n";
    gp << xf << " " << H << "\n";
    gp << "e\n";
    gp << "pause -1 'Cierra esta ventana para continuar'\n\n";

    gp << "unset output\n";
    gp.close();

    system("Resultados/gnuplot plot_png.gp");
}
