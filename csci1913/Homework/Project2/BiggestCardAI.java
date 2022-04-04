public class BiggestCardAI extends AI {


    public Card getPlay(Hand hand, CardPile cardPile) {
        Card max = hand.get(0);
        for (int i = 1; i < hand.getSize(); i++) {
            if (cardPile.canPlay(hand.get(i))) {
                if (hand.get(i).getRankNum() > max.getRankNum()) {
                    max = hand.get(i);
                }
            }
        }
        return max;
    }

    public String toString() {
        return ("Biggest Card AI");
    }
}
