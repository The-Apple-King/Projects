@SuppressWarnings("unchecked")
public class TrieNode<T> {

    private T data;
    private TrieNode<T>[] nodes = new TrieNode[26];
    

    public TrieNode(){
        for (int i = 0; i < 26; i++) {
            nodes[i] = null;
        }
        data = null;
    }


    public T getData() {
        return data;
    }


    public void setData(T d) {
        data = d;
    }


    public TrieNode<T> getChild(char c) {
        if(nodes[(int) (c-97)] == null){
            nodes[(int) (c-97)] = new TrieNode<>();
        }
        return nodes[(int) (c-97)];
    }

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
