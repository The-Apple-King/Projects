import time
import math
seed = 0

def set_seed(new_seed):
    global seed
    seed = new_seed

def next():
    global seed
    seed = (math.pow(7, 5)*seed)%(math.pow(2, 31) -1)

def next_int(min, max):
    global seed
    next()
    return (seed%(max-min))+min

def random_choice(seq):
    return seq[int(next_int(0,(len(seq))))]

def main():
    choice = ''
    while(choice.upper() != 'C'):
        set_seed(int(time.time()))
        next()
        print('''RNG Utility:
        A) Roll a dice
        B) pick a random option
        C) quit
        Enter choice: ''')
        choice = input()
        if(choice.upper() == 'A'):
            print("Enter minimum number: ")
            min = eval(input())
            print("Enter maximum number: ")
            max = eval(input())
            print("Enter how many times: ")
            rolls = eval(input())
            sum = 0
            for i in range(rolls):
                va = next_int(min,max)
                sum += va
                print('roll ', i, ' = ', va)
            print(sum)
        elif(choice.upper() == 'B'):
            print("Enter options or hit enter to pick a random option: ")
            lst = []
            va = input()
            while(len(va) != 0):
                print("Enter options or hit enter to pick a random option: ")
                lst.append(va)
                va = input()
            print(random_choice(lst))
        elif(choice.upper() == 'C' ):
            print('goodbye!')

main()