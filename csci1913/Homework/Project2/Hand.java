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

    public int getSize() {
        return hand.length;
    }

    public Card get(int i) {
        if (i < hand.length && i >= 0) {
            return hand[i];
        } else {
            System.out.println("Invalid hand index!");
            return hand[0];
        }
    }

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
