public class SmallestCardAI extends AI {

    public Card getPlay(Hand hand, CardPile cardPile) {
        Card min = hand.get(0);
        for (int i = 1; i < hand.getSize(); i++) {
            if (cardPile.canPlay(hand.get(i))) {
                if (hand.get(i).getRankNum() < min.getRankNum()) {
                    min = hand.get(i);
                }
            }
        }
        return min;
    }

    public String toString() {
        return ("Smallest Card AI");
    }
}
