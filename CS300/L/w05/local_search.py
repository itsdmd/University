import random
import copy
import math

file = open("output.txt", "w")


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

    def resetArrays(self):
        self.cRow = [0] * (self.nQueen)
        self.cDiagonal1 = [0] * (self.nQueen * 2 - 1)
        self.cDiagonal2 = [0] * (self.nQueen * 2 - 1)

    def printState(self):
        print(
            " ".join(str(r) for r in self.state), "\tHeuristic: ", self.getHeuristic()
        )

    def getFormattedState(self):
        return " ".join(str(r) for r in self.state)

    def countQueenList(self):
        # TODO: calculate the value of cRow, cDiagonal1, cDiagonal2
        self.resetArrays()
        for i in range(self.nQueen):
            row = self.state[i]
            self.cRow[row] += 1
            self.cDiagonal1[i + row] += 1
            self.cDiagonal2[self.nQueen - 1 - i + row] += 1

    def getHeuristic(self):
        self.countQueenList()
        heuristic = 0
        for count in self.cRow + self.cDiagonal1 + self.cDiagonal2:
            heuristic += count * (count - 1)  # Number of attacking pairs
        return heuristic

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
    # TODO: Implement Hill-climbing search
    currentStateNode = NQueensStateNode(state)
    currentStateNode.printState()
    max_tries = 1000
    while max_tries > 0:
        max_tries -= 1
        nextState = currentStateNode.getBestSuccesor()
        if nextState is None:
            break
        nextStateNode = NQueensStateNode(nextState)
        # currentStateNode.printState()
        if nextStateNode.getHeuristic() == 0:
            print("Solution found:")
            nextStateNode.printState()
            return nextStateNode
        elif nextStateNode.getHeuristic() < currentStateNode.getHeuristic():
            currentStateNode = nextStateNode
            continue
        elif nextStateNode.getHeuristic() == currentStateNode.getHeuristic():
            print("Local minimum found:")
            nextStateNode.printState()
            print("\n")
            return nextStateNode
        elif max_tries == 0:
            print("Best state found after 1000 tries:")
            nextStateNode.printState()
            print("\n")
            return nextStateNode


def HillCLimbingFirstChoice(state):
    """Generate successors randomly until one is generated that is better
    than the current state"""
    # TODO
    currentState = state
    currentNode = NQueensStateNode(currentState)
    max_tries = 1000
    nextState = currentNode.getFirstChoice()
    nextNode = NQueensStateNode(nextState)

    while max_tries > 0:
        max_tries -= 1

        if nextNode.getHeuristic() < currentNode.getHeuristic():
            nextNode.printState()
            currentState = nextState
            currentNode = nextNode
            if nextNode.getHeuristic() == 0:
                print("Solution found:")
                nextNode.printState()
                break

        nextState = currentNode.getFirstChoice()
        nextNode = NQueensStateNode(nextState)

    file = open("output.txt", "a")
    file.write(nextNode.getFormattedState() + "\n")
    file.close()


def getRandomState(nQueen):
    """Returns a random state in which each column has exactly one queen in it"""
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
    best_final_state = None
    while num_ran > 0:
        num_ran = num_ran - 1
        randomState = getRandomState(nQueen)
        final_state = HillClimbing(randomState)
        if final_state is None:
            break
        best_final_state = final_state
        if final_state.getHeuristic() < best_final_state.getHeuristic():
            best_final_state = final_state
            best_random_state = randomState
            HillClimbing(best_random_state)

    file = open("output.txt", "a")
    file.write(best_final_state.getFormattedState() + "\n")
    file.close()


if __name__ == "__main__":
    file = open("output.txt", "w")

    initial_state = [2, 3, 0, 1, 2, 3, 0, 1]
    file.write(" ".join(str(r) for r in initial_state) + "\n")
    file.close()

    print("===== Hill Climbing =====")
    file = open("output.txt", "a")
    file.write(HillClimbing(initial_state).getFormattedState() + "\n")
    file.close()

    print("===== Hill Climbing First Choice =====")
    HillCLimbingFirstChoice(initial_state)
    print("\n")

    print("===== Hill Climbing Random Restart =====")
    print("Num of restarts: 8")
    HillClimbingRandomRestart(8)
