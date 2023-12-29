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
    # Refrence: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
    def DFS(self, node, visited):
        if node not in visited:
            visited.append(node)

            for neigh in self.graph[node]:
                self.DFS(neigh, visited)

        return visited


# Driver code
# Create a graph given in the above diagram
g = Graph()

# Read from input file
f = open("input.txt", "r")
for line in f:
    u, v = [int(it) for it in line.strip().split(" ")]
    g.addEdge(u, v)
f.close()

visited = []
g.DFS(1, visited)

# Write to output file
f = open("output.txt", "w")
for i in visited:
    f.write(str(i) + " ")
f.close()
