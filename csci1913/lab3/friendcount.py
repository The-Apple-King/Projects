import csv

def friends_count(file):
    friends_dict = {}
    reader = csv.DictReader(open(file))
    for row in reader:
        friends_dict[row["Name1"]] = friends_dict.get(row["Name1"], 0) + 1
        friends_dict[row["Name2"]] = friends_dict.get(row["Name2"] , 0) + 1
    return friends_dict


def oldest_friend(file):
    friends_dict = {}
    days_dict = {}
    reader = csv.DictReader(open(file))
    for row in reader:
        if(days_dict.get(row["Name1"], 0) < int(row["friendship_days"])):
            days_dict.update({row["Name1"]: int(row["friendship_days"])})
            friends_dict[row["Name1"]] = row["Name2"]
        if(days_dict.get(row["Name2"], 0) < int(row["friendship_days"])):
            days_dict.update({row["Name2"]: int(row["friendship_days"])})
            friends_dict[row["Name2"]] = row["Name1"]
            
    return friends_dict

def oldest_people(file):
    maxAge = 0
    Age = set()
    reader = csv.DictReader(open(file))
    for row in reader:
            if(maxAge < int(row["Age1"])):
                maxAge = int(row["Age1"])
                Age.clear()
                Age.add(row["Name1"])
            if(maxAge < int(row["Age2"])):
                maxAge = int(row["Age2"])
                Age.clear()
                Age.add(row["Name2"])
            if(int(row["Age1"]) == maxAge):
                Age.add(row["Name1"])
            if(int(row["Age2"]) == maxAge):
                Age.add(row["Name2"])
    return Age
        
        

def error_detect_age(file): 
    friends_dict = {}
    reader = csv.DictReader(open(file))
    for row in reader:
        if(friends_dict.get(row["Name1"], 0) != int(row["Age1"])):
            if(friends_dict.get(row["Name1"], 0) == 0):
                friends_dict.update({row["Name1"]: int(row["Age1"])})
            else:
                return False
        if(friends_dict.get(row["Name2"], 0) < int(row["Age2"])):
            if(friends_dict.get(row["Name2"], 0) == 0):
                friends_dict.update({row["Name2"]: int(row["Age2"])})
            else:
                return False
    return True