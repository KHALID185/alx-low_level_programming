#!/usr/bin/python3
"""
module for calculate perimeter
"""


def island_perimeter(grid) -> int:
    """
        fct for calculate the perimter
        args: list of grids
    """
    wdth = len(grid[0])
    hght = len(grid)
    edg = 0
    sz = 0

    for itr in range(hght):
        for j in range(wdth):
            if grid[itr][j] == 1:
                sz += 1
                if (j > 0 and grid[itr][j - 1] == 1):
                    edg += 1
                if (itr > 0 and grid[itr - 1][j] == 1):
                    edg += 1
    return (sz * 4 - edg * 2)
