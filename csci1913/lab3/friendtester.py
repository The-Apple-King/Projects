# This file will help you test your friendcount.py functions.
# Note -- since we use dictionaries and sets here (which have no inherent ordering) jsut checking if your printout is right can be a misleading way to test this code.
#         as such I've added a more direct == test -- you should get a bunch of "true" if the tests are running right.
# Also note -- I've split the import statements up to make it easier for you to test one function at a time.

from friendcount import friends_count
result = friends_count('friends_file_1.csv')
expected = {'Kate': 2, 'Sam': 1, 'Tory': 1, 'Wendy': 2, 'Tom': 1, 'Bob': 1, 'Liam': 1, 'Terry': 1, 'Anna': 1, 'Nick': 1, 'kitty': 1, 'Jerry': 1, 'extreme': 1, 'sports': 1}
print(result == expected) # Expected to print True
#print(result)

result = friends_count('friends_file_2.csv')
expected = { }
print(result == expected) # Expected to print True
#print(result)

result = friends_count('friends_file_3.csv')
expected = {'Toby': 1, 'Harry': 1, 'Kate': 1, 'Sam': 1, 'Wendy': 2, 'Tom': 1, 'Bob': 1, 'Liam': 1, 'Terry': 1, 'Anna': 1, 'Nick': 1, 'kitty': 1, 'Jerry': 1, 'extreme': 1, 'sports': 1, 'calvin': 1, 'kelvin': 1}
print(result == expected) # Expected to print True
#print(result)

result = friends_count('friends_file_4.csv')
expected = {'a': 1, 'h': 2, 'b': 1, 'i': 1, 'c': 1, 'j': 1, 'd': 1, 'k': 1, 'e': 1, 'l': 1, 'f': 1, 'm': 1, 'g': 1, 'n': 1, 'o': 1}
print(result == expected) # Expected to print True
#print(result)

result = friends_count('friends_file_5.csv')
expected = {'Correy': 1, 'Prober': 1, 'Almeta': 1, 'Lia': 1, 'Kelly': 1, 'Wallis': 1, 'Melisent': 2, 'Jacqui': 1, 'Dede': 1, 'Mozelle': 1, 'Marsiella': 1, 'Virgin': 1, 'Kial': 1, 'Sikorski': 1, 'Joelly': 1, 'Cleo': 1, 'Marcelline': 1, 'Himelman': 1, 'Lyssa': 1, 'Agle': 1, 'Mureil': 1, 'Alexandr': 1, 'Evaleen': 1, 'Cassius': 1, 'Nicoli': 1, 'Ruvolo': 1, 'Monika': 1, 'Tound': 1, 'Zsa Zsa': 1, 'Sancho': 2, 'Vinita': 1, 'Merell': 1, 'Robinia': 1, 'Burnside': 1, 'Julieta': 1, 'Kiyoshi': 1, 'Eve': 1, 'Bates': 1, 'Sonni': 1, 'Raimondo': 1, 'Alyda': 1, 'Bryna': 1, 'Dolli': 1, 'Blake': 1, 'Fanny': 1, 'Vanni': 1, 'Sabina': 1, 'Arquit': 1, 'Gerianna': 1, 'Crudden': 1, 'Meg': 1, 'Eliathas': 1, 'Josephine': 1, 'Chrystel': 1, 'Bobbi': 1, 'Screens': 1, 'Florencia': 1, 'Nahum': 1, 'Brooks': 1, 'Dreda': 1, 'Corry': 1, 'Bach': 1, 'Kaja': 1, 'Connelly': 1, 'Rozele': 1, 'Oriana': 1, 'Catharine': 2, 'Alwin': 1, 'Shell': 2, 'Munn': 1, 'Alyssa': 1, 'Mallon': 1, 'Ariela': 1, 'Sekofski': 1, 'Kimmy': 1, 'Atonsah': 1, 'Dorice': 2, 'Yam': 1, 'Adele': 1, 'Smitt': 1, 'Willetta': 1, 'Eldrid': 1, 'Frances': 1, 'Buffum': 1, 'Janene': 1, 'Clarice': 1, 'Si': 1, 'Vonny': 1, 'Masao': 1, 'Alex': 1, 'Darian': 1, 'Teddie': 1, 'Felecia': 1, 'Keelia': 1, 'Vilma': 1, 'Reeba': 1, 'Shama': 2, 'Mathilda': 1, 'Lunsford': 1, 'Emilia': 1, 'Dichy': 1, 'Fayre': 1, 'Hutchison': 1, 'Minda': 1, 'Noelyn': 1, 'Quintina': 1, 'Shaver': 1, 'Marcy': 1, 'Adrienne': 1, 'Jacquetta': 1, 'Candy': 2, 'Curren': 1, 'Tatiania': 1, 'Jagir': 1, 'Annabela': 1, 'Letsou': 1, 'Estell': 1, 'Mayeda': 1, 'Lorie': 1, 'Sabella': 2, 'Iseabal': 1, 'Maiah': 1, 'Susan': 1, 'McClimans': 1, 'Lexine': 1, 'Stacy': 1, 'Tilly': 1, 'Klotz': 1, 'Justinn': 1, 'Lory': 1, 'Atlanta': 1, 'Emanuel': 1, 'Sue': 1, 'Brodench': 1, 'Lanna': 1, 'Giff': 1, 'Etta': 1, 'Wenoa': 1, 'Rhoda': 1, 'Mendez': 1, 'Odessa': 1, 'Campball': 1, 'Amelia': 1, 'Vacuva': 1, 'Ebonee': 1, 'Dielu': 1, 'Kayla': 1, 'Travax': 1, 'Peri': 1, 'Katleen': 1, 'Borrell': 1, 'Deloria': 1, 'Nerita': 1, 'Kassey': 1, 'Schonfeld': 1, 'Kate': 1, 'Middleton': 1, 'Randa': 1, 'Pond': 1, 'Corly': 1, 'Nunci': 1, 'Vary': 1, 'Tani': 1, 'Weitman': 1, 'Alexine': 1, 'Kalinda': 1, 'Dianemarie': 1, 'Martsen': 1, 'Ezmeralda': 1, 'Fosque': 1, 'Roz': 1, 'Nore': 1, 'Jordan': 1, 'Chinua': 1, 'Lita': 1, 'Maples': 1, 'Hayley': 1, 'Burch': 1, 'Riannon': 1, 'Tyson': 1, 'Agathe': 1, 'Alcott': 1, 'Karina': 1, 'Gaspard': 1, 'Anica': 1, 'Rustice': 1, 'Annice': 1, 'Netty': 1, 'Meriel': 1, 'Leopold': 1, 'Rochette': 1, 'Swanhildas': 1}
print(result == expected) # Expected to print True
#print(result)

