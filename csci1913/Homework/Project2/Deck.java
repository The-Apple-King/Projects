public class Deck {
    private int deckSize = 52;
    private Card[] deck = new Card[52];

    public Deck() {
        int count = 0;
        for (int i = 1; i < 5; i++) {
            for (int j = 1; j < 14; j++) {
                deck[count] = new Card(j, i);
                count++;
            }
        }
    }
    

    public void shuffle() {
        for (int i = 0; i < deck.length; i++) {
            int k = (int) Math.random() * i;
            Card temp = deck[i];
            deck[i] = deck[k];
            deck[k] = temp;
        }
        deckSize = 52;
    }

    /**
     * returns card decrements deckSize
     * @return card from the top of the deck
     */
    public Card draw() {
        if (deckSize > 0) {
            deckSize--;
            return deck[deckSize];
        } else {
            shuffle();
            deckSize--;
            return deck[deckSize];
        }
    }

    /**
     * 
     * @return deckSize
     */
    public int cardsRemaining() {
        return deckSize;
    }

    /**
     * 
     * @return true if empty else false
     */
    public boolean isEmpty() {
        if (deckSize == 0) {
            return true;
        }
        return false;
    }
}
