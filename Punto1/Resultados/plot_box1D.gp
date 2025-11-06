set terminal png size 900,700
set output 'Resultados/torpedo_cazador.png'
set title 'Torpedo - Submarino'
set xlabel 'x (m)'
set ylabel 'y (m)'
set grid
set key outside
plot 'Resultados/datos_colisión.dat' using 2:3 with lines lw 2 lc rgb 'black' title 'Torpedo (y vs x)', 'Resultados/datos_colisión.dat' using 5:4 with lines lw 2 lc rgb 'red' title 'Submarino (h vs H)', '-' using 1:2 with points pt 7 ps 2 lc rgb 'blue' title 'Impacto'
333.333 500
e
unset output

set terminal wxt size 900,700
set title 'Torpedo - Submarino (Vista Interactiva)'
plot 'Resultados/datos_colisión.dat' using 2:3 with lines lw 2 lc rgb 'black' title 'Torpedo', 'Resultados/datos_colisión.dat' using 5:4 with lines lw 2 lc rgb 'red' title 'Submarino', '-' using 1:2 with points pt 7 ps 2 lc rgb 'blue' title 'Impacto'
333.333 500
e
pause -1 'Cierra esta ventana para continuar'

set terminal gif animate delay 5 size 900,700
set output 'Resultados/Video_colisión.gif'
set title 'Animación de la colisión'
set xlabel 'x (m)'
set ylabel 'y (m)'
set xrange [0:400]
set yrange [0:600]
set key outside
stats 'Resultados/datos_colisión.dat' skip 1 nooutput
N = STATS_records
do for [i=2:N] {
  plot 'Resultados/datos_colisión.dat' skip 1 every ::1::i using 2:3 with lines lw 2 lc rgb 'black' title 'Torpedo', \
       'Resultados/datos_colisión.dat' skip 1 every ::1::i using 5:4 with lines lw 2 lc rgb 'red' title 'Submarino', \
       'Resultados/datos_colisión.dat' skip 1 every ::i::i using 2:3 with points pt 7 ps 2 lc rgb 'blue' title 'Impacto'
}
unset output
