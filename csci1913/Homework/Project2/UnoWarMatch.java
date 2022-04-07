//Project 2
//Owen Swearingen
public class UnoWarMatch {

    AI ai1;
    AI ai2;

    /**
     * creates a match between the two ai sent in
     * @param ai1 first ai
     * @param ai2 second ai
     */
    public UnoWarMatch(AI ai1, AI ai2) {
        this.ai1 = ai1;
        this.ai2 = ai2;
    }

    /**
     * plays a single round of unoWar between two ai
     * @param deck the deck that will be drawn from
     * @param hand1 ai1's hand
     * @param hand2 ai2's hand
     * @param first whos turn it is, true = ai1 false =ai2
     * @return returns true if ai1 wins false if ai2 wins
     */
    private boolean playRound(Deck deck, Hand hand1, Hand hand2, boolean first) {

        CardPile cardPile = new CardPile(deck.draw());
        Card currentPlay;// just a card to be overwritten

        while (true) {
            if (first) {
                currentPlay = ai1.getPlay(hand1, cardPile);
                hand1.remove(currentPlay);
            } else {
                currentPlay = ai2.getPlay(hand2, cardPile);
                hand2.remove(currentPlay);
            }

            if (currentPlay == null) {
                return !first;
            } else {
                cardPile.play(currentPlay);
            }
            first = !first;

        }
    }

    /**
     * accumulator that returns who won 10 rounds first by calling playRound()
     * @return true if ai1 won false if ai2 won
     */
    public boolean playGame() {
        int ai1wins = 0;
        int ai2wins = 0;
        Deck deck = new Deck();
        Hand hand1 = new Hand(deck, 5);
        Hand hand2 = new Hand(deck, 5);
        boolean turn = true;
        while (ai1wins < 10 && ai2wins < 10) {// until one has gotten 10 wins
            if (playRound(deck, hand1, hand2, turn)) { // if true ai1 wins else ai2 wins
                ai1wins++;
                turn = true;
            } else {
                ai2wins++;
                turn = false;
            }
        }
        return (ai1wins > ai2wins); // if ai1 wins more true if ai2 wins more false

    }

    /**
     * runs games and finds the wins/trials for ai1
     * @param nTrials how many games to play
     * @return the number of ai1 wins divided by total trials
     */
    public double winrate(int nTrials) {
        double ai1wins = 0;

        for (int i = 0; i < nTrials; i++) {
            if (playGame()) {
                ai1wins++;
            }
        }

        return (ai1wins / nTrials);
    }

    /**
     * prints out who the match takes place between
     */
    @Override
    public String toString() {
        return (ai1.toString() + " V.S. " + ai2.toString() + ": ");
    }
}
