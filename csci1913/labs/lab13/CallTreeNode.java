//Owen Swearingen
//tree Nodes
public class CallTreeNode {
    
    private String name; //the string stored by this node
    CallTreeNode first; //person to call first
    CallTreeNode second;//person to call second

    /**
     * instanciates the node
     * @param name the name of the person in this node
     * @param first the first node this points to
     * @param second the second node this points to
     */
    public CallTreeNode(String name, CallTreeNode first, CallTreeNode second){
        this.name = name;
        this.first = first;
        this.second = second;
    }

    /**
     * gets the name stored by this node
     * @return string name
     */
    public String getName(){
        return name;
    }

    /**
     * gets the first node pointed at
     * @return first CallTreeNode
     */
    public CallTreeNode getFirst(){
        return first;
    }

    /**
     * gets the second node pointed at
     * @return second CallTreeNode
     */
    public CallTreeNode getSecond(){
        return second;
    }

    /**
     * sets the fist CalltreeNode
     * @param first CallTreeNode to be set as first
     */
    public void setFirst(CallTreeNode first){
        this.first = first;
    }

    /**
     * sets the second node to point at
     * @param second CallTreeNode to be pointed at second
     */
    public void setSecond(CallTreeNode second){
        this.second = second;
    }

    /**
     * returns true if this node is a caller
     * @return true if caller, false if not
     */
    public boolean isCaller(){
        if(first != null || second != null){
            return true;
        }
        return false;
    }
}