result = friends_count('friends_file_6.csv')
expected = {'1': 1, '16': 1, '2': 1, '15': 1, '3': 1, '14': 1, '4': 1, '13': 1, '5': 1, '12': 1, '6': 1, '11': 1, '7': 1, '10': 1, '8': 1, '9': 1}
print(result == expected) # Expected to print True
#print(result)

from friendcount import oldest_friend
result = oldest_friend('friends_file_1.csv')
expected = {'Kate': 'Sam', 'Sam': 'Kate', 'Tory': 'Kate', 'Wendy': 'Bob', 'Tom': 'Wendy', 'Bob': 'Wendy', 'Liam': 'Terry', 'Terry': 'Liam', 'Anna': 'Nick', 'Nick': 'Anna', 'kitty': 'Jerry', 'Jerry': 'kitty', 'extreme': 'sports', 'sports': 'extreme'}
print(result == expected) # Expected to print True
#print(result)

result = oldest_friend('friends_file_2.csv')
expected = { }
print(result == expected) # Expected to print True
#print(result)

result = oldest_friend('friends_file_3.csv')
expected = {'Toby': 'Harry', 'Harry': 'Toby', 'Kate': 'Sam', 'Sam': 'Kate', 'Wendy': 'Bob', 'Tom': 'Wendy', 'Bob': 'Wendy', 'Liam': 'Terry', 'Terry': 'Liam', 'Anna': 'Nick', 'Nick': 'Anna', 'kitty': 'Jerry', 'Jerry': 'kitty', 'extreme': 'sports', 'sports': 'extreme', 'calvin': 'kelvin', 'kelvin': 'calvin'}
print(result == expected) # Expected to print True
#print(result)

result = oldest_friend('friends_file_4.csv')
expected = {'a': 'h', 'h': 'a', 'b': 'i', 'i': 'b', 'c': 'j', 'j': 'c', 'd': 'k', 'k': 'd', 'e': 'l', 'l': 'e', 'f': 'm', 'm': 'f', 'g': 'n', 'n': 'g', 'o': 'h'}
print(result == expected) # Expected to print True
#print(result)

