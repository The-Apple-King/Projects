import java.util.Random;

public class CharBag {

    private int letters[] = new int[27];
    int totLetters;

    private int arrPos(char c) {
        int letterloc;
        if (Character.isLetter(c)) {
            c = Character.toLowerCase(c);
            letterloc = c - 97;
        } else {
            letterloc = 26;
        }
        return letterloc;
    }

    public void add(char c) {
        letters[arrPos(c)]++;
        totLetters++;
    }

    public void remove(char c) {
        if(letters[arrPos(c)] > 0){
        letters[arrPos(c)]--;
        totLetters--;
        }
    }

    public int getCount(char c) {
        return letters[arrPos(c)];
    }

    public int getSize() {
        return totLetters;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("CharBag{");
        for (int i = 0; i < letters.length-1; i++) {
            char let = (char) (i + 97);
            sb.append(let + ":" + letters[i] + ", ");
        }
        sb.append(".:" + letters[letters.length - 1] + "}");
        return sb.toString();
    }

    public char getRandomChar() {
        if (totLetters > 0) {
            Random rand = new Random();
            int num = 1 + rand.nextInt(totLetters);
            int accum = 0;
            int loc = 0;
            while(loc < 26){
                accum += letters[loc];
                if(accum >= num){
                    break;
                }
                loc++;
            }
            return (char) (loc+97);
        }
        return LetterSample.STOP;
    }

}
