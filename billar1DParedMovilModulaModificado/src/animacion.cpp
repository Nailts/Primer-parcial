#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void generarAnimacion(const string &nombreArchivo, const string &nombreGif) {
    ofstream gp("scripts/animacion_box1D.gp");
    gp << "set terminal gif animate delay 20 optimize size 1000,700 font 'Arial,12'\n";
    gp << "set output '" << nombreGif << "'\n";
    gp << "set grid\n";

    gp << "stats '" << nombreArchivo << "' nooutput\n";
    gp << "N = STATS_records - 1\n";

    gp << "do for [i=2:N+1] {\n";
    gp << "  set multiplot layout 2,1 title 'Simulación: Partícula en caja 1D'\n";

    gp << "  set title 'Posición de la partícula y pared móvil'\n";
    gp << "  set xlabel 'Tiempo (s)'\n  set ylabel 'Posición (m)'\n";
    gp << "  plot '" << nombreArchivo
       << "' using 1:2 every ::1::i with linespoints lw 2 pt 7 lc rgb 'blue' title 'Partícula', "
       << "'" << nombreArchivo
       << "' using 1:4 every ::1::i with lines lw 2 lc rgb 'gray' title 'Pared móvil'\n";

    gp << "  set title 'Energía cinética de la partícula'\n";
    gp << "  set xlabel 'Tiempo (s)'\n  set ylabel 'Energía (J)'\n";
    gp << "  plot '" << nombreArchivo
       << "' using 1:5 every ::1::i with linespoints lw 2 pt 7 lc rgb 'red' title 'E_k(t)'\n";

    gp << "  unset multiplot\n";
    gp << "}\n";
    gp << "unset output\n";
    gp.close();

    if(system("gnuplot scripts/animacion_box1D.gp") == 0)
        cout << "✅ Animación GIF generada: " << nombreGif << endl;
    else
        cerr << "⚠️ Error al generar GIF." << endl;
}
