@SuppressWarnings("unchecked")
public class TrieNode<T> {

    private T data; //data stored in this node
    private TrieNode<T>[] nodes; //the nodes connected to this one
    

    /**
     * creates a TrieNode object
     */ 
    public TrieNode(){
        nodes = new TrieNode[26];
        data = null;
    }

    /**
     * returns data stored in this node
     * @return data stored in this node
     */
    public T getData() {
        return data;
    }

    /**
     * sets the value of data in this node
     */
    public void setData(T d) {
        data = d;
    }

    /**
     * gets the child node of this node
     * @param c the char defining the next node
     * @return the TrieNode corresponding to char c
     */
    public TrieNode<T> getChild(char c) {
        if(c < 96 || c > 123){// not in range
            return null;
        }
        if(nodes[(int) (c-97)] == null){ //if node doesnt exist
            nodes[(int) (c-97)] = new TrieNode<T>();
        }
        return nodes[(int) (c-97)];
    }

    /**
     * gets the size of the trie
     * @return the size in an int
     */
    public int getTreeSize() {
        int accum = 1;
        for (int i = 0; i < nodes.length; i++) {
            if(nodes[i] != null){
                accum += nodes[i].getTreeSize();
            }
        }
        return accum;
    }
    
}
