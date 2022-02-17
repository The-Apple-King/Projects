def unsorted_list_to_dict(list):
    dictionary = {}
    for x in list:
        dictionary[x[0]] = x[1]
    return dictionary

def is_sorted(list):
    preceed = 0
    for x in list:
        if x[1] >= preceed:
            preceed = x[1]
        else:
            return False
    return True

def unsorted_get(unsorted_assoc, key, dflt):
    for x in unsorted_assoc:
        if (x[1] == key):
            return x[0]
    return dflt

def unsorted_put(unsorted_assoc, key, value):
    tup = (value, key)
    for x in range(len(unsorted_assoc)):
        if (unsorted_assoc[x][1] == key):
            unsorted_assoc[x]= tup
    unsorted_assoc.append(tup)
    return unsorted_assoc

def sorted_get(sorted_assoc, key, dflt):
    max = len(sorted_assoc)
    min = 0
    for mid in range(len(sorted_assoc)):
        mid = (min + max)//2
        if (sorted_assoc[mid][1] > key):
            min = mid
        if (sorted_assoc[mid][1] < key):
            max = mid
        if (sorted_assoc[mid][1] == key):
            return sorted_assoc[mid][0]
    return dflt

def sorted_put(sorted_assoc, key, value):
    tup = (value, key)
    max = len(sorted_assoc)
    min = 0
    for mid in range(len(sorted_assoc)):
        mid = (min + max)//2
        if (sorted_assoc[mid][1] > key):
            min = mid
        if (sorted_assoc[mid][1] < key):
            max = mid
        if (sorted_assoc[mid][1] == key):
            sorted_assoc[mid] = tup
    return sorted_assoc
