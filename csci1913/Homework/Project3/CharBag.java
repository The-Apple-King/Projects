import java.util.Random;

public class CharBag {

    private int letters[]; //array representing the letters the last index being the stop char
    int totLetters; //the total number of letters sampled

    /**
     * 
     */
    public CharBag(){
        letters = new int[27];
        totLetters = 0;
    }

    /**
     * a helper function to find the location in our array of the char sent in
     * @param c the character to find the position of
     * @return the position in the array of a char
     */
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

    /**
     * adds a value to the charbag
     * @param c character to add to the charbag
     */
    public void add(char c) {
        letters[arrPos(c)]++;
        totLetters++;
    }
    
    /**
     * removes a char from charbag
     * @param c the char to be removed
     */
    public void remove(char c) {
        if(letters[arrPos(c)] > 0){
        letters[arrPos(c)]--;
        totLetters--;
        }
    }

    /**
     * returns the number of char c in the charbag
     * @param c the char to check position
     * @return the number of c in the charbag
     */
    public int getCount(char c) {
        return letters[arrPos(c)];
    }

    /**
     * gets the total amount of samples in the charbag
     * @return total letters
     */
    public int getSize() {
        return totLetters;
    }

    
    /** 
     * returns the letters and how many in a string
    */
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

    /**
     * returns a random character with skewed probability based on the data in charbag
     * @return a random char
     */
    public char getRandomChar() {
        if (totLetters > 0) {
            Random rand = new Random();
            int num = 1+rand.nextInt(totLetters);
            int accum = 0;
            int loc = -1;
            //finds location of num in array
            while(accum < num) {
                loc++;
                accum += letters[loc];
            }
            //finds and returns the correct char value of the random char
            if(loc <= 25){ 
                return((char) (loc + 97));
            }else if(loc == 26){
                return(LetterSample.STOP);
            }
        }
        return(LetterSample.STOP);
    }

}
