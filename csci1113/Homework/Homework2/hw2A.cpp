#include <iostream>
#include <stdlib.h>
#include <ctime>

int main(int argc, char const *argv[])
{
    srand(time(0));
    char cont = 'Y';
    int guess = 0;

    while(cont == 'Y'){
        int correctNumber = 1+rand()%9;
        while (guess != correctNumber)
        {
            std::cout << "What is your guess? \n";
            std::cin >> guess;

            if(guess == correctNumber - 1 || guess == correctNumber + 1){
                std::cout << "Close!\n";
            }
            else if (guess < correctNumber - 1)
            {
                std::cout << "Too low!\n";
            }
            else if (guess > correctNumber + 1)
            {
                std::cout << "Too high!\n";
            }
            else if (guess == correctNumber)
            {
                std::cout << "Correct!\n";
                std::cout << "Do you want to play again? [Y or N]: ";
                std::cin >> cont;
                cont = toupper(cont);
            }
        }
        
    }
    return 0;
}


