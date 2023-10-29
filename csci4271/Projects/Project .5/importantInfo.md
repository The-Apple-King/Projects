vulnerability is a safety vulnerability
1 planned vulnerability 3 known vulnerabilites


describing ideas will give partial credit
fully explaining one will give full credit

The idea is to audit the code, write a report on it then create an attack.

mentioned unexpected or broken bcbasic code to work
there are exploits that work outside gdb

written
report including 2–4 pages
one-inch margins
times new roman
10 points high
double spaced
should include a figure
labeled with your name and UMN email address, as well as the
names and addresses of the other members of your group.


As a final appendix to your report (a separate last page), write between one sentence
and one page describing the software and/or AI tools that assisted you in any of the phases
of the project. If you chose not to use any special tools, this could be a single sentence like
“The only tools I used were GDB and the spellchecker in Google Docs.” But we would like
to hear more details if you found other tools to be useful. We won’t reduce the credit you
get for the body of the report if you say, to take an extreme example, that you were able
to get a large language model to do the whole project for you by using the right prompts.
But we are interested in these information to inform how we adjust the project for future
versions of the course.


 the code also asssumes in the standard library interfaces it uses that
"long" and "unsigned long" are sufficient to hold these.


### issues?

pointer to pointer to code

variables are dealt with could mess with that mem

simple type, both strings and return val
we could also maybe overflow to make the system think its the wrong var type

scan line does something when input too long

450 insert statement has the most comments inside the code, and it has something to do with pointers to pointers to code.

interp looks to be the most dangerous


952 less important arrays work like arraylists and have a growing amount of allocated mem

copying an array to itself is a no-op, could use for a slide?

theres a debugging tool built in i don't know if it matters

1313 there is opcodes, idk if we can overwrite but they activate functions from there. 


array copy has a bug where it will free before doing anything

array pointers are stored in the same spot as an integer is so using an int we could somehow change where the pointer points for an array.

## change arr pointer to location of instructions and then modify them using array?
    looking through arr copy, sets the lhs to an arr before checking anything
    maybe two ints, if we somehow run an arr_copy on two ints it would work the way we want.

    if we set the lhs to an int that has a pointer to the same val as the array then it will just set the type to array 
    and do nothing else

2d array ???

    1 a[0] = 0
    2 b = 0
    3 b = a
    4 println a

    using this we can get the mem address for a into the val of b

# if we use the free bug on an array the next array will be for the same mem location
this is consistent .


mem allocated bottom to top, each int 192 bits apart?
if we set the sam var to a val it adds 96 to the space between vars


loops do not affect allocated data,

println seems to separate data at random distances

1. by setting array = to itself we free all array mem
2. each time you set a var it will increase the size of the variable
3. any statement i.e. println will be stored as a variable that can be accessed later
    repeatedly printing will increase the size of the variable
4. rem will actually affect code by creating a var
5. we can print the memory location of arrays by setting an int to an array without a int val


how program executes,
check we can open file,
once opened we use a pointer to find all new lines and replace them with 0
we parse line, any spaces are ignored, then we check for a comment, then it checks for a line number, 
if there is a number we check valid then continue
else we set one sequentially
parse line doesn't check line order
# we check for a comment again? after a line number 504
then we set the line number to the statement

what does int_const do

we then resolve jumps,
loop through each statement, look for the line number if == then return statement,
if bigger return 0, once 0 is returned we get a fail that line isn't found

single letter variables, bad practice