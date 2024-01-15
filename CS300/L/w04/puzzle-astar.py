from queue import Queue

class PuzzleNode:
    def __init__(self, board, parent=None, action=None):
        self.board = board
        self.parent = parent
        self.action = action

    def __eq__(self, other):
        return self.board == other.board

    def __hash__(self):
        return hash(tuple(map(tuple, self.board)))

    def is_goal_state(self, goal_state):
        return self.board == goal_state

    def generate_neighbors(self):
        neighbors = []
        blank_i, blank_j = self.get_blank_position()

        for move in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            new_i, new_j = blank_i + move[0], blank_j + move[1]

            if 0 <= new_i < 3 and 0 <= new_j < 3:
                new_board = [row[:] for row in self.board]
                new_board[blank_i][blank_j], new_board[new_i][new_j] = new_board[new_i][new_j], new_board[blank_i][blank_j]
                neighbors.append(PuzzleNode(new_board, self, move))

        return neighbors

    def get_blank_position(self):
        for i in range(3):
            for j in range(3):
                if self.board[i][j] == 0:
                    return i, j
    
    def hamming_distance(self, goal_state):
        # TODO: Implement Hamming distance heuristic
        pass

    def manhattan_distance(self, goal_state):
        # TODO: Implement Manhattan distance heuristic
        pass

def bfs(start_node, goal_state):
    visited = set()
    queue = Queue()

    queue.put(start_node)

    while not queue.empty():
        current_node = queue.get()

        if current_node.is_goal_state(goal_state):
            path = []
            while current_node.parent is not None:
                path.insert(0, current_node.board)
                current_node = current_node.parent
            path.insert(0, start_node.board)
            return path

        visited.add(current_node)

        for neighbor in current_node.generate_neighbors():
            if neighbor not in visited:
                queue.put(neighbor)

    return None

def astar(start_node, goal_state):
    visited = set()
    priority_queue = PriorityQueue()

    # TODO: Enqueue the start node with priority based on the heuristic value

    while not priority_queue.empty():
        current_node = priority_queue.get()

        if current_node.is_goal_state(goal_state):
            # TODO: Return the path to the goal state
            pass

        visited.add(current_node)

        for neighbor in current_node.generate_neighbors():
            if neighbor not in visited:
                # TODO: Enqueue the neighbor with priority based on the heuristic value
                pass

    return None

def print_solution(solution):
    if solution:
        print("Solution found:")
        for step, board in enumerate(solution):
            print(f"Step {step + 1}:")
            print_board(board)
    else:
        print("No solution found.")

def print_board(board):
    for row in board:
        print(" ".join(map(str, row)))
    print()

if __name__ == "__main__":
    start_state = [
        [1, 2, 3],
        [4, 0, 5],
        [6, 7, 8]
    ]

    goal_state = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 0]
    ]

    start_node = PuzzleNode(start_state)

    # solution = bfs(start_node, goal_state)

    solution = astar(start_node, goal_state)

    print_solution(solution)
