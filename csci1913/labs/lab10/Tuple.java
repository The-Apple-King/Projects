//Owen Swearingen
//lab 10
public class Tuple<T> {
    T[] vals;

    /**
     * 
     * @param args array of objects to be saved as a tuple
     */
    public Tuple(T[] args){
        vals = args;
    }

    /**
     * determines if a tuple is sorted
     * @param <Q> object type of tuple
     * @param tup tuple object to compare against this tuple
     * @return true if tuple is sorted
     */
    public static <Q extends Comparable<Q>> boolean isSorted(Tuple<Q> tup) {
        if(tup.getLength() > 0 && tup.get(0) == null) {
            return false;
        }
        for (int i = 1; i < tup.getLength(); i++) {
            if(tup.get(i) == null) {
                return false;
            }
            if(tup.get(i).compareTo(tup.get(i-1)) < 0){
                return false;
            }
        }
        return true;
    }

    /**
     * get the amount of items in a tuple
     * @return the size of tuple
     */
    public int getLength() {
        return vals.length;
    }

    /**
     * get object at an index
     * @param index location in tuple
     * @return object at index 
     */
    public T get(int index) {
        if (index < vals.length && index >= 0) {
            return vals[index];
        }
        return null;
    }

    /**
     * lists the tuple objects in a string
     */
    public String toString() {
        StringBuilder sb = new StringBuilder("(");
        boolean first = true;
        for (T val : vals) {
            if (first) {
                first = false;
            } else {
                sb.append(", ");
            }
            if (vals != null) {
                sb.append(val);
            } else {
                sb.append("null");
            }
        }
        sb.append(")");
        return sb.toString();
    }

    /**
     * returns true if tuple contains element
     * @param elem the element to test for
     * @return true is tuple contains elem
     */
    public boolean contains(T elem) {
        for (int i = 0; i < vals.length; i++) {
            if(vals[i] == elem) {
                return true;
            } else if(vals[i] != null && elem != null && vals[i].equals(elem)){
                return true;
            }
        }
        return false;
    }
    
    /**
     * returns true if this tuple is equal to the other tuple
     */
    @Override
    public boolean equals(Object other) {
        if (other == this) {
            return true;
        } else if (other == null) {
            return false;
        } else if (other instanceof Tuple<?>) {
            Tuple<?> tup = (Tuple<?>)other;
            if(tup.getLength() == this.getLength()){
                for (int i = 0; i < vals.length; i++) {
                    if(!vals[i].equals(tup.get(i))){
                        return false;
                    }
                }
                return true;
            }
        } else {
            return false;
        }
        return false;
    }
}
