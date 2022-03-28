// Owen Swearingen
//Homework 4A
//Ecode a string using a key and return the string 

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

char encryptChar(char phrase, char key, char letters[26]);
int indexOf(char c, char letters[26]);

int main(){

    //create data
    string phrase;
    string keyword;
    char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    cout << "Enter the phrase: ";
    cin >> phrase;
    cout << "Enter the keyword: ";
    cin >> keyword;
    

    //loop through and create a new string
    for (size_t i = 0; i < phrase.length(); i++)
    {
        int j = i%(keyword.length());
        phrase[i] = encryptChar(toupper(phrase[i]),toupper(keyword[j]), letters);

    }

    // output data
    cout << "Encrypted phrase: " + phrase;
    
}

/**
 * @brief takes in two characters and 
 * encrypts the first using the second as a key
 * 
 * @param phrase the char to be encrypted
 * @param key the character key to encryption
 * @param letters char array of all the letters of the alphabet
 * @return char returns modified phrase
 */
char encryptChar(char phrase, char key, char letters[26]){
    return letters[((indexOf(phrase, letters)+indexOf(key, letters))%26)];
}

/**
 * @brief finds the index location of the character
 * 
 * @param c the character
 * @param letters the char array containing alphabet
 * @return int the index of c in letters or -1 if it isn't a letter
 */
int indexOf(char c, char letters[26]){
    for (size_t i = 0; i < 26; i++)
    {
        if(letters[i] == c){
            return i;
        }
    }
    return -1;
}