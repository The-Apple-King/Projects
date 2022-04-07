//Project 2
//Owen Swearingen
public  class AI {
    
    /**
     * gets which card to play 
     * @param hand the hand the ai choses from
     * @param cardPile the top card the ai needs to play on top of
     * @return returns the card to play or null if theres nothing to play
     */
    public Card getPlay(Hand hand, CardPile cardPile){
        for (int i = 0; i < hand.getSize(); i++) {
            if(cardPile.canPlay(hand.get(i))){
                return hand.get(i);
            }
        }
        return null;
    }

    public String toString(){
        return("Random Card AI");
    }
}