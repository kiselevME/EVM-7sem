set terminal png size 1280,941 crop
set output 'graphics_lagrange.png'

set autoscale

set title "My polynoms"
set grid
set xrange [-1:1]
set yrange [-1:1]

plot 1/(1+25*x*x) title "Function", \
"data_2.dat" title "Lagrange"