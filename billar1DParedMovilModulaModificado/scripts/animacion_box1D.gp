set terminal gif animate delay 20 optimize size 1000,700 font 'Arial,12'
set output 'results/anim_simulacion.gif'
set grid
stats 'results/datos_box1D.dat' nooutput
N = STATS_records - 1
do for [i=2:N+1] {
  set multiplot layout 2,1 title 'Simulación: Partícula en caja 1D'
  set title 'Posición de la partícula y pared móvil'
  set xlabel 'Tiempo (s)'
  set ylabel 'Posición (m)'
  plot 'results/datos_box1D.dat' using 1:2 every ::1::i with linespoints lw 2 pt 7 lc rgb 'blue' title 'Partícula', 'results/datos_box1D.dat' using 1:4 every ::1::i with lines lw 2 lc rgb 'gray' title 'Pared móvil'
  set title 'Energía cinética de la partícula'
  set xlabel 'Tiempo (s)'
  set ylabel 'Energía (J)'
  plot 'results/datos_box1D.dat' using 1:5 every ::1::i with linespoints lw 2 pt 7 lc rgb 'red' title 'E_k(t)'
  unset multiplot
}
unset output
