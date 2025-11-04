set terminal pngcairo size 1000,700 enhanced font 'Arial,12'
set output 'results/grafica_box1D.png'
set grid
set multiplot layout 2,1 title 'Simulación: Partícula en caja 1D'
set title 'Posición de la partícula y pared móvil'
set xlabel 'Tiempo (s)'
set ylabel 'Posición (m)'
plot 'results/datos_box1D.dat' using 1:2 with lines lw 2 lc rgb 'blue' title 'Partícula', 'results/datos_box1D.dat' using 1:4 with lines lw 2 lc rgb 'gray' title 'Pared móvil'
set title 'Energía cinética de la partícula'
set xlabel 'Tiempo (s)'
set ylabel 'Energía (J)'
plot 'results/datos_box1D.dat' using 1:5 with lines lw 2 lc rgb 'red' title 'E_k(t)'
unset multiplot
unset output
