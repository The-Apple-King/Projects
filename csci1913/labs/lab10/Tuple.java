public class Tuple<T> {
    T[] vals;

    public static <Q extends Comparable<Q>> boolean isSorted(Tuple<Q> tup) {
        return false;
    }

    boolean isSorted(Tuple<Q> tup) {

    }

    public int getLength() {
        return vals.length;
    }

    public T get(int index) {
        if (index < vals.length && index > 0) {
            return vals[index];
        }
        return null;
    }

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

    public boolean contains(L elem) {
        for (int i = 0; i < vals.length; i++) {
            if(vals[i].equals(elem)){
                return true;
            }
        }
        return false;
    }
    
    public boolean equals(Object o) {
        return false;
    }
}
