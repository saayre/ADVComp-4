set terminal postscript
set output "dims.ps"
set title "Dimensionality"
set xrange [:2]

fun(x) = a * x + b
a = -2
b = 3
IGNORE_ABOVE=2
filter(y)=(y<=IGNORE_ABOVE)?(y):(1/0)
fit fun(x) "dims.dat" using (filter($1)):2 via a, b
plot "dims.dat" using 1:2 title 'Data', \
	 a * x + b title 'Fit'