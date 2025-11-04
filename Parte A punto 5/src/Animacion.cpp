#include "../Include/funcionesParcial.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

const double EPSILON = 1.0e-6;
const double g = 9.8;

// Aquí copias todas tus funciones: solicitarDatos, validarDatos, simularMovimiento, graficarDatos
void graficarDatos(const string& nombreArchivo, const string& nombreImagen,
                   const string &nombreGif, double xf, double H) 
                   
{
    ofstream gp("Resultados/plot_gif.gp", ios::trunc);
    gp << "set terminal gif animate delay 5 size 900,700\n";
    gp << "set output '" << nombreGif << "'\n";
    gp << "set title 'Animación de la colisión'\n";
    gp << "set xlabel 'x (m)'\n";
    gp << "set ylabel 'y (m)'\n";
    gp << "set xrange [0:" << xf * 1.2 << "]\n";
    gp << "set yrange [0:" << H * 1.2 << "]\n";

    gp << "stats '/Resultados/" << nombreArchivo << "' nooutput\n";
    gp << "N = STATS_records\n";

    gp << "do for [i=2:N] {\n";
    gp << "  plot '/Resultados/" << nombreArchivo << "' every ::1::i using 2:3 with lines lw 2 lc rgb 'black' title 'Torpedo', "
       << "'/Resultados/" << nombreArchivo << "' every ::1::i using 5:4 with lines lw 2 lc rgb 'red' title 'Submarino', "
       << "'/Resultados/" << nombreArchivo << "' every ::i::i using 2:3 with points pt 7 ps 2 lc rgb 'blue' title 'Impacto'\n";
    gp << "}\n";

    gp << "unset output\n";

    gp.close();
}

