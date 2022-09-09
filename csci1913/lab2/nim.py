
from lib2to3.pgen2 import token


def create_token_counts(size, token_max):
    board = []
    for i in range(size):
        if token_max-i > 0:
            board.append(token_max-i)
        else:
            board.append(1)
    return board

def is_valid_move(token_counts, row, takes):
    if row.isdigit() and takes.isdigit():
        row = int(row) - 1
        if row < len(token_counts) and row > -1:
            takes = int(takes)

            if (token_counts[row] >= takes and
                    1 <= takes <= 3):
                return True
    return False
    

def update(token_counts, row, takes):
    board = token_counts.copy()
    board[row] -= takes
    return board

def draw_board(token_counts):
    print("Game board.")
    print("")
    print("====================")
    for i, token in enumerate(token_counts, start=1):
        print(i, "", end = "")
        for _ in range(token):
            print("$", end = "")
        print("")
    print("====================")

def is_over(token_counts):
    isOver = True
    for i in token_counts:
        if i != 0:
            isOver = False
    return isOver
