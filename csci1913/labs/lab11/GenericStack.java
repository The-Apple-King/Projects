//Owen Swearingen
//lab 11
public class GenericStack<Elem> {
 
    private Elem data[];
    private int size = -1;

    /**
     * creates a new Elem stack of size 'size'
     * @param size the default size of the stack
     */
    
    public GenericStack(int size){
        data = (Elem[]) new Object[size];
    }

    /**
     * checks if the stack is empty
     * @return true if empty false if not
     */
    public boolean isEmpty(){
        if(size == -1){
            return true;
        }
        return false;
    }

    /**
     * adds a value to the stack
     * @param val value to be added to stack
     */
    public void push(Elem val){
        if(data.length == size + 2){
            Elem[] temp = (Elem[])new Object[(data.length+1)*2];
            for (int i = 0; i < data.length; i++) {
                temp[i] = data[i];
            }
            data = temp;
        }
        size++;
        data[size] = val;
    }

    /**
     * looks at the top of the stack 
     * @return the top element of the stack
     */
    public Elem peek(){
        if(size == -1){
            return null;
        }
        return data[size];
    }

    /**
     * removes the value at the top of the stack and returns it
     * @return the value at the top of the stack
     */
    public Elem pop(){
        if(size == -1){
            return null;
        }
        Elem val = data[size];
        data[size] = null;
        size--;
        return val;
    }

}