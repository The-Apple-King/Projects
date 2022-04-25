public class Trie<T> {

    private TrieNode<T> root; //The root node of the Trie

    /**
     * creates a root node
     */
    public Trie() {
        root = new TrieNode<T>();
    }

    /**
     * gets a node based on the string it recieves
     * @param string address to node
     * @return returns the node at string location
     */
    private TrieNode<T> getNode(String string) {
        TrieNode<T> loc = root;
        for (int i = 0; i < string.length(); i++) {
            loc = loc.getChild(string.charAt(i));
        }
        return loc;
    }

    /**
     * returns the value stored in the node at address string
     * @param string address of the node
     * @return the value stored in the node
     */
    public T get(String string) {
        return getNode(string).getData();
    }

    /**
     * puts val into data at location string
     * @param string address of node
     * @param val value to be put into the node
     * @return returns the value to be stored into the node
     */
    public T put(String string, T val) {
        getNode(string).setData(val);
        return val;
    }

    /**
     * returns the root node for testing
     * @return root node
     */
    public TrieNode<T> getRoot() {
        return root;
    }
}
