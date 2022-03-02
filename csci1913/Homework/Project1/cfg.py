import csv
from tempfile import tempdir
from my_rng import random_choice, set_seed
import my_rng
import time
set_seed(int(time.time()))

def new_grammar():
    return {}

def add_rule(grammar, left, right):
    if left in grammar:
        grammar[left].append(right.split())
    else:
        grammar[left] = [right.split()]

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

def grammar_from_file(filename):
    grammar = new_grammar()
    reader = csv.DictReader(open(filename))
    for row in reader:
        add_rule(grammar, row["variable"], row["replacement"])
    print(generate(grammar))