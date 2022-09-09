# CSCI 1913 Lab 01 Fall 2022
# All assignments should start with a "header comment" like this one.
# it should list what the file is (lab01 fall 2022) and who wrote it (below)
# This will be a standing REQUIREMENT for the whole semester.
# Authors: TODO: FILL YOUR NAME IN
#          TODO: FILL YOUR PARTNERS NAME IN


# NOTE: You should pay attention to how this file is structured -- you'll be making these files on your own after this
# lab -- so you'll want to know about all the "details" (other than correct code) that we expect! The big things to pay
# attention to here is the header comment at the top, and the docstrings (STRINGS on the first line of a function
# describing what the function does) -- this is a formal part of the programming language that is used to document code.

from unittest import TestCase


def num_divisors(n):
    """Given an integer input n, return the number of positive integers that are divisors of n
    (including 1 and itself)"""
    divisors = 0
    for x in range(1, n+1):
        if n%(x) == 0:
            divisors +=1
    return(divisors)
            


# hard to make this NOT work on negative numbers with num_divisors being weird for negatives.
def is_highly_composite_number(n):
    """ an integer n is a highly composite number if and only if it is a positive integer with
    more divisors than any positive interger smaller than it."""
    max_divisors = 0
    test_case = 0
    if n < 0:
        return(False)
    for i in range(n+1):
        test_case = num_divisors(i)
            # final cases \/
        if i == n and test_case > max_divisors:
            return(True)
        if i == n and test_case <= max_divisors:
            return(False)
            #sets max_divisors
        if test_case > max_divisors:
            max_divisors= test_case
        test_case = 0
        

            


# TODO: you need to declare one extra function here
def kluver_cat_name():
    """returns the name of Mr. Kluvers cat"""
    return 'Willow'

# REMINDER: For submission you should have no code outside of functions.
# it can be quite useful **while developing your code** to use print statements
# at the end of this file to run tests (example:)
#TODO: before submitting the code -- delete this.
# but, for the actual submission -- this has to be deleted
