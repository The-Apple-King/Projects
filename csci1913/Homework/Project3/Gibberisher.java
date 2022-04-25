public class Gibberisher {

    private Trie<CharBag> charbag; //tree of charbags
    private int segmentLength; //the length of the string samples to find words
    private int letterSamples; //the amount of letterSamples 

    /**
     * instanciates the values in gibberisher
     */
    public Gibberisher(int segmentLength) {
        this.segmentLength = segmentLength;
        charbag = new Trie<CharBag>();
        letterSamples = 0;
    }

    /**
     * creates the tree for generate to use to create words
     * @param word[] the array of words in dictionary
     */
    public void train(String word[]){
        for (int i = 0; i < word.length; i++) {// for every word
            LetterSample[]samples = LetterSample.toSamples(word[i], segmentLength);
            for (int j = 0; j < samples.length; j++) {//for every sample
                CharBag val = charbag.get(samples[j].getSegment());
                if(val == null){//if it doesn't exist make it
                    val = charbag.put(samples[j].getSegment(), new CharBag());
                }
                val.add(samples[j].getNextLetter());// add letter to it
                letterSamples++;
            }
        }
    }

    /**
     * returns the number of samples
     * @return number of samples
     */
    public int getSampleCount() {
        return letterSamples;
    }

    /**
     * creates a new word based on the data sent in
     * @return a gibberish string
     */
    public String generate() {
        String word = "";
        do {
            String sample = word.substring(Math.max(word.length() - segmentLength, 0));
            CharBag val = charbag.get(sample);
            word = word + val.getRandomChar();
        } while(word.charAt(word.length()-1) != LetterSample.STOP);
        return word.substring(0, word.length()-1);
    }
}
