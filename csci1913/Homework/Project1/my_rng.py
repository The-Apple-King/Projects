'''
  CSCI 1913
  Project 1
  Author: Owen Swearingen
'''

import time
import math
seed = 0

#param int
#sets the global variable seed to whatever number is inputted
def set_seed(new_seed):
    global seed
    seed = new_seed

#uses the global variable seed and does a math function on it in order to create a psuedo random number
def next():
    global seed
    seed = (math.pow(7, 5)*seed)%(math.pow(2, 31) -1)
    return seed

#param min int and max int
#uses global seed and next to find a random number within the range of min - max
def next_int(min, max):
        global seed
        return (next()%(max-min+1))+min

#param list
#uses max of list and zero as min and max and cals next int to randomly select an item in the list
def random_choice(seq):
    return seq[int(next_int(0,(len(seq)-1)))]


#uses the random functions above to select random numbers.
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
if __name__ == "__main__":
    main()
