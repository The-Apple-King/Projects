# This is a PROGRAM that uses the nim code from nim.py. It runs through a series of function calls and print statement
# that will allow you to test if your code works the way we expect
# @Author Daniel Kluver and Min Namgung

from nim import create_token_counts, is_over, is_valid_move, draw_board, update

tokens = create_token_counts(0, 0)
print(tokens)                       # []
tokens = create_token_counts(5, 5)
print(tokens)                       # [5, 4, 3, 2, 1]
tokens = create_token_counts(4, 3)
print(tokens)                       # [3, 2, 1, 1]
tokens = create_token_counts(7, 9)
print(tokens)                       # [9, 8, 7, 6, 5, 4, 3]
tokens = create_token_counts(1, 1)
print(tokens)                       # [1]
tokens = create_token_counts(5, 7)
print(tokens)                       # [7, 6, 5, 4, 3]
tokens = create_token_counts(8, 4)
print(tokens)                       # [4, 3, 2, 1, 1, 1, 1, 1]
tokens = create_token_counts(6, 1)
print(tokens)                       # [1, 1, 1, 1, 1, 1]
tokens = create_token_counts(13, 9)
print(tokens)                       # [9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 1, 1, 1]


tokens = [5, 4, 3, 2]
print(is_valid_move(tokens, '1', '2')) # True
tokens = [8, 7, 6, 5, 4]
print(is_valid_move(tokens, '5', '2')) # True
tokens = [4, 3]
print(is_valid_move(tokens, '1', '1')) # True
tokens = [4, 3]
print(is_valid_move(tokens, '3', '4')) # False
tokens = [5, 4, 3, 2]
print(is_valid_move(tokens, '5', '4')) # False
tokens = [5, 4, 3, 2]
print(is_valid_move(tokens, "a", "a")) # False
tokens = [5, 4, 3, 2]
print(is_valid_move(tokens, "a", "2")) # False
tokens = [5, 4, 3, 2]
print(is_valid_move(tokens, "1", "a")) # False
tokens = [5, 4, 3, 2]
print(is_valid_move(tokens, "0", "1")) # False
tokens = [5, 4, 3, 2]
print(is_valid_move(tokens, "4", "3")) # False
tokens = [5, 4, 3, 2]
print(is_valid_move(tokens, "1", "4")) # False
tokens = [5, 4, 3, 2]
print(is_valid_move(tokens, "3", "3")) # True


tokens = [3, 2, 1]
result = update(tokens, 2, 1)
print(tokens, result)                   # [3, 2, 1] [3, 2, 0]
tokens = [4, 3, 2, 1, 0]
result = update(tokens, 3, 1)
print(tokens, result)                   # [4, 3, 2, 1, 0] [4, 3, 2, 0, 0]
tokens = [9, 8, 7, 6, 5, 4, 3]
result = update(tokens, 6, 2)
print(tokens, result)                   # [9, 8, 7, 6, 5, 4, 3] [9, 8, 7, 6, 5, 4, 1]
tokens = [8, 7, 6, 5]
result = update(tokens, 0, 3)
print(tokens, result)                   # [8, 7, 6, 5] [5, 7, 6, 5]
tokens = [5, 4, 3, 2, 1]
result = update(tokens, 1, 1)
print(tokens, result)                   # [5, 4, 3, 2, 1] [5, 3, 3, 2, 1]
tokens = [4, 3, 2, 1]
result = update(tokens, 1, 2)
print(tokens, result)                   # [4, 3, 2, 1] [4, 1, 2, 1]

tokens = [5,4,3,2,1]
print("before call")
draw_board(tokens)
print("after call")
# before call
# Game board.
#
# ====================
# 1 $$$$$
# 2 $$$$
# 3 $$$
# 4 $$
# 5 $
# ====================
# after call

tokens = [5,4,3,4,1,0,0,9,1]
print("before call")
draw_board(tokens)
print("after call")
# before call
# Game board.
#
# ====================
# 1 $$$$$
# 2 $$$$
# 3 $$$
# 4 $$$$
# 5 $
# 6
# 7
# 8 $$$$$$$$$
# 9 $
# ====================
# after call

tokens = [1]
print("before call")
draw_board(tokens)
print("after call")
# before call
# Game board.
#
# ====================
# 1 $
# ====================
# after call


print(is_over([0]))                 # True
print(is_over([1,4,1,3,1,0]))       # False
print(is_over([0,1,2,3,2]))         # False
print(is_over([1,2,3,4,0]))         # False
print(is_over([0,0,0,0,0,0,0,0]))   # True
print(is_over([1,2,0,2,1,3]))       # False

# EXPECTED RESULTS ALL IN ONE PLACE:
'''
[]
[5, 4, 3, 2, 1]
[3, 2, 1, 1]
[9, 8, 7, 6, 5, 4, 3]
[1]
[7, 6, 5, 4, 3]
[4, 3, 2, 1, 1, 1, 1, 1]
[1, 1, 1, 1, 1, 1]
[9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 1, 1, 1]
True
True
True
False
False
False
False
False
False
False
False
True
[3, 2, 1] [3, 2, 0]
[4, 3, 2, 1, 0] [4, 3, 2, 0, 0]
[9, 8, 7, 6, 5, 4, 3] [9, 8, 7, 6, 5, 4, 1]
[8, 7, 6, 5] [5, 7, 6, 5]
[5, 4, 3, 2, 1] [5, 3, 3, 2, 1]
[4, 3, 2, 1] [4, 1, 2, 1]
before call
Game board.

====================
1 $$$$$
2 $$$$
3 $$$
4 $$
5 $
====================
after call
before call
Game board.

====================
1 $$$$$
2 $$$$
3 $$$
4 $$$$
5 $
6 
7 
8 $$$$$$$$$
9 $
====================
after call
before call
Game board.

====================
1 $
====================
after call
True
False
False
False
True
False

'''