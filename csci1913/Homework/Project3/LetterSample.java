public class LetterSample {

    public static final char STOP = '.';
    private char nextLetter;
    private String segmentString;

    /**
     * creates a sample of letters and what letter should follow that sample
     * @param segmentString the string identifying this LetterSample
     * @param nextLetter the letter after to add to the Charbag
     */
    public LetterSample(String segmentString, char nextLetter) {
        this.nextLetter = nextLetter;
        this.segmentString = segmentString;
    }

    /**
     * returns the segment that identifies this string
     */
    public String getSegment() {
        return segmentString;
    }

    /**
     * returns the letter that should follow the segment string
     */
    public char getNextLetter() {
        return nextLetter;
    }    

    /**
     * takes a string and turns it into an array of LetterSamples
     * @param input the word to be separated into samples 
     * @param segmentSize the size of the segment of letters
     * @return array of LetterSamples
     */
    public static LetterSample[] toSamples(String input, int segmentSize) {
        LetterSample segments[] = new LetterSample[input.length()+1];
        char word[] = new char[input.length() + 1];
        for (int i = 0; i < word.length - 1; i++) {
            word[i] = input.charAt(i);
        }
        word[word.length - 1] = STOP;

        //create the letter sample array
        for (int i = 0; i < segments.length; i++) {
            StringBuilder sb = new StringBuilder();
            //get segment
            for(int j = i-(segmentSize); j - (i-(segmentSize))< segmentSize; j++){
                if(j>=0){
                    sb.append(word[j]);
                }
            }
            //add to array
            segments[i] = new LetterSample(sb.toString(), word[i]);
        }
        return segments;
    }

    /**
     * returns a LetterSample as a string
     */
    @Override
    public String toString() {
        return "\"" + segmentString + "\"" + " -> "  + nextLetter;
    }
}