//Project 2
//Owen Swearingen
public class SmallestCardAI extends AI {

    /**
     * gets which card to play 
     * @param hand the hand the ai choses from
     * @param cardPile the top card the ai needs to play on top of
     * @return returns the card to play or null if theres nothing to play
     */
    public Card getPlay(Hand hand, CardPile cardPile) {
        Card min = null;
        for (int i = 0; i < hand.getSize(); i++) {
            if (cardPile.canPlay(hand.get(i))) {
                if(min == null) {
                    min = hand.get(i);
                } else if(hand.get(i).getRankNum() < min.getRankNum()) {
                    min = hand.get(i);
                }
            }
        }
        if (cardPile.canPlay(min)) {
            return min;
        } else {
            return null;
        }
    }

    public String toString() {
        return ("Smallest Card AI");
    }
}
