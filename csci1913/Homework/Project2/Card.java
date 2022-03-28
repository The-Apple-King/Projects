public class Card {
    private int cardRank;
    private int cardSuit;
    private String rankkey[] = new String[] { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Jack", "Queen", "King" };
    private String suitkey[] = new String[] { "Spades", "Hearts", "Clubs", "Diamonds" };

    public Card(int rank, int suit) {
        if (rank > 13 || rank < 1) {
            System.out.println("Invalid Card");
            cardRank = 1;
            cardSuit = 1;
        }
        else if (suit > 4 || suit < 1) {
            System.out.println("Invalid Card");
            cardRank = 1;
            cardSuit = 1;
        }
        else{
            cardRank = rank;
            cardSuit = suit;
        }
    }

    public int getRankNum() {
        return cardRank;
    }

    public String getRankName() {
        return rankkey[cardRank-1];
    }

    public String getSuitName() {
        return suitkey[cardSuit-1];
    }

    public String toString() {
        return (getRankName() + " of " + getSuitName());
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == this){
            return true;
        }
        if (obj instanceof Card) {
            if (cardRank == ((Card) obj).getRankNum() && getSuitName().equals(((Card) obj).getSuitName())) {
                return true;
            }
        }
        return false;
    }
}