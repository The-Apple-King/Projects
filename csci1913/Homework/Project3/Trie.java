public class Trie<T> {

    private TrieNode<T> root;

    public Trie() {
        root = new TrieNode<>();
    }

    private TrieNode<T> getNode(String string) {
        TrieNode<T> loc = root;
        for (int i = 0; i < string.length(); i++) {
            loc = loc.getChild(string.charAt(i));
        }
        return loc;
    }

    public T get(String string) {
        return getNode(string).getData();
    }

    public void put(String string, T val) {
        getNode(string).setData(val);
    }

    public TrieNode<T> getRoot() {
        return root;
    }
}
