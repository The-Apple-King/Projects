//Owen Swearingen
//Lab12
public class RepeatBlockQueueNode <T>{

    private T value;
    private RepeatBlockQueueNode<T> next = null;
    private int nodes;

    /**
     * creates a RepeatBlockQueueNode
     * @param elem the element of this node
     * @param next the node this node points to
     */
    public RepeatBlockQueueNode(T elem, RepeatBlockQueueNode<T> next) {
        value = elem;
        nodes = 0;
        if(elem != null){
            nodes ++;
        }
        this.next = next;
    }

    /**
     * returns value in node
     * @return value in node
     */
    public T getData(){
        return value;
    }

    /**
     * returns the amount of duplicate nodes in this position
     * @return number of duplicate nodes in this position
     */
    public int getCount(){
        return nodes;
    }

    /**
     * gets the next node in list
     * @return the next node in the linked list
     */
    public RepeatBlockQueueNode<T> getNext(){
        return next;
    }

    /**
     * sets the value of the data in this node
     * @param val the value to set current node to
     */
    public void setData(T val){
        value = val;
    }

    /**
     * sets the amount of duplicate values in this node
     * @param val number of duplicate nodes
     */
    public void setCount(int val){
        nodes = val;
    }

    /**
     * sets the node this node points to
     * @param nextNode the node to point to
     */
    public void setNext(RepeatBlockQueueNode<T> nextNode){
        next = nextNode;
    }

    /**
     * returns the value as a string
     */
    @Override
    public String toString() {
        return value.toString();
    }
}