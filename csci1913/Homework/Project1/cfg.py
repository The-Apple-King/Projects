def new_grammer():
    return {}

def add_rule(grammar, left, right):
    if(grammar.comtains(left)):
        grammar[left].append(right)
    else:
        grammar[left] = [right]

def generate(grammar):
    sentence = ""
    for i in grammar.keys():
        sentence += grammar[i]

def grammar_from_file(filename):
