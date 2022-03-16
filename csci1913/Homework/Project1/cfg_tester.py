from cfg import *
import my_rng

# start out by seeding the rng for consisitent results
my_rng.set_seed(10)

print('TEST grammar 1')
# Start -> a
# should always generate "a"
G1 = new_grammar()
# rule is a length 1 tuple this time. The PDF says that it can be a tuple of strings or a list of strings.
add_rule(G1, "Start", ("a",))
for i in range(10):
    seq = generate(G1)
    print(len(seq), end=" ")
    for elem in seq:
        print(elem, end='')
    print()
    # should print 1 a 10 times.
# TEST grammar 1
# 1 a
# 1 a
# 1 a
# 1 a
# 1 a
# 1 a
# 1 a
# 1 a
# 1 a
# 1 a

print()
print('TEST grammar 2')
# this adds a much longer sequence of rules and rules with more than one thing in them.
G2 = new_grammar()
# rules will be lists this time.
add_rule(G2, "Start", ["a", "A", 'a'])
add_rule(G2, "A", ["b", "B", 'b'])
add_rule(G2, "B", ["c", "C", 'c'])
add_rule(G2, "C", ["D", "D"])
add_rule(G2, "D", ["d"])

for i in range(10):
    seq = generate(G2)
    print(len(seq), end=" ")
    for elem in seq:
        print(elem, end='')
    print()
    # should print 8 abcddcba repeatedly

# Technically this can be a list or a tuple, so we cast to list so tests are reliable.

print(list(generate(G2))) # ['a', 'b', 'c', 'd', 'd', 'c', 'b', 'a']

# TEST grammar 2
# 8 abcddcba
# 8 abcddcba
# 8 abcddcba
# 8 abcddcba
# 8 abcddcba
# 8 abcddcba
# 8 abcddcba
# 8 abcddcba
# 8 abcddcba
# 8 abcddcba



print()
print('TEST grammar 3')
# This time we will have more than one rule for Start.
G3 = new_grammar()
# rules will be lists AND tuples this time.
# I add this first rule 4 times so that we get cat 1/5th of the time, -- that way we get each output around 1/5th of the time!
add_rule(G3, "Start", ("Letter", "o", "Letter"))
add_rule(G3, "Start", ("Letter", "o", "Letter"))
add_rule(G3, "Start", ("Letter", "o", "Letter"))
add_rule(G3, "Start", ("Letter", "o", "Letter"))
add_rule(G3, "Start", ("c", "a", "t"))
add_rule(G3, "Letter", ['d'])
add_rule(G3, "Letter", ['g'])
# This one will be like the tests for random -- we can't give exact counts, but we can give an expected range...
dod = 0
dog = 0
god = 0
gog = 0
cat = 0
unexpected = 0
for i in range(10000):
    seq = generate(G3)
    if len(seq) != 3:
        unexpected += 1
    elif seq[0] == 'd' and seq[1] == 'o' and seq[2] == 'd':
        dod += 1
    elif seq[0] == 'd' and seq[1] == 'o' and seq[2] == 'g':
        dog += 1
    elif seq[0] == 'g' and seq[1] == 'o' and seq[2] == 'd':
        god += 1
    elif seq[0] == 'g' and seq[1] == 'o' and seq[2] == 'g':
        gog += 1
    elif seq[0] == 'c' and seq[1] == 'a' and seq[2] == 't':
        cat += 1
    else:
        unexpected += 1

# all of the 5 options should show up betwen 1850 and 2150 99% of the time.
# most of the time they will be around 2000
print("dod", dod, 1850 < dod < 2150)
print("dog", dog, 1850 < dog < 2150)
print("god", god, 1850 < god < 2150)
print("gog", gog, 1850 < gog < 2150)
print("cat", cat, 1850 < cat < 2150)
# and only these 5 should happen -- nothign unexpected should happen.
print("unexpected", unexpected, unexpected==0)

print()
print('TEST grammar 4')
# read a grammar from file. the CFg is just G3 again.
G4 = grammar_from_file("test_cfg.csv")
dod = 0
dog = 0
god = 0
gog = 0
cat = 0
unexpected = 0
for i in range(10000):
    seq = generate(G4)
    if len(seq) != 3:
        unexpected += 1
    elif seq[0] == 'd' and seq[1] == 'o' and seq[2] == 'd':
        dod += 1
    elif seq[0] == 'd' and seq[1] == 'o' and seq[2] == 'g':
        dog += 1
    elif seq[0] == 'g' and seq[1] == 'o' and seq[2] == 'd':
        god += 1
    elif seq[0] == 'g' and seq[1] == 'o' and seq[2] == 'g':
        gog += 1
    elif seq[0] == 'c' and seq[1] == 'a' and seq[2] == 't':
        cat += 1
    else:
        unexpected += 1

# all of the 5 options should show up betwen 1850 and 2150 99% of the time.
# most of the time they will be around 2000
print("dod", dod, 1850 < dod < 2150)
print("dog", dog, 1850 < dog < 2150)
print("god", god, 1850 < god < 2150)
print("gog", gog, 1850 < gog < 2150)
print("cat", cat, 1850 < cat < 2150)
# and only these 5 should happen -- nothign unexpected should happen.
print("unexpected", unexpected, unexpected==0)




#OVERALL EXPECTED OUTPUT -- note the test grammars 3 and 4 might have different numbers!
'''

TEST grammar 1
1 a
1 a
1 a
1 a
1 a
1 a
1 a
1 a
1 a
1 a

TEST grammar 2
8 abcddcba
8 abcddcba
8 abcddcba
8 abcddcba
8 abcddcba
8 abcddcba
8 abcddcba
8 abcddcba
8 abcddcba
8 abcddcba
['a', 'b', 'c', 'd', 'd', 'c', 'b', 'a']

TEST grammar 3
dod 1968 True
dog 1972 True
god 2050 True
gog 2039 True
cat 1971 True
unexpected 0 True

TEST grammar 4
dod 2062 True
dog 2074 True
god 1922 True
gog 1970 True
cat 1972 True
unexpected 0 True

'''