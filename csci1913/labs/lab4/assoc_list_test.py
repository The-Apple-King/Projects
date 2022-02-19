#
# Tests for required functions on lab 4
#   10 Feb 2022
#   Min Namgung
#   DANIEL KLUVER
#
# Each test has a comment showing what output is expected.
# In general, each test will be around 2 points each.

from assoc_lists import *

# Linear association list tests:

empty = []
lin_list_num = [("word", 3.14), ("reason", 1.23), ("candy", 5), ("fault", 4.1)]

associate_list_1 = [("apple", 6.5), ("banana", 8.3), ("peach", 9.1), ("strawberry", 2.1)]
associate_list_2 = [("Chicago", 2.5), ("LA", 7), ("New York", 15), ("Minneapolis", 9.7)]
associate_list_3 = [("red", 7), ("orange", 8), ("blue", 10), ("green", 13)]
associate_list_4 = [("computer", 1), ("mouse", 3), ("keyboard", 5), ("monitor", 6)]
associate_list_5 = [("math", 4.5), ("english", 16), ("chemistry", 37), ("physics", 6)]

# The lin_list is equivalent to this: {3:"word", 1:"reason", 5:"candy", 4:"fault"}
# Note, we can use any "sortable" data for keys, so any number or strings.

# Add test sets
print(unsorted_list_to_dict([]))               # {}
print(unsorted_list_to_dict(associate_list_1)) # {6.5: 'apple', 8.3: 'banana', 9.1: 'peach', 2.1: 'strawberry'}
print(unsorted_list_to_dict(associate_list_2)) # {2.5: 'Chicago', 7: 'LA', 15: 'New York', 9.7: 'Minneapolis'}
print(unsorted_list_to_dict(associate_list_3)) # {7: 'red', 8: 'orange', 10: 'blue', 13: 'green'}
print(unsorted_list_to_dict(associate_list_4)) # {1: 'computer', 3: 'mouse', 5: 'keyboard', 6: 'monitor'}
print(unsorted_list_to_dict(associate_list_5)) # {4.5: 'math', 16: 'english', 37: 'chemistry', 6: 'physics'}


print(is_sorted([]))               # True
print(is_sorted(associate_list_1)) # False
print(is_sorted(associate_list_2)) # False
print(is_sorted(associate_list_3)) # True
print(is_sorted(associate_list_4)) # True
print(is_sorted(associate_list_5)) # False

print(unsorted_get(empty, 1.23, "apple"))            # apple
print(unsorted_get(lin_list_num, 53.2, "wonka"))     # wonka
print(unsorted_get(lin_list_num, 3.14, 0))           # word
print(unsorted_get(lin_list_num, 5, "no"))           # candy
print(unsorted_get(lin_list_num, 4.1, "yes"))        # fault

unsorted_put(empty, "apple", "dog")
print(empty)                                    # [('dog', 'apple')]
unsorted_put(lin_list_num, 5, "sugar")

print(len(lin_list_num))                        # 4
print( ("sugar", 5) in lin_list_num)            # True
print(unsorted_get(lin_list_num, 5, "what"))    # sugar

unsorted_put(lin_list_num, 10.3, "flood")
print(len(lin_list_num))                        # 5
print( ("flood", 10.3) in lin_list_num)         # True



# BINARY SEAR ASSOCIATION TESTS
print("BINARY")
empty = []
bin_list = {
   "crow" : 3,
   "raven" : 49,
   "fish" : 2,
   "cat" : 13,
   "dog" : 52,
   "zebra" : 13,
   "whale" : 11.3,
   "emu" : 56
}
# note that python let's us use < and > so no issue here.
bin_list = [(13, 'cat'), (3, 'crow'), (52, 'dog'), (56, 'emu'), (2, 'fish'), (49, 'raven'), (11.3, 'whale'), (41, 'zebra')]


