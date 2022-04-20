//Owen Swearingen
//Lab 12
public class RepeatBlockQueue<T> {

    private RepeatBlockQueueNode front;
    private RepeatBlockQueueNode back;
    private int size;

    /**
     * creates an empty front and back node and sets size to 0
     */
    public RepeatBlockQueue() {
        back = new RepeatBlockQueueNode<T>(null, null);
        front = new RepeatBlockQueueNode<T>(null, back);
        size = 0;
    }

    /**
     * adds a node to the list, if empty creates the list around that node
     * @param elem value to be contained in the node
     */
    public void enqueue(T elem) {
        RepeatBlockQueueNode<T> node = new RepeatBlockQueueNode<T>(elem, null);
        if (size == 0) {
            front = node;
            back = node;
        } else if (back.getData() == elem) {
            back.setCount(back.getCount() + 1);
        } else {
            back.setNext(node);
            back = back.getNext();
        }
        size++;
    }

    /**
     * returns the value stored in the first node
     * @return value in the first node
     */
    public T front() {
        if (size == 0) {
            return null;
        }
        return (T) front.getData();
    }

    /**
     * checks for duplicate nodes in the first node and subtracts one from the total
     * if no duplicates removes from list
     * returns the value stored in the first node
     * @return value stored in the first node
     */
    public T dequeue() {
        if (isEmpty()) {
            return null;

        } else if (size == 1) {
            RepeatBlockQueueNode node = front;
            if (node.getCount() > 1) {
                node.setCount(node.getCount() - 1);
                size--;
                return (T) node.getData();
            } else {
                back = new RepeatBlockQueueNode<T>(null, null);
                front = new RepeatBlockQueueNode<T>(null, back);
                size = 0;
                return (T) node.getData();
            }
        } else {
            RepeatBlockQueueNode node = front;
            if (node.getCount() > 1) {
                node.setCount(node.getCount() - 1);
                size--;
                return (T) node.getData();
            } else {
                front = front.getNext();
                size--;
                return (T) node.getData();
            }
        }
    }

    /**
     * checks if list is empty
     * @return true if empty, false if not
     */
    public boolean isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

    /**
     * returns the value of size
     * @return size of list
     */
    public int getSize() {
        return size;
    }

    /**
     * returns the amount of duplicates in the first node
     * @return number of duplicates in node 1
     */
    public int frontOfLineRepeatCount() {
        return front.getCount();
    }

    /**
     * prints out list in format
     * value:count, ...
     */
    @Override
    public String toString() {
        StringBuilder out = new StringBuilder("");
        RepeatBlockQueueNode<T> node = front;
        while (size != 0) {
            if (node != back) {
                out.append(node.getData() + ":" + node.getCount());
                out.append(", ");
                node = node.getNext();
            }
            if (node == back) {
                out.append(node.getData() + ":" + node.getCount());
                break;
            }
        }
        return out.toString();
    }
}