result = oldest_friend('friends_file_5.csv')
expected = {'Correy': 'Prober', 'Prober': 'Correy', 'Almeta': 'Lia', 'Lia': 'Almeta', 'Kelly': 'Wallis', 'Wallis': 'Kelly', 'Melisent': 'Annice', 'Jacqui': 'Melisent', 'Dede': 'Mozelle', 'Mozelle': 'Dede', 'Marsiella': 'Virgin', 'Virgin': 'Marsiella', 'Kial': 'Sikorski', 'Sikorski': 'Kial', 'Joelly': 'Cleo', 'Cleo': 'Joelly', 'Marcelline': 'Himelman', 'Himelman': 'Marcelline', 'Lyssa': 'Agle', 'Agle': 'Lyssa', 'Mureil': 'Alexandr', 'Alexandr': 'Mureil', 'Evaleen': 'Cassius', 'Cassius': 'Evaleen', 'Nicoli': 'Ruvolo', 'Ruvolo': 'Nicoli', 'Monika': 'Tound', 'Tound': 'Monika', 'Zsa Zsa': 'Sancho', 'Sancho': 'Netty', 'Vinita': 'Merell', 'Merell': 'Vinita', 'Robinia': 'Burnside', 'Burnside': 'Robinia', 'Julieta': 'Kiyoshi', 'Kiyoshi': 'Julieta', 'Eve': 'Bates', 'Bates': 'Eve', 'Sonni': 'Raimondo', 'Raimondo': 'Sonni', 'Alyda': 'Bryna', 'Bryna': 'Alyda', 'Dolli': 'Blake', 'Blake': 'Dolli', 'Fanny': 'Vanni', 'Vanni': 'Fanny', 'Sabina': 'Arquit', 'Arquit': 'Sabina', 'Gerianna': 'Crudden', 'Crudden': 'Gerianna', 'Meg': 'Eliathas', 'Eliathas': 'Meg', 'Josephine': 'Chrystel', 'Chrystel': 'Josephine', 'Bobbi': 'Screens', 'Screens': 'Bobbi', 'Florencia': 'Nahum', 'Nahum': 'Florencia', 'Brooks': 'Dreda', 'Dreda': 'Brooks', 'Corry': 'Bach', 'Bach': 'Corry', 'Kaja': 'Connelly', 'Connelly': 'Kaja', 'Rozele': 'Oriana', 'Oriana': 'Rozele', 'Catharine': 'Alwin', 'Alwin': 'Catharine', 'Shell': 'Vary', 'Munn': 'Shell', 'Alyssa': 'Mallon', 'Mallon': 'Alyssa', 'Ariela': 'Sekofski', 'Sekofski': 'Ariela', 'Kimmy': 'Atonsah', 'Atonsah': 'Kimmy', 'Dorice': 'Janene', 'Yam': 'Dorice', 'Adele': 'Smitt', 'Smitt': 'Adele', 'Willetta': 'Eldrid', 'Eldrid': 'Willetta', 'Frances': 'Buffum', 'Buffum': 'Frances', 'Janene': 'Dorice', 'Clarice': 'Si', 'Si': 'Clarice', 'Vonny': 'Masao', 'Masao': 'Vonny', 'Alex': 'Darian', 'Darian': 'Alex', 'Teddie': 'Felecia', 'Felecia': 'Teddie', 'Keelia': 'Vilma', 'Vilma': 'Keelia', 'Reeba': 'Shama', 'Shama': 'Jacquetta', 'Mathilda': 'Lunsford', 'Lunsford': 'Mathilda', 'Emilia': 'Dichy', 'Dichy': 'Emilia', 'Fayre': 'Hutchison', 'Hutchison': 'Fayre', 'Minda': 'Noelyn', 'Noelyn': 'Minda', 'Quintina': 'Shaver', 'Shaver': 'Quintina', 'Marcy': 'Adrienne', 'Adrienne': 'Marcy', 'Jacquetta': 'Shama', 'Candy': 'Curren', 'Curren': 'Candy', 'Tatiania': 'Jagir', 'Jagir': 'Tatiania', 'Annabela': 'Letsou', 'Letsou': 'Annabela', 'Estell': 'Mayeda', 'Mayeda': 'Estell', 'Lorie': 'Sabella', 'Sabella': 'Lorie', 'Iseabal': 'Maiah', 'Maiah': 'Iseabal', 'Susan': 'McClimans', 'McClimans': 'Susan', 'Lexine': 'Stacy', 'Stacy': 'Lexine', 'Tilly': 'Klotz', 'Klotz': 'Tilly', 'Justinn': 'Lory', 'Lory': 'Justinn', 'Atlanta': 'Emanuel', 'Emanuel': 'Atlanta', 'Sue': 'Brodench', 'Brodench': 'Sue', 'Lanna': 'Giff', 'Giff': 'Lanna', 'Etta': 'Wenoa', 'Wenoa': 'Etta', 'Rhoda': 'Mendez', 'Mendez': 'Rhoda', 'Odessa': 'Campball', 'Campball': 'Odessa', 'Amelia': 'Vacuva', 'Vacuva': 'Amelia', 'Ebonee': 'Dielu', 'Dielu': 'Ebonee', 'Kayla': 'Travax', 'Travax': 'Kayla', 'Peri': 'Candy', 'Katleen': 'Borrell', 'Borrell': 'Katleen', 'Deloria': 'Nerita', 'Nerita': 'Deloria', 'Kassey': 'Schonfeld', 'Schonfeld': 'Kassey', 'Kate': 'Middleton', 'Middleton': 'Kate', 'Randa': 'Pond', 'Pond': 'Randa', 'Corly': 'Nunci', 'Nunci': 'Corly', 'Vary': 'Shell', 'Tani': 'Weitman', 'Weitman': 'Tani', 'Alexine': 'Kalinda', 'Kalinda': 'Alexine', 'Dianemarie': 'Martsen', 'Martsen': 'Dianemarie', 'Ezmeralda': 'Fosque', 'Fosque': 'Ezmeralda', 'Roz': 'Nore', 'Nore': 'Roz', 'Jordan': 'Chinua', 'Chinua': 'Jordan', 'Lita': 'Maples', 'Maples': 'Lita', 'Hayley': 'Burch', 'Burch': 'Hayley', 'Riannon': 'Tyson', 'Tyson': 'Riannon', 'Agathe': 'Alcott', 'Alcott': 'Agathe', 'Karina': 'Sabella', 'Gaspard': 'Catharine', 'Anica': 'Rustice', 'Rustice': 'Anica', 'Annice': 'Melisent', 'Netty': 'Sancho', 'Meriel': 'Leopold', 'Leopold': 'Meriel', 'Rochette': 'Swanhildas', 'Swanhildas': 'Rochette'}
print(result == expected) # Expected to print True
#print(result)

