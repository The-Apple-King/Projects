#
# Tests for required functions on lab 5
#
# Each test has a comment showing what output is expected.
# In general, each test will be around 1 points each.

from sorts import *

print(insertion_sort([1, 2, 3, 4, 5]))     # 4
print(insertion_sort([5, 4, 3, 2, 1]))     # 14
print(insertion_sort([1, 5, 3, 4, 2]))     # 9
print(insertion_sort([2, 7, 5, 6, 9, 3, 1, 0, 8, 4]))     # 34

print(selection_sort([1, 2, 3, 4, 5]))     # 10
print(selection_sort([5, 4, 3, 2, 1]))     # 10
print(selection_sort([1, 5, 3, 4, 2]))     # 10
print(selection_sort([2, 7, 5, 6, 9, 3, 1, 0, 8, 4]))     # 45

print(merge_sort([1, 2, 3, 4, 5]))         # 7
print(merge_sort([5, 4, 3, 2, 1]))         # 5
print(merge_sort([1, 5, 3, 4, 2]))         # 8
print(merge_sort([2, 7, 5, 6, 9, 3, 1, 0, 8, 4]))         # 23

print(merge([1,2,3,4,5,6,7,8], 0, 4, 7)) # 5
print(merge([9,1,5,3,6,-2], 1, 2, 4)) #3
print(merge([2, 5, 6, 7, 9, 0, 1, 3, 4, 8], 0, 4, 9)) #9
print(merge([1, 5, 6, 7, 8, 0, 2, 3, 4, 9], 0, 4, 9)) #9