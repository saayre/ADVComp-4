set encoding iso_8859_1
set terminal postscript
set output "dims.ps"
set title "Some kind of DLA Dimensionality"
set xrange [:2]
set yrange [1:4]
set xlabel "log(s)"; set ylabel "log(N)"

fun(x) = a * x + b
a = -2
b = 3
set label "slope = this \261 that" at 1.4, 3.2
IGNORE_ABOVE=2
filter(y)=(y<=IGNORE_ABOVE)?(y):(1/0)
fit fun(x) "dims.dat" using (filter($1)):2 via a, b
plot "dims.dat" using (filter($1)):2 title 'Data' lt -1 pt 7 ps 0.8, \
	 a * x + b title 'Fit' lt 1 lc rgb 'red' lw 2
