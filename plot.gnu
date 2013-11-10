set terminal postscript
set output "map.ps"
unset colorbox
unset border
unset xtics
unset ytics
set size square
set palette defined (0 "white", 0.0000000000001 "blue", 1 "red")
plot 'map.dat' u 1:2:3 with image