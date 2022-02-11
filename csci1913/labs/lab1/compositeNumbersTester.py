# If you can get this file to run and produce the correct output,
# then you shouldn't have much trouble with the autograder (With the possible exception of the third required
# function -- that one isn't tested here!)

# You should be able to run this file as-is, without any modifications, by putting it in the same folder
# as the file `compositeNumbers.py` that you wrote for lab01

# This is an import statement -- it runs the file "compositeNumbers.py" and then extracts definitions from the resulting
# environment
from compositeNumbers import num_divisors, is_highly_composite_number
print("This should be the first print")

print(num_divisors(-10))      # 0
print(num_divisors(10))       # 4
print(num_divisors(0))        # 0
print(num_divisors(-1))       # 0
print(num_divisors(1))        # 1
print(num_divisors(-2))       # 0
print(num_divisors(2))        # 2
print(num_divisors(-200))     # 0
print(num_divisors(200))      # 12
print(num_divisors(-720720))  # 0
print(num_divisors(720720))   # 240
# This one can take a little longer, but it shouldn't be more than a few seconds
print(num_divisors(27072097))  # 4

print("Start is_highly_composite_number tests")
print(is_highly_composite_number(-60))   # False
print(is_highly_composite_number(-10))   # False
print(is_highly_composite_number(0))     # False
print(is_highly_composite_number(1))     # True
print(is_highly_composite_number(2))     # True
print(is_highly_composite_number(3))     # False
print(is_highly_composite_number(4))     # True
print(is_highly_composite_number(5))     # False
print(is_highly_composite_number(6))     # True
print(is_highly_composite_number(8))     # False
print(is_highly_composite_number(12))    # True
print(is_highly_composite_number(24))    # True
print(is_highly_composite_number(36))    # True
print(is_highly_composite_number(48))    # True
print(is_highly_composite_number(60))    # True
print(is_highly_composite_number(120))   # True
print(is_highly_composite_number(96))    # False
print(is_highly_composite_number(5040))  # True

'''Answer key for this file:

This should be the first print
0
4
0
0
1
0
2
0
12
0
240
4
Start is_highly_composite_number tests
False
False
False
True
True
False
True
False
True
False
True
True
True
True
True
True
False
True

'''
