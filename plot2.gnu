set terminal postscript
set output "dims.ps"
set title "Dimensionality"

fun(x) = a * x + b
a = -2
b = 3
fit fun(x) "dims.dat" using 1:2 via a, b
plot "dims.dat" using 1:2 title 'Data', \
	 a * x + b title 'Fit'