# This is a PROGRAM that uses the nim code to play a game of nim
# Right now it is pretty sparse -- lots of room for improvement.
# @Author Daniel Kluver and Min Namgung
from nim import create_token_counts, is_over, is_valid_move, draw_board, update


def play_one_game():
    token_counts = create_token_counts(4,4)

    while not is_over(token_counts):
        row = "a"
        takes = "a"
        while not is_valid_move(token_counts, row, takes):
            draw_board(token_counts)
            row = input("Choose a row 1 - "+str(len(token_counts))+" ")
            takes = input("How many tokens to take, 0 to 3 (no more than are available) ")
            if not is_valid_move(token_counts, row, takes):
                print("Invalid move")
        row = int(row) - 1
        takes = int(takes)
        token_counts = update(token_counts, row, takes)
    print("Game over, the last player lost!")

if __name__ == "__main__":
    play_one_game()