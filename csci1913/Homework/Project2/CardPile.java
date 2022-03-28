public class CardPile {

    private Card topCard;
    private int numCards = 1;

    public CardPile(Card topCard) {
        this.topCard = topCard;
    }

    public boolean canPlay(Card card) {
        if (card != null) {
            if (topCard.getRankNum() <= card.getRankNum() || topCard.getSuitName().equals(card.getSuitName())) {
                return true;
            }
        }
        return false;
    }

    public void play(Card card) {
        if (canPlay(card) && card != null) {
            topCard = card;
            numCards++;
        } else {
            System.out.println("Illegal move detected!");
        }
    }

    public int getNumCards() {
        return numCards;
    }

    public Card getTopCard() {
        return topCard;
    }

}
