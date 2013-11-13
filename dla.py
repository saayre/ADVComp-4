# dla.py, written by Sayre Christenson, written 2013-11-07

import numpy as num
import random as ran
import sys

def check():
    chk = 0

    if grid[ (ix+1)%(side-1), iy] == 1:
        chk = 1
    if grid[ (ix-1)%(side-1), iy] == 1:
        chk = 1
    if grid[ix, (iy+1)%(side-1)] == 1:
        chk = 1
    if grid[ix, (iy-1)%(side-1)] == 1:
        chk = 1

    return chk

def move(direction):
    global ix, iy

    if direction == 1:
        ix += 1
    if direction == 2:
        ix -= 1
    if direction == 3:
        iy += 1
    if direction == 4:
        iy -= 1

    ix %= side
    iy %= side


def check8():
    chk = 0

    if grid[ (ix+1)%(side-1), iy] == 1:
        chk = 1
    if grid[ (ix-1)%(side-1), iy] == 1:
        chk = 1
    if grid[ix, (iy+1)%(side-1)] == 1:
        chk = 1
    if grid[ix, (iy-1)%(side-1)] == 1:
        chk = 1

    if grid[ (ix+1)%(side-1), (iy+1)%(side-1)] == 1:
        chk = 1
    if grid[ (ix-1)%(side-1), (iy+1)%(side-1)] == 1:
        chk = 1
    if grid[ (ix+1)%(side-1), (iy-1)%(side-1)] == 1:
        chk = 1
    if grid[ (ix-1)%(side-1), (iy-1)%(side-1)] == 1:
        chk = 1

    return chk

def move8(direction):
    global ix, iy

    if direction == 1 or direction == 5 or direction == 6:
        ix += 1
    if direction == 2 or direction == 7 or direction == 8:
        ix -= 1
    if direction == 3 or direction == 5 or direction == 7:
        iy += 1
    if direction == 4 or direction == 6 or direction == 8:
        iy -= 1

    ix %= side
    iy %= side


if len(sys.argv) == 1:
    print "dla N side diag"
    exit()

# switch on diagonals
if len(sys.argv) == 4:
    check = check8
    move = move8

# initialize grid
side = int(sys.argv[2])
grid = num.zeros( (side, side), dtype=int)

grid[side/2, side/2] = 1

# walk in particles
N = int(sys.argv[1])
ran.seed(None)

for n in range(N):

    if ran.randint(0, 1) == 0:
        ix = ran.randint(0, side-1)
        iy = ran.randint(0, 1) * (side -1)
        
    else:
        iy = ran.randint(0, side-1)
        ix = ran.randint(0, 1) * (side - 1)

    if grid[ix, iy] == 1:
        n -= 1
        continue

    print n
    # move
    while check() == 0:
        if len(sys.argv) == 4:
            move(ran.randint(1, 8))
        else:
            move(ran.randint(1, 4))

    grid[ix, iy] = 1

# count boxes
box_lengths = []
i = 2
while i < side:
    box_lengths.append(i)
    i *= 2

box_count = {}                  # results dictionary
for box in box_lengths:
    box_count[box] = 0
    start_y = 0
    while start_y < side:
        
        start_x = 0
        while start_x < side:
            # if there's a 1 in the box
            if sum(sum( grid[start_x:start_x+box, start_y:start_y+box] )) > 0:
                box_count[box] += 1

            start_x += box

        start_y += box

print 'hihi'
print(box_count)

with open("map.dat", "w") as f:
    for y_ind, row in enumerate(grid):
        for x_ind, val in enumerate(row):

            f.write( '{0} {1} {2}\n'.format(x_ind, y_ind, val) )
