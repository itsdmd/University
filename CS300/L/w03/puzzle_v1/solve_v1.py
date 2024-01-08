# -*- coding: utf-8 -*-
"""
Created on Fri Jan 13 12:56:49 2023

@author: TrongLe
"""
from puzzle import Puzzle


def bfs():
    init_state = [[1,8,2],[0,4,3],[7,6,5]]
    p = Puzzle()

    frontier = []
    frontier.append(init_state)
    
    explored = []
    ACTIONS = ['U', 'D', 'L', 'R']
    while True:
        if frontier:
            pass
        else:
            return False