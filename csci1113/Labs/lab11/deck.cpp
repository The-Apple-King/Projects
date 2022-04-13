#include <iostream>
#include <string>
using namespace std;

class deck
{
private:
    int cardDeck[52];
    int topCard;

public:
    deck();
    string dealCard();
    void shuffle();
};
void printHand(string *hand, int max);

int main()
{
    deck myCards = deck();
    string hand[4];
    myCards.shuffle();
    for (size_t i = 0; i < 13; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            hand[j] = myCards.dealCard();
        }
        printHand(hand, 4);
    }
}

void printHand(string *hand, int max)
{
    for (size_t i = 0; i < max; i++)
    {
        cout << hand[i] << " ";
    }
    cout << endl;
}

deck::deck()
{
    for (size_t i = 0; i < 52; i++)
    {
        cardDeck[i] = i%13;
    }
    topCard = 51;
}

void deck::shuffle()
{
    srand(time(0));
    for (size_t i = 1; i < 52; i++)
    {
        int j = rand() % i;
        int temp = cardDeck[i];
        cardDeck[i] = cardDeck[j];
        cardDeck[j] = temp;
    }
}

string deck::dealCard()
{
    int val = cardDeck[topCard];
    val = val % 13;
    switch (val)
    {
    case 0:
        topCard--;
        return "A";
        break;
    case 10:
        topCard--;
        return "J";
        break;

    case 11:
        topCard--;
        return "Q";
        break;

    case 12:
        topCard--;
        return "K";
        break;

    default:
        topCard--;
        return to_string(val);
    }
}