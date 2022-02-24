def deep_sum(lst_of_lists_and_nums):
    total =0
    for elem in lst_of_lists_and_nums:
        if isinstance(elem, list):
            total += deep_sum(elem)
        else:
            total += elem
    return total
    
    

x = [1, [2, 3], 4, [1, [3, 2], [4, [4, 2, [1]]], 3], 1, [2]]
print(deep_sum(x))