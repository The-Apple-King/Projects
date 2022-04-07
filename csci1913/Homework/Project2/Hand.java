//Project 2
//Owen Swearingen
public class Hand {

    private Card[] hand;
    private Deck drawfrom;

    public Hand(Deck deck, int size) {
        hand = new Card[size];
        for (int i = 0; i < size; i++) {
            hand[i] = deck.draw();
        }
         drawfrom = deck;
    }

    /**
     * 
     * @return returns size of the hand
     */
    public int getSize() {
        return hand.length;
    }

    /**
     * 
     * @param i the location in the hand
     * @return returns the card at that location
     */
    public Card get(int i) {
        if (i < hand.length && i >= 0) {
            return hand[i];
        } else {
            System.out.println("Invalid hand index!");
            return hand[0];
        }
    }

    /**
     * 
     * @param card the card to be removed
     * @return true if card removed successfully
     */
    public boolean remove(Card card) {
        for (int i = 0; i < hand.length; i++) {
            if (hand[i].equals(card)) {
                hand[i] = drawfrom.draw();
                return true;
            }
        }
        return false;
    }

}
