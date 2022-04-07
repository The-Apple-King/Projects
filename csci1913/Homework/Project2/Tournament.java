//Project 2
//Owen Swearingen
public class Tournament {
    
    public static void main(String[] args) {
        AI[] ais = { new AI(),
        new SmallestCardAI(),
        new BiggestCardAI()
        };

        UnoWarMatch[] matchups = new UnoWarMatch[9];
        int index = 0;
        //loops through to set each matchup
        for (int i = 0; i < ais.length; i++) {
            for (int j = 0; j < ais.length; j++) {
                matchups[index] = new UnoWarMatch(ais[i], ais[j]);
                index++;
            }
        }

        //loops through matchups to try every play
        for (int i = 0; i < matchups.length; i++) {
            System.out.println(matchups[i].toString() + matchups[i].winrate(1000));
        }
    }
}