result = oldest_friend('friends_file_6.csv')
expected = {'1': '16', '16': '1', '2': '15', '15': '2', '3': '14', '14': '3', '4': '13', '13': '4', '5': '12', '12': '5', '6': '11', '11': '6', '7': '10', '10': '7', '8': '9', '9': '8'}
print(result == expected) # Expected to print True
#print(result)


from friendcount import oldest_people
result = oldest_people('friends_file_1.csv')
expected = {'extreme', 'Jerry'}
print(result == expected) # Expected to print True
#print(result)

result = oldest_people('friends_file_2.csv')
expected = set()
print(result == expected) # Expected to print True
#print(result)

result = oldest_people('friends_file_3.csv')
expected = {'calvin'}
print(result == expected) # Expected to print True
#print(result)

result = oldest_people('friends_file_4.csv')
expected = {'h'}
print(result == expected) # Expected to print True
#print(result)

result = oldest_people('friends_file_5.csv')
expected = {'Vacuva'}
print(result == expected) # Expected to print True
#print(result)

result = oldest_people('friends_file_6.csv')
expected = {'8'}
print(result == expected) # Expected to print True
#print(result)

from friendcount import error_detect_age


result = error_detect_age('friends_file_1.csv')
expected = False
print(result == expected) # Expected to print True
#print("result: ", result)

result = error_detect_age('friends_file_2.csv')
expected = True
print(result == expected) # Expected to print True
#print("result: ", result)

result = error_detect_age('friends_file_3.csv')
expected = False
print(result == expected) # Expected to print True
#print("result: ", result)

result = error_detect_age('friends_file_4.csv')
expected = False
print(result == expected) # Expected to print True
#print("result: ", result)

result = error_detect_age('friends_file_5.csv')
expected = False
print(result == expected) # Expected to print True
#print("result: ", result)

result = error_detect_age('friends_file_6.csv')
expected = True
print(result == expected) # Expected to print True
#print("result: ", result)

