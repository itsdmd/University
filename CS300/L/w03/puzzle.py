from queue import Queue


class PuzzleNode:
    board: list[list[int]] = [[]]
    parent = None

    def __init__(self, board, parent=None):
        # TODO: Initialize PuzzleNode attributes
        self.board = board
        self.parent = parent

    def __eq__(self, other):
        # TODO: Implement equality comparison
        if other is None:
            return False
        else:
            for i in range(len(self.board)):
                for j in range(len(self.board[i])):
                    if self.board[i][j] != other.board[i][j]:
                        return False
            return True

    def __hash__(self):
        # TODO: Implement hash function
        return hash(tuple(map(tuple, self.board)))

    def is_goal_state(self, goal_state):
        # TODO: Implement goal state check
        if self.board == goal_state:
            return True
        else:
            return False

    def generate_neighbors(self):
        # TODO: Generate neighboring states
        # Return a set of strings representing the neighboring states

        blank_pos = self.get_blank_position()
        board_width = len(self.board[0])
        board_height = len(self.board)

        # Get valid actions
        valid_actions = []
        if blank_pos[0] == 0:
            valid_actions.append("up")
        elif blank_pos[0] == board_width - 1:
            valid_actions.append("down")
        else:
            valid_actions.append("up")
            valid_actions.append("down")

        if blank_pos[1] == 0:
            valid_actions.append("left")
        elif blank_pos[1] == board_height - 1:
            valid_actions.append("right")
        else:
            valid_actions.append("left")
            valid_actions.append("right")

        # Create set for neighbors
        neighbors = set()

        # Generate neighbors
        # print("Generating neighbors of " + str(self.board))
        # print("Blank position: " + str(blank_pos))
        # print("Valid actions: " + str(valid_actions))
        for action in valid_actions:
            # print("Action: " + action)
            new_board = [row[:] for row in self.board]

            if action == "up":
                new_board[blank_pos[0]][blank_pos[1]] = new_board[blank_pos[0] + 1][
                    blank_pos[1]
                ]
                new_board[blank_pos[0] + 1][blank_pos[1]] = 0
            elif action == "down":
                new_board[blank_pos[0]][blank_pos[1]] = new_board[blank_pos[0] - 1][
                    blank_pos[1]
                ]
                new_board[blank_pos[0] - 1][blank_pos[1]] = 0
            elif action == "right":
                new_board[blank_pos[0]][blank_pos[1]] = new_board[blank_pos[0]][
                    blank_pos[1] - 1
                ]
                new_board[blank_pos[0]][blank_pos[1] - 1] = 0
            elif action == "left":
                new_board[blank_pos[0]][blank_pos[1]] = new_board[blank_pos[0]][
                    blank_pos[1] + 1
                ]
                new_board[blank_pos[0]][blank_pos[1] + 1] = 0

            # Convert board to string
            new_board_name = ""
            for row in range(len(new_board)):
                for col in range(len(new_board[row])):
                    new_board_name += str(new_board[row][col])

            # print(new_board_name)

            # Add neighbor set
            neighbors.add(PuzzleNode(new_board, self))

        return neighbors

    def get_blank_position(self):
        # TODO: Get the position of the blank tile
        x, y = -1, -1
        for i in range(len(self.board)):
            for j in range(len(self.board[i])):
                if self.board[i][j] == 0:
                    x = i
                    y = j
                    break
        return (x, y)


def bfs(start_node, goal_state):
    visited = set()
    queue = Queue()

    queue.put(start_node)

    while not queue.empty():
        current_node = queue.get()

        if current_node.is_goal_state(goal_state):
            # TODO: Return the path to the goal state
            path = []
            for _ in range(len(visited)):
                try:
                    path.append(current_node.board)
                    current_node = current_node.parent
                except:
                    # Reached the start node
                    break
            if len(path) > 0:
                path.reverse()
                return path
            else:
                return None

        visited.add(current_node)

        for neighbor in current_node.generate_neighbors():
            if neighbor not in visited:
                # TODO: Enqueue the neighbor for exploration
                queue.put(neighbor)

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
    start_state = [[1, 2, 3], [4, 0, 5], [6, 7, 8]]

    goal_state = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]

    start_node = PuzzleNode(start_state)
    solution = bfs(start_node, goal_state)

    print_solution(solution)
