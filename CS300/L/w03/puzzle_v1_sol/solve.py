# -*- coding: utf-8 -*-
"""
Created on Fri Jan  6 14:11:06 2023

@author: TrongLe
"""
from puzzle import Puzzle


def print_solution(p, parrent):
    cur = p.get_encode_state(p.goal_state)
    while parrent[cur] != -1:
        print('{}\n{}\n{}\n'.format(cur[0:3],cur[3:6],cur[6:]))
        cur = parrent[cur]
    return
        
    
def bfs():
    init_state = [[1,8,2],[0,4,3],[7,6,5]]
    parrent = {}

    p = Puzzle()
    parrent[p.get_encode_state(init_state)] = -1
    frontier = []
    frontier.append(init_state)
    explored = []
    ACTIONS = ['U', 'D', 'L', 'R']
    while True:
        if frontier:
            node = frontier.pop(0)
            explored.append(node)
            for action in ACTIONS:
                child = p.transition(node, action)
                #print(child)
                if child and child not in explored and child not in frontier:
                    parrent[p.get_encode_state(child)] = p.get_encode_state(node)
                    if p.check_goal(child):
                        return print_solution(p, parrent)
                    frontier.append(child)
        else:
            return False
        

bfs()
                    
                    
                
                
    