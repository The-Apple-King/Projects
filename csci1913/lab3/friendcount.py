import csv

def friends_count(file):
    friends_dict = {}
    reader = csv.DictReader(open(file))
    for row in reader:
        #get returns either the value or default so we return dict[name] + 1
        friends_dict[row["Name1"]] = friends_dict.get(row["Name1"], 0) + 1
        friends_dict[row["Name2"]] = friends_dict.get(row["Name2"] , 0) + 1
    return friends_dict


def oldest_friend(file):
    #uses two dictionaries days_dict saves name and their longest friendship
    #friends_dict saves the two names together
    friends_dict = {}
    days_dict = {}
    reader = csv.DictReader(open(file))
    for row in reader:
        #name 1 checks
        if(days_dict.get(row["Name1"], 0) < int(row["friendship_days"])):
            days_dict.update({row["Name1"]: int(row["friendship_days"])})
            friends_dict[row["Name1"]] = row["Name2"]
        #name 2 checks
        if(days_dict.get(row["Name2"], 0) < int(row["friendship_days"])):
            days_dict.update({row["Name2"]: int(row["friendship_days"])})
            friends_dict[row["Name2"]] = row["Name1"]
            
    return friends_dict

def oldest_people(file):
    #uses maxAge to save the max age
    #uses set to save names
    maxAge = 0
    Age = set()
    reader = csv.DictReader(open(file))
    for row in reader:
        #name1 checks
        if(maxAge < int(row["Age1"])):
            maxAge = int(row["Age1"])
            Age.clear()
            Age.add(row["Name1"])
        #name2 checks
        if(maxAge < int(row["Age2"])):
            maxAge = int(row["Age2"])
            Age.clear()
            Age.add(row["Name2"])
        #checks if there are any with the same age
        if(int(row["Age1"]) == maxAge):
            Age.add(row["Name1"])
        if(int(row["Age2"]) == maxAge):
            Age.add(row["Name2"])
    return Age
        
        

def error_detect_age(file): 
    #uses friends_dict to save ages and test if they are equal each time they are called
    friends_dict = {}
    reader = csv.DictReader(open(file))
    for row in reader:
        #name1 checks if age isn't the same
        if(friends_dict.get(row["Name1"], 0) != int(row["Age1"])):
            #checks if its the first time that we set this age
            if(friends_dict.get(row["Name1"], 0) == 0):
                #sets the age in dictionary
                friends_dict.update({row["Name1"]: int(row["Age1"])})
            else:
                return False
                #repeats for name2
        if(friends_dict.get(row["Name2"], 0) < int(row["Age2"])):
            if(friends_dict.get(row["Name2"], 0) == 0):
                friends_dict.update({row["Name2"]: int(row["Age2"])})
            else:
                return False
    return True