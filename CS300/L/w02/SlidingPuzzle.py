from BFS import Graph
import numpy as np

g = Graph()

board = [[4, 1, 2], [5, 0, 3]]


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
stateDictIndex = 1
finalState = np.array([[1, 2, 3], [4, 5, 0]])
finalStateFound = False
frontier = [board]


def addStateToDict(state):
    global stateDict, stateDictIndex

    if str(state) not in stateDict:
        stateDict[str(state)] = stateDictIndex
        # print(
        #     "Added state "
        #     + str(state)
        #     + " to dictionary, index: "
        #     + str(stateDictIndex)
        # )
        stateDictIndex += 1

    return stateDict[str(state)]


# Generate a graph of all possible states from the initial state
def generateGraph(g, currentState):
    global stateDict, stateDictIndex, finalState, finalStateFound, frontier

    if np.array_equal(np.array(currentState), finalState):
        finalStateFound = True
        return

    # Get all possible next states,
    # add them to the graph and frontier
    curStateIndex = addStateToDict(currentState)
    nextStates = possibleNextStates(currentState)
    for state in nextStates:
        if np.array_equal(np.array(state), finalState):
            finalStateFound = True
            finalStateIndex = addStateToDict(state)
            g.addEdge(curStateIndex, finalStateIndex)
            # print("Final state found")
            return

        stateIndex = addStateToDict(state)
        g.addEdge(curStateIndex, stateIndex)
        # Find if the state is already in the frontier
        if state not in frontier:
            frontier.append(state)

    frontier.pop(0)
    if frontier:
        # Board is unsolvable if recursion depth is too high
        try:
            generateGraph(g, frontier[0])
        except RecursionError:
            print("Board is unsolvable")
            return
    else:
        return

    return


generateGraph(g, board)
# print(g.graph)


# Driver code
try:
    finalStateIndex = stateDict[str(finalState.tolist())]
    g.BFS(1, finalStateIndex)

    path = g.traceback(1, finalStateIndex)
    path.reverse()

    print("Solution:")
    for index in path:
        print(list(stateDict.keys())[list(stateDict.values()).index(index)])
except:
    exit(1)
