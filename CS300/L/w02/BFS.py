from collections import defaultdict

# define graph


class Graph:

    # Constructor
    def __init__(self):
        # default dictionary to store graph
        self.graph = defaultdict(list)

    # function to add an edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)

    # function to be implemented
    def BFS(self, s):
        visited = [s]
        queue = [s]

        print(self.graph[0])

        while queue:
            current = queue.pop(0)
            print(current, end=" ")

            for neigh in self.graph[current]:
                if neigh not in visited:
                    visited.append(neigh)
                    queue.append(neigh)


# Driver code
# Create a graph given in the above diagram
g = Graph()

# Read from input file
f = open("input.txt", "r")
for line in f:
    u, v = [int(it) for it in line.strip().split(' ')]
    g.addEdge(u, v)
f.close()

g.BFS(0)
