import random
import copy
import math


class NQueensStateNode:
    def __init__(self, initialState):
        self.state = initialState  # list of queen positions for each column
        self.nQueen = len(initialState)  # number of queens
        self.cRow = [0] * (self.nQueen)  # number of queens on the same row i
        self.cDiagonal1 = [0] * (
            self.nQueen * 2 - 1
        )  # number of queens on the same diagonal1
        self.cDiagonal2 = [0] * (
            self.nQueen * 2 - 1
        )  # number of queens on the same diagonal2

    def printState(self):
        print(
            " ".join(str(r) for r in self.state), "\tHeuristic: ", self.getHeuristic()
        )

    def countQueenList(self):
        # [2,3,0,1]
        # TODO: calculate the value of cRow, cDiagonal1, cDiagonal2
        for i in range(self.nQueen):
            row = self.state[i]
            self.cRow[row] += 1
            self.cDiagonal1[i + row] += 1
            self.cDiagonal2[self.nQueen - 1 - i + row] += 1

    def getHeuristic(self):
        # [2,3,0,1]
        self.countQueenList()
        heuristic = 0
        for count in self.cRow + self.cDiagonal1 + self.cDiagonal2:
            heuristic += count * (count - 1)  # Number of attacking pairs
        return heuristic

        """
        heuristic = 0
        for i in range(len(self.state)):
            queen_i_row_pos = self.state[i]
            for j in range(i+1,len(self.state)):
                queen_j_row_pows = self.state[j]
                if(queen_i_row_pos == queen_j_row_pows):
                    heuristic+=1
                if(abs(queen_j_row_pows - queen_i_row_pos) == j-i):
                    heuristic+=1
        return heuristic 
        """

    def getBestSuccesor(self):
        bestState = None
        bestHeuristic = float("inf")
        for i in range(self.nQueen):
            for j in range(self.nQueen):
                newState = copy.deepcopy(self.state)
                newState[i] = j
                newNode = NQueensStateNode(newState)
                heuristic = newNode.getHeuristic()
                if heuristic < bestHeuristic:
                    bestState = newState
                    bestHeuristic = heuristic
        return bestState

    def getFirstChoice(self):
        # Randomly select a successor
        i = random.randrange(self.nQueen)
        j = random.randrange(self.nQueen)
        newState = copy.deepcopy(self.state)
        newState[i] = j
        return newState


def HillClimbing(state):
    currentStateNode = NQueensStateNode(state)
    # TODO: Implement Hill-climbing search
    currentStateNode = NQueensStateNode(state)
    currentStateNode.printState()
    max_tries = 1000
    while max_tries > 0:
        max_tries -= 1
        nextState = currentStateNode.getBestSuccesor()
        if nextState is None:
            break  # No better successor found
        currentStateNode = NQueensStateNode(nextState)
        currentStateNode.printState()
        if currentStateNode.getHeuristic() == 0:
            print("Solution found:")
            currentStateNode.printState()
            break
        elif max_tries == 0:
            print("Best state found after 1000 tries:")
            currentStateNode.printState()
            break


def HillCLimbingFirstChoice(state):
    """Generate successors randomly until one is generated that is better
    than the current state"""
    # TODO
    currentState = state
    while True:
        nextState = NQueensStateNode(currentState).getFirstChoice()
        nextNode = NQueensStateNode(nextState)
        if nextNode.getHeuristic() < NQueensStateNode(currentState).getHeuristic():
            currentState = nextState
            if nextNode.getHeuristic() == 0:
                print("Solution found:")
                nextNode.printState()
                break


def getRandomState(nQueen):
    """returns a random state in which each column has exactly one queen in it"""
    # TODO
    state = [random.randrange(nQueen) for _ in range(nQueen)]
    return state


def HillClimbingRandomRestart(nQueen):
    """That is a series of hill-climbing searches from randomly
    generated initial states until a goal is found.
        • For each restart: run until termination vs run for a fixed time
        • Run a fixed number of restarts or run indefinitely
    """
    # TODO
    num_ran = 10
    while num_ran > 0:
        num_ran = num_ran - 1
        randomState = getRandomState(nQueen)
        final_state = HillClimbing(randomState)
        if final_state.getHeuristic() < best_final_state.getHeuristic():
            best_final_state = final_state
            best_random_state = randomState
            # Run until termination
            # Track the finding of best_final_State
            HillClimbing(best_random_state)


if __name__ == "__main__":
    HillClimbing([2, 3, 0, 1, 2, 3, 0, 1])
    HillClimbingRandomRestart(8)
