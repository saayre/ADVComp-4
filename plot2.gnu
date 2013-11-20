set terminal postscript
set output "dims.ps"
set title "Dimensionality"

fun(x) = a * x
a = -2
fit fun(x) "dims.dat" using 1:2 via a
plot "dims.dat" using 1:2, \
	 a * x