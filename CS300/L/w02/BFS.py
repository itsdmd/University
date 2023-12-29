from collections import defaultdict


# define graph
class Graph:
    # Constructor
    def __init__(self):
        # default dictionary to store graph
        self.graph = defaultdict(list)

    # function to add an edge to graph
    def addEdge(self, u, v):
        # check if the vertex is already in the graph
        if v not in self.graph[u]:
            self.graph[u].append(v)

    # function to be implemented
    # Refrence: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
    def BFS(self, start, goal):
        visited = [start]
        queue = [start]
        result = []

        # Loop until the queue is empty
        while queue:
            # Dequeue the first element
            cur = queue.pop(0)
            result.append(cur)

            # Iterate all adjacent nodes of the dequeued node
            for neigh in self.graph[cur]:
                if neigh not in visited:
                    visited.append(neigh)
                    queue.append(neigh)

                    if neigh == goal:
                        result.append(neigh)
                        return result

        return result

    def traceback(self, start, goal):
        # Iteratively find the parent of nodes
        # starting from the goal node until the start node is reached
        cur = goal
        result = []
        while cur != start:
            result.append(cur)
            for neigh in self.graph:
                if cur in self.graph[neigh]:
                    cur = neigh
                    break
        result.append(start)
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

bfs_result = g.BFS(1, 6)

# Write to output file
f = open("output.txt", "w")
for i in bfs_result:
    f.write(str(i) + " ")
f.close()