print(sorted_get(empty, "dog", "no"))                    # no
print(sorted_get(bin_list, "apple", "nada"))             # nada
print(sorted_get(bin_list, "dragon", "nope"))            # nope
print(sorted_get(bin_list, "zzz", "no"))                 # no
print(sorted_get(bin_list, "cat", "no"))                 # 13
print(sorted_get(bin_list, "whale", "no"))               # 11.3
print(sorted_get(bin_list, "zebra", "no"))               # 41


sorted_put(empty, "apple", "dog")
print(empty)                                    # [('dog', 'apple')]

bin_list = [(13, 'cat'), (3, 'crow'), (52, 'dog'), (56, 'emu'), (2, 'fish'), (49, 'raven'), (11.3, 'whale'), (41, 'zebra')]
sorted_put(bin_list, "cat", 99)

print(sorted_get(bin_list, "cat", "no"))        # 99
print(len(bin_list))                            # 8
print(bin_list[0])                              # (99, 'cat')

bin_list = [(13, 'cat'), (3, 'crow'), (52, 'dog'), (56, 'emu'), (2, 'fish'), (49, 'raven'), (11.3, 'whale'), (41, 'zebra')]
sorted_put(bin_list, "zebra", 99)

print(sorted_get(bin_list, "zebra", "no"))      # 99
print(len(bin_list))                            # 8
print(bin_list[7])                              # (99, 'zebra')

bin_list = [(13, 'cat'), (3, 'crow'), (52, 'dog'), (56, 'emu'), (2, 'fish'), (49, 'raven'), (11.3, 'whale'), (41, 'zebra')]
sorted_put(bin_list, "dog", 99)

print(sorted_get(bin_list, "dog", "no"))        # 99
print(len(bin_list))                            # 8
print(bin_list[2])                              # (99, 'dog')

bin_list = [(13, 'cat'), (3, 'crow'), (52, 'dog'), (56, 'emu'), (2, 'fish'), (49, 'raven'), (11.3, 'whale'), (41, 'zebra')]
sorted_put(bin_list, "apple", 99)

print(sorted_get(bin_list, "apple", "no"))      # 99
print(len(bin_list))                            # 9
print(bin_list[0])                              # (99, 'apple')

bin_list = [(13, 'cat'), (3, 'crow'), (52, 'dog'), (56, 'emu'), (2, 'fish'), (49, 'raven'), (11.3, 'whale'), (41, 'zebra')]
sorted_put(bin_list, "zzzzz", 99)

print(sorted_get(bin_list, "zzzzz", "no"))       # 99
print(len(bin_list))                             # 9
print(bin_list[-1])                              # (99, 'zzzzz')

bin_list = [(13, 'cat'), (3, 'crow'), (52, 'dog'), (56, 'emu'), (2, 'fish'), (49, 'raven'), (11.3, 'whale'), (41, 'zebra')]
sorted_put(bin_list, "dragon", 99)

print(sorted_get(bin_list, "dragon", "no"))     # 99
print(len(bin_list))                            # 9
print(bin_list[3])                              # (99, 'dragon')


# ENTIRE EXPECTED OUTPUT:
'''

{}
{6.5: 'apple', 8.3: 'banana', 9.1: 'peach', 2.1: 'strawberry'}
{2.5: 'Chicago', 7: 'LA', 15: 'New York', 9.7: 'Minneapolis'}
{7: 'red', 8: 'orange', 10: 'blue', 13: 'green'}
{1: 'computer', 3: 'mouse', 5: 'keyboard', 6: 'monitor'}
{4.5: 'math', 16: 'english', 37: 'chemistry', 6: 'physics'}
True
False
False
True
True
False
apple
wonka
word
candy
fault
[('dog', 'apple')]
4
True
sugar
5
True
BINARY
no
nada
nope
no
13
11.3
41
[("dog", "apple")]
99
8
(99, 'cat')
99
8
(99, 'zebra')
99
8
(99, 'dog')
99
9
(99, 'apple')
99
9
(99, 'zzzzz')
99
9
(99, 'dragon')

'''