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
        result = []

        while queue:
            cur = queue.pop(0)
            result.append(cur)
            print(cur, end=" ")

            for neigh in self.graph[cur]:
                if neigh not in visited:
                    visited.append(neigh)
                    queue.append(neigh)

        return result


# Driver code
# Create a graph given in the above diagram
g = Graph()

# Read from input file
f = open("input.txt", "r")
for line in f:
    u, v = [int(it) for it in line.strip().split(" ")]
    g.addEdge(u, v)
f.close()

print(g.graph)

g.BFS(1)
