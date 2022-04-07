//Project 2
//Owen Swearingen
public class CardPile {

    private Card topCard;
    private int numCards = 1;

    public CardPile(Card topCard) {
        this.topCard = topCard;
    }

    /**
     * 
     * @param card checks if the current card can be played
     * @return true if card can be played
     */
    public boolean canPlay(Card card) {
        if (card != null) {
            return topCard.getRankNum() <= card.getRankNum() || topCard.getSuitNum() == card.getSuitNum();
        }
        return false;
    }

    /**
     *  attemps to play the card if impossible prints illegal move detected
     * @param card card to play
     */
    public void play(Card card) {
        if (canPlay(card) && card != null) {
            topCard = card;
            numCards++;
        } else {
            System.out.println("Illegal move detected!");
        }
    }

    /**
     * 
     * @return number of cards
     */
    public int getNumCards() {
        return numCards;
    }

    /**
     * 
     * @return returns the card at the top of the deck
     */
    public Card getTopCard() {
        return topCard;
    }

}
