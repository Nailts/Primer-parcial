set terminal gif animate delay 5 size 900,700
set output 'Resultados/Video_colisión.gif'
set title 'Animación de la colisión'
set xlabel 'x (m)'
set ylabel 'y (m)'
set xrange [0:80]
set yrange [0:120]
stats 'Resultados/datos_colisión.dat' nooutput
N = STATS_records
do for [i=2:N] {
  plot 'Resultados/datos_colisión.dat' every ::1::i using 2:3 with lines lw 2 lc rgb 'black' title 'Torpedo', 'Resultados/datos_colisión.dat' every ::1::i using 5:4 with lines lw 2 lc rgb 'red' title 'Submarino', 'Resultados/datos_colisión.dat' every ::i::i using 2:3 with points pt 7 ps 2 lc rgb 'blue' title 'Impacto'
}
unset output
