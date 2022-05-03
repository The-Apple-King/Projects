//Owen Swearingen
//Call Tree
public class CallTree {
    CallTreeNode root; //the root of tree

    /**
     * instanciates the tree
     * @param val the first name in the tree
     */
    public CallTree(String val) {
        root = new CallTreeNode(val, null, null);
    }

    /**
     * finds the location of String name node
     * @param name the name stored by the node
     * @return the CallTreeNode that stores name
     */
    private CallTreeNode find(String name) {
        return find(name, root);

    }

    /**
     * helper function that does the recursive part
     * @param name value to look for
     * @param temp current node
     * @return the node that stores name if it exists else null
     */
    private CallTreeNode find(String name, CallTreeNode temp) {
        if(temp == null) {
            return null;
        }
        if(temp.getName().equals(name)) {
            return temp;
        }
        CallTreeNode first = find(name, temp.getFirst());
        if(first != null) {
            return first;
        }
        return find(name, temp.getSecond());
    }

    /**
     * returns in a person is in the call tree
     * @param person name to look for
     * @return true if in tree else false
     */
    public boolean inCallTree(String person){
        if(find(person) == null){
            return false;
        }
        return true;
    }

    /**
     * sets the branching nodes of the node that stores person
     * @param person the node to attach callers to
     * @param first first to call
     * @param second second to call
     * @return returns true if there are no issues, false if there is
     */
    public boolean shouldCall(String person, String first, String second){
        CallTreeNode temp = find(person);
        if(temp == null || temp.isCaller() || (find(first) != null || find(second) != null)){
            return false;
        }
        CallTreeNode left = new CallTreeNode(first, null, null);
        CallTreeNode right = new CallTreeNode(second, null, null);
        temp.setFirst(left);
        temp.setSecond(right);
        return true;
    }

    /**
     * gets the first caller for node name
     * @param name the name stored by node
     * @return returns the first caller if it exists else null
     */
    public String getFirstCall(String name){
        CallTreeNode temp = find(name);
        if(temp.getFirst() == null){
            return null;
        }
        return temp.getFirst().getName();
    }

    /**
     * returns the second caller for node name
     * @param name the name stored by node
     * @return returns the second caller if it exists else null
     */
    public String getSecondCall(String name){
        CallTreeNode temp = find(name);
        if(temp.getSecond() == null){
            return null;
        }
        return temp.getSecond().getName();
    }

    /**
     * returns the height of tree
     * @return height of the tree
     */
    public int getCallCount(){
        return getHeight(root);
    }

    /**
     * returns the height from node person
     * @param person the name stored by the node
     * @return the height of the tree from that node
     */
    public int getRemainingCalls(String person){
        CallTreeNode temp = find(person);
        return getHeight(temp);
    }

    /**
     * returns the height of the tree
     * @param node the node to start searching from
     * @return returns the height as an int
     */
    private int getHeight(CallTreeNode node){
        if(node == null){
            return 0;
        }
        return Math.max(getHeight(node.getFirst(), 0), getHeight(node.getSecond(), 0));
    }

    /**
     * helper function to store recursive values 
     * @param node the node being looked at
     * @param height the current height 
     * @return the height of the tree
     */
    private int getHeight(CallTreeNode node, int height){
        if(node == null){
            return height;
        }
        return Math.max(getHeight(node.getFirst(), height + 1), getHeight(node.getSecond(), height + 1));
    }
}
