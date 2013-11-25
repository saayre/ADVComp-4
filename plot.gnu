set terminal postscript
set output "map.ps"
unset colorbox
unset border
unset xtics
unset ytics
set nokey
set size square
set yrange [512:0]
set xrange [0:512]
set palette defined (0 "white", 0.0000000000001 "blue", 1 "red")
#set object circle at first 0,0 size first 10 fc rgb "blue"
plot 'map.dat' u 1:2:3 with image, \
     "<echo '256, 384'" with points lc rgb "blue" pt 7