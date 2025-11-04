# ===== Animación E(t) =====
datafile='results/datos_simulacion.dat'
giffile='results/anim_energia.gif'

set terminal gif animate delay 5 size 900,600
set output giffile
set title 'Evolución temporal: Energía cinética'
set xlabel 'Tiempo (s)'
set ylabel 'Energía (J)'
set grid

stats datafile using 1 nooutput
tmin = STATS_min; tmax = STATS_max
stats datafile using 5 nooutput
Emin = STATS_min; Emax = STATS_max
dE = (Emax - Emin)*0.05
set xrange [tmin:tmax]
set yrange [Emin - dE : Emax + dE]

N = system(sprintf("grep -v '^ *$' '%s' | tail -n +2 | wc -l", datafile))
do for [i=1:N] {
    plot datafile every ::1::i using 1:5 with lines lw 2 lc rgb 'red' title 'Energía cinética'
}
unset output
