# ===== Animación x(t) y x_R(t) =====
datafile='results/datos_simulacion.dat'
giffile='results/anim_posicion.gif'

set terminal gif animate delay 5 size 900,600
set output giffile
set title 'Evolución temporal: posición de partícula y pared'
set xlabel 'Tiempo (s)'
set ylabel 'Posición (m)'
set grid

stats datafile using 1 nooutput
tmin = STATS_min; tmax = STATS_max
stats datafile using 2 nooutput
xmin = STATS_min; xmax = STATS_max
stats datafile using 4 nooutput
xRmin = STATS_min; xRmax = STATS_max
dy = (xRmax - xmin)*0.05
set xrange [tmin:tmax]
set yrange [xmin - dy : xRmax + dy]

N = system(sprintf("grep -v '^ *$' '%s' | tail -n +2 | wc -l", datafile))
do for [i=1:N] {
    plot datafile every ::1::i using 1:2 with lines lw 2 lc rgb 'blue' title 'Partícula',\
         datafile every ::1::i using 1:4 with lines lw 2 lc rgb 'gray' title 'Pared móvil'
}
unset output
