//Project 2
//Owen Swearingen
public class BiggestCardAI extends AI {

    /**
     * gets which card to play 
     * @param hand the hand the ai choses from
     * @param cardPile the top card the ai needs to play on top of
     * @return returns the card to play or null if theres nothing to play
     */
    public Card getPlay(Hand hand, CardPile cardPile) {
        Card max = null;
        for (int i = 0; i < hand.getSize(); i++) {
            Card cur = hand.get(i);
            if (cardPile.canPlay(cur)) {
                if (max == null) {
                    max = cur;
                } else if (cur.getRankNum() > max.getRankNum()) {
                    max = cur;
                }
            }
        }
        if (cardPile.canPlay(max)) {
            return max;
        }
        return null;
    }

    public String toString() {
        return ("Biggest Card AI");
    }
}
