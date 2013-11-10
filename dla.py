# dla.py, written by Sayre Christenson, written 2013-11-07

import numpy as num
import random as ran

def check():
    chk = 0

    if grid[ix+1, iy] == 1:
        chk = 1
    if grid[ix-1, iy] == 1:
        chk = 1
    if grid[ix, iy+1] == 1:
        chk = 1
    if grid[ix, iy-1] == 1:
        chk = 1

    return chk


def move(direction):
    global ix, iy

    if direction == 1:
        ix += 1
    if direction == 1:
        ix -= 1
    if direction == 1:
        iy += 1
    if direction == 1:
        ix -= 1

    ix %= side - 1
    iy %= side - 1


def check8():
    return 0




def move8(direction):
    return 0


diag = 0

# switch on diagonals
if diag == 1:
    check = check8
    move = move8

# initialize grid
side = 512
grid = num.zeros( (side, side), dtype=int)

grid[side/2, side/2] = 1

# walk in particles
N = 100
ran.seed(None)

for n in range(N):

    ix = ran.randint(0, side-1)
    iy = ran.randint(0, side-1)

    if ix > side/4 and ix < 3*side/4 and iy > side/4 and iy < 3*side/4:
        continue

    if grid[ix, iy] == 1:
        continue

    # move
    while check() == 0:
        move(ran.randint(1, 4))
        print ix, iy

    grid[ix, iy] = 1

with open("plotdla.dat", "w") as f:
    for inds, val in enumerate(grid):

        f.write(inds)

