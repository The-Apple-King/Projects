# This program simply reads one data file and prints who is a friend with who else.
# You can use it to get a sense of how the file-reading syntax works.
# I STRONGLY RECOMMEND making sure you understand how this example file works before moving onto your own code.

# Author Daniel Kluver

import csv # You need this import!

# For this to works you will need the csv files to be in the same folder as your python code.
# The "reader" object this creates can be treated like a sequence of dictionaries except:
# * You can only loop over it (len, in, [] and the other sequence syntax don't work ONLY LOOPING)
# * You can only loop over it ONCE before you have to reopen the file (redo this line)

reader = csv.DictReader(open("C:/Users/TheAppleKing/Documents/school/Programs/repo-swear041/csci1913/lab3/friends_file_1.csv"))

# You loop over it just like anything else in python -- the DictReader just takes care of all the details for you
for row in reader:
    # each row is a dictionary -- (technically a specialized dictionary called OrderedDict which remembers an order to
    # keys in the dictionary but you can ignore that detail)
    print(row["Name1"], "is a friend with", row["Name2"])
    # The keys of the "row" dictionary are the headers of the CSV file, so the row["Name1"] is the name1 value for this row.

# Note -- you CANNOT loop twice without "reopening" the file
for row in reader:
    print("This doesn't print because you can't loop over a reader object twice!")