public class LetterSample {

    public static final char STOP = '.';
    private char nextLetter;
    private String segmentString;

    public LetterSample(String segmentString, char nextLetter) {
        this.nextLetter = nextLetter;
        this.segmentString = segmentString;
    }

    public char getNextLetter() {
        return nextLetter;
    }

    public String getSegment() {
        return segmentString;
    }

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

    @Override
    public String toString() {
        return "\"" + segmentString + "\"" + " -> "  + nextLetter;
    }
}