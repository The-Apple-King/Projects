public class Gibberisher {

    private Trie<CharBag> charbag;
    private int segmentLength;
    private int letterSamples;

    public Gibberisher(int segmentLength){
        this.segmentLength = segmentLength;
        charbag = new Trie<>();
        letterSamples = 0;
    }
    
    public void train(String word[]){
        LetterSample pp = new LetterSample(segmentString, nextLetter);
    }

    public int getSampleCount(){
        return letterSamples;
    }

    public String generate(){
        return null;
    }
}
