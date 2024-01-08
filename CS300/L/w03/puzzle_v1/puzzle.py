# -*- coding: utf-8 -*-
"""
Created on Fri Jan  6 13:21:45 2023

@author: TrongLe
"""

from copy import deepcopy

class Puzzle:

    def __init__(self):
        self.goal_state = [[1,2,3],[4,5,6],[7,8,0]]
        self.state = None
        self.size = 3
        self.x0 = 0
        self.y0 = 0
        
    def find_blank_pos(self, state):
        """
        Find blank position of current state.

        Returns
        -------
        A tuples (x0,y0) is the position of the blank.

        """
        
        for x, row in enumerate(state):
            for y, e in enumerate(row):
                if e == 0:
                    return x, y
            
    def update_blank_pos(self, x, y):
        state = deepcopy(self.state)
        state[self.x0][self.y0] = state[x][y]
        state[x][y] = 0
        return state
        
    def transition(self, state, action):
        self.x0, self.y0 = self.find_blank_pos(state)
        self.state = state
        if action == 'U':
            if self.x0 > 0:
                x, y = self.x0 - 1, self.y0
                return self.update_blank_pos(x, y)
            else:
                return None
        if action == 'D':
            if self.x0 < self.size - 1:
                x, y = self.x0 + 1, self.y0
                return self.update_blank_pos(x, y)
            else:
                return None
        if action == 'L':
            if self.y0 > 0:
                x, y = self.x0, self.y0 - 1
                return self.update_blank_pos(x, y)
            else:
                return None
        if action == 'R':
            if self.y0 < self.size - 1:
                x, y = self.x0, self.y0 + 1
                return self.update_blank_pos(x, y)
            else:
                return None
    
    def check_goal(self, state):
        return state == self.goal_state
    
                
                
            
            
        
    