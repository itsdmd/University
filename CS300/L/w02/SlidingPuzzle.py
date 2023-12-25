from BFS import Graph
import numpy as np

g = Graph()

board = [[1, 2, 3], [4, 0, 5]]


# Return a list of possible next states
def possibleNextStates(curState):
    nextStates = []
    boardWidth = len(curState[0])
    boardHeight = len(curState)

    for i in range(boardHeight):  # row index
        for j in range(boardWidth):  # column index
            if curState[i][j] == 0:
                if i > 0:
                    nextState = [row[:] for row in curState]
                    nextState[i][j] = nextState[i - 1][j]
                    nextState[i - 1][j] = 0
                    nextStates.append(nextState)
                if i < boardHeight - 1:
                    nextState = [row[:] for row in curState]
                    nextState[i][j] = nextState[i + 1][j]
                    nextState[i + 1][j] = 0
                    nextStates.append(nextState)
                if j > 0:
                    nextState = [row[:] for row in curState]
                    nextState[i][j] = nextState[i][j - 1]
                    nextState[i][j - 1] = 0
                    nextStates.append(nextState)
                if j < boardWidth - 1:
                    nextState = [row[:] for row in curState]
                    nextState[i][j] = nextState[i][j + 1]
                    nextState[i][j + 1] = 0
                    nextStates.append(nextState)
    return nextStates


stateDict = {}
stateDictIndex = 0
finalState = np.array([[1, 2, 3], [4, 5, 0]])
finalStateFound = False


def addStateToDict(state):
    global stateDict, stateDictIndex

    stateDict[str(state)] = stateDictIndex
    stateDictIndex = stateDictIndex + 1
    print("Added state " + str(state) + " at index " + str(stateDict[str(state)]))


# Generate a graph of all possible states from the initial state
def generateGraph(g, currentState):
    global stateDict, stateDictIndex, finalState, finalStateFound

    if finalStateFound:
        return

    if np.array_equal(np.array(currentState), finalState):
        finalStateFound = True
        return

    if str(currentState) not in stateDict:
        addStateToDict(currentState)

    nextStates = possibleNextStates(currentState)
    # print("Next states: " + str(nextStates))

    for nextState in nextStates:
        if finalStateFound:
            return

        genGraph = False
        if str(nextState) not in stateDict:
            addStateToDict(nextState)
            genGraph = True

        g.addEdge(stateDict[str(currentState)], stateDict[str(nextState)])

        if genGraph:
            generateGraph(g, nextState)


generateGraph(g, board)
print(g.graph)

# Driver code
path = g.BFS(0)

# Translate the path from index to state
