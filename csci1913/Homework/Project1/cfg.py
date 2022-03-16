'''
  CSCI 1913
  Project 1
  Author: Owen Swearingen
'''

import csv
import my_rng
import time
my_rng.set_seed(int(time.time()))


#returns an empty dictionary
def new_grammar():
    return {}

#param dictionary, key, text
#adds a list of all the words in the text separated by spaces to the dictionary with key left
def add_rule(grammar, left, right):
    if left in grammar:
        grammar[left].append(flatten(right))
    else:
        grammar[left] = [flatten(right)]

def flatten(lst):
    output =[]
    for sentence in lst:
        for word in sentence.split():
            output.append(word)
    return output

#param dictionary
#runs through a list sentence and replaces all replaceable words in the right spot
def generate(grammar):
    sentence = ['Start']
    modified = True
    while modified:
        modified = False
        for i in range(len(sentence)):
            if(sentence[i] in grammar): #checks if the thing needs to be replaced
                modified = True 
                temp = my_rng.random_choice(grammar[sentence[i]])
                #temp = my_rng.random_choicem grammar[sentence[i]]
                sentence.pop(i)
                for x in range(len(temp)):
                    sentence.insert(i+x, temp[x])
    return sentence

#param string of filename
#reads the csv file and calls add_rule to add them to the dictionary
def grammar_from_file(filename):
    grammar = new_grammar()
    reader = csv.DictReader(open(filename))
    for row in reader:
        add_rule(grammar, row["variable"], [row["replacement"]])
    return grammar