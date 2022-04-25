public class Trie<T> {

    private TrieNode<T> root;

    public Trie() {
        root = new TrieNode<T>();
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

    public T put(String string, T val) {
        getNode(string).setData(val);
        return val;
    }

    public TrieNode<T> getRoot() {
        return root;
    }
}
