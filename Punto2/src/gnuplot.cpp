#include "../include/gnuplot.h"
#include <fstream>
using namespace std;

void crearScriptGnuplot(double Rint, double Rext) {
 
   ofstream gp("results/plot_rosquilla2D.gp");

    
    
    gp << "set terminal gif animate delay 5 loop 0 size 600,800\n";
    gp << "set output 'results/trayectoria_rosquilla.gif'\n\n";
    gp << "set title 'Movimiento 2D de una particula en una rosquilla'\n";
    gp << "set xlabel 'x (m)'\n";
    gp << "set ylabel 'y (m)'\n";
    gp << "set size ratio -1\n";
    gp << "set xrange [-" << Rext << ":" << Rext << "]\n";
    gp << "set yrange [-" << Rext << ":" << Rext << "]\n";
    gp << "set grid\n\n"; 
    gp << "set object 1 circle at 0,0 size " << Rext << " front lw 2 lc rgb 'purple'\n";
    gp << "set object 2 circle at 0,0 size " << Rint << " front lw 2 lc rgb 'green'\n";
    gp << "stats 'results/datos_rosquilla.dat' using 1 nooutput\n";
    gp << "N = STATS_records - 1\n";
    gp << "do for [i=2:N] {\n";
    gp << "  plot 'results/datos_rosquilla.dat' every ::2::i using 2:3 with lines lw 2 lc rgb 'blue' notitle, \\\n";
    gp << "       0,0 notitle lc rgb 'black'\n";
    gp << "}\n";
    gp << "set terminal wxt size 600,800 title 'results/trayectoria_rosquilla.gif'\n";
    gp << "set output\n";

        // --- 2. Generar GRÁFICA PNG (Vista final) ---
    gp << "\n# GRAFICA FINAL (PNG)\n";
    gp << "set terminal png size 600,800\n"; // Terminal PNG para gráfica estática
    gp << "set output 'results/Grafica_rosquilla.png'\n"; // Archivo de salida para la PNG
    gp << "plot 'results/datos_rosquilla.dat' using 2:3 with lines lw 2 lc rgb 'blue' title 'Trayectoria Completa', \\\n";
    gp << "     'results/datos_rosquilla.dat' using 2:3 every ::2::2 with points pt 7 ps 1 lc rgb 'red' title 'Posicion Inicial'\n"; // Gráfica completa + punto inicial
   // --- 3. Volver a la terminal interactiva (opcional) ---
    gp << "\nset terminal wxt size 600,800 title 'Vista final: trayectoria en la rosquilla'\n";
    gp << "set output\n";
    gp << "replot\n"; // Muestra la gráfica en la ventana interactiva al finalizar (si gnuplot está en modo interactivo)

    gp.close();   
}

