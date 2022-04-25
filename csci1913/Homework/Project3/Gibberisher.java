public class Gibberisher {

    private Trie<CharBag> charbag;
    private int segmentLength;
    private int letterSamples;

    public Gibberisher(int segmentLength) {
        this.segmentLength = segmentLength;
        charbag = new Trie<CharBag>();
        letterSamples = 0;
    }

    public void train(String word[]){
        for (int i = 0; i < word.length; i++) {
            LetterSample[]samples = LetterSample.toSamples(word[i], segmentLength);
            for (int j = 0; j < samples.length; j++) {
                CharBag val = charbag.get(samples[j].getSegment());
                if(val == null){
                    val = charbag.put(samples[j].getSegment(), new CharBag());
                }
                val.add(samples[j].getNextLetter());
                letterSamples++;
            }
        }
    }

    public int getSampleCount() {
        return letterSamples;
    }

    public String generate() {
        String word = "";
        do {
            String sample = word.substring(Math.max(word.length() - segmentLength, 0));
            CharBag val = charbag.get(sample);
            word = word + val.getRandomChar();
        } while(word.charAt(word.length()-1) != LetterSample.STOP);
        return word;
    }
}
