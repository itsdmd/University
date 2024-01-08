import random
import copy
import math

class NQueensStateNode:
    def __init__(self, initialState):
        self.state = initialState # list of queen positions for each column
        self.nQueen = len(initialState) #number of queens
        self.cRow = dict() # number of queens on the same row i
        self.cDiagonal1 = dict() # number of queens on the same diagonal1
        self.cDiagonal2 = dict() # number of queens on the same diagonal2
  

    def printState(self):
        print(' '.join(str(r) for r in self.state))


    def countQueenList(self):

        # TODO: calculate the value of cRow, cDiagonal1, cDiagonal2

        pass

    def getHeuristic(self):
        self.countQueenList()
        heuristic = 0

        # TODO: calculate heuristic value based on cRow, cDiagonal1, cDiagonal2

        return heuristic

    def getBestSuccesor(self):
        bestState = None

        # TODO: find the best succesor which has the best heuristic value

        return bestState

    def gefFirstChoice(self):
        # TODO
        pass


  

def HillClimbing(state):
    currentStateNode = NQueensStateNode(state)
    # TODO: Implement Hill-climbing search


def HillCLimbingFirstChoice(state):
    '''Generate successors randomly until one is generated that is better
    than the current state'''
    # TODO
    pass

def getRandomState(nQueen):
    '''returns a random state in which each column has exactly one queen in it'''
    # TODO
    pass

def HillClimbingRandomRestart(nQueen):
    '''That is a series of hill-climbing searches from randomly
    generated initial states until a goal is found.
        • For each restart: run until termination vs run for a fixed time
        • Run a fixed number of restarts or run indefinitely
    '''
    # TODO
    pass

if __name__ == '__main__':
    HillClimbing([2, 3, 0, 1])
