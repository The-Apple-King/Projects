import csv
from tempfile import tempdir
from my_rng import random_choice, set_seed
import my_rng
import time
set_seed(int(time.time()))


#returns an empty dictionary
def new_grammar():
    return {}

#param dictionary, key, text
#adds a list of all the words in the text separated by spaces to the dictionary with key left
def add_rule(grammar, left, right):
    for i in right:
        if left in grammar:
            grammar[left].append(i.split())
        else:
            grammar[left] = [i.split()]

#param dictionary
#runs through a list sentence and replaces all replaceable words in the right spot
def generate(grammar):
    sentence = ['Start']
    while "Start" in sentence or "Story" in sentence or "Phrase" in sentence or "Noun" in sentence or "verb" in sentence:
        for i in range(len(sentence)):
            if(sentence[i] in grammar): #checks if the thing needs to be replaced
                temp = random_choice(grammar[sentence[i]])
                sentence.pop(i)
                for x in range(len(temp)):
                    sentence.insert(i+x, temp[x]) 
    return sentence

#param string of filenam
#reads the csv file and calls add_rule to add them to the dictionary
def grammar_from_file(filename):
    grammar = new_grammar()
    reader = csv.DictReader(open(filename))
    for row in reader:
        add_rule(grammar, row["variable"], row["replacement"])