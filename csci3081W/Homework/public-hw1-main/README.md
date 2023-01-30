# public-hw1

CSci 3081W: Program Design and Development <br />
Homework 1 – C++ Basics<br />
Spring 2023<br />

# Due Date: 
Full Assignment - Sunday, February 12th, 2023, before 11:59 pm. 

# Overview: 
This homework will be a set of problems that you answer with code in C++. The concepts in every problem are covered in the Zybooks assignments. 

# Instructions:  
This homework is a coding assignment.  To receive credit for this homework, you will need to submit a set of .cc files to Gradescope. Please do not zip them! This is an individual assignment. Feel free to discuss with your classmates but code sharing of any kind is not allowed and will result in a zero on the assignment.

# Problem 1: Passwords (10 pts)

In a file named passwords_a.cc, write a C++ program that takes in user input a string representing a password and an integer representing a user's age.  Check if the password is at least 8 characters long and if the user's age is at least 18. If the password is at least 8 characters long and the user's age is at least 18, print "Access granted." If the password is less than 8 characters long and the user's age is at least 18, print "Password too short, access denied." If the password is at least 8 characters long and the user's age is less than 18, print "Too young, access denied." If neither condition is met, print "Access denied".

In a file named passwords_b.cc, write a C++ program that takes in user input two strings representing passwords and checks if they match using string comparison methods (section 8.4.1). If the passwords match, print "passwords match" and if they don't match, print "passwords do not match".

Submission: Submit two files to Gradescope for this problem: passwords_a.cc and passwords_b.cc

# Problem 2: Fruit (15 pts)
We have given you a file named fruit_class.cc where you need to define a Fruit class and complete main() based on the given instructions (inline comments).
Submission: Submit one file to Gradescope for this problem: fruit_class.cc

# Problem 3: Ducks (75 pts)
## Ducks in a row (15 pts)
We have given you files named duck.cc and main.cc that contain instructions for the creation of a Duck class with some attributes, as well as a partially filled main function that contains a vector of a few ducks. Your job is to complete the Duck class as well as sort the ducks based on their coolness in the main method. (Hint: Look at C++ standard sort)
## Big Three (10 pts)
For this part of the homework, you will build upon your duck.cc file. You must add a destructor, copy constructor, and copy assignment operator. You must also explain what each one does and how they differ from each other and the default constructor in your own words. (use inline comments for your explanations)
## More Ducks (30 pts)
We will now refactor our Duck class to be an abstract parent class (Duck) with child classes (Mallard, Canvasback, and Rubber).<br />
Each class should be its own file (duck.cc, mallard.cc, canvasback.cc, and rubber.cc)<br />
	The parent class will have the following pure virtual methods added:<br />
quack: string<br />
display: string<br />
swim: string<br />
fly: string<br />
	The child classes have the following behavior:<br />
Mallard<br />
  quack: prints “Quack!”<br />
  display: prints “I am a Mallard Duck!”<br />
  swim: prints “I can swim!”<br />
  fly: prints “I can fly!”<br />
Canvasback<br />
  quack: prints “Quack!”<br />
  display: prints “I am a Canvasback Duck!”<br />
  swim: prints “I can swim!”<br />
  fly: prints “I can fly!”<br />
Rubber<br />
  quack: prints “Squeak!”<br />
  display: prints “I am a Rubber Duck!”<br />
  swim: prints “I can swim!”<br />
  fly: prints “I can’t fly!”<br />
One of these four added functions can be refactored such that it is not pure virtual anymore. Refactor that function accordingly.<br />
Create an instance of each of the children classes in the main function.<br />
You'll also have to comment out the ducks vector, all the push_backs, and sort from part a. Why? Respond in the comments section in duck.cpp where it says [Response here].<br />
## Duck Extension - Creativity Time (20 pts)
Create five functions that take in two ducks and output something. You get to define the functions however you want. Feel free to add new variables to the ducks in order to complete wanted functionality. In addition to writing the code, comments are required. Comments should not only detail the logic behind the code, but also explain how the different classes and methods interact to create an interesting experience. In the main method, demonstrate each one of your five functions in action. This is your chance to have fun!
Submission: main.cc, duck.cc, mallard.cc, canvasback.cc, and rubber.cc to Gradescope
