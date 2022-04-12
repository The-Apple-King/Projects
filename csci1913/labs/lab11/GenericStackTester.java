
/**
 * Test for GenericStack class
 *
 */
public class GenericStackTester {
    public static void main(String[] args) {
        System.out.println("Test 1: emptyStack");
        GenericStack<String> stack1 = new GenericStack<>(2);
        System.out.println(stack1.isEmpty());            // true

        System.out.println(null == stack1.peek());       // true
        System.out.println(null == stack1.pop());        // true

        System.out.println("Test 2 Push Once");
        stack1.push("rouge");
        System.out.println(stack1.isEmpty());            // false
        System.out.println(stack1.peek());               // rouge
        System.out.println(stack1.peek());               // rouge
        System.out.println(stack1.isEmpty());            // false

        System.out.println("Test 3 Pop after push");
        System.out.println(stack1.pop());                // rouge
        System.out.println(null == stack1.peek());       // true
        System.out.println(stack1.isEmpty());            // true
        System.out.println(null == stack1.pop());        // true

        System.out.println("Test 4 Push More Pop More");
        stack1.push("diet");
        stack1.push("hectic");
        System.out.println(stack1.isEmpty());            // false
        System.out.println(stack1.peek());               // hectic
        System.out.println(stack1.isEmpty());            // false
        System.out.println(stack1.pop());                // hectic
        System.out.println(stack1.isEmpty());            // false
        System.out.println(stack1.peek());               // diet
        System.out.println(stack1.isEmpty());            // false
        System.out.println(stack1.pop());                // diet
        System.out.println(stack1.isEmpty());            // true

        System.out.println("Test 5 Mixed Push and Pop");
        stack1.push("rouge");
        stack1.push("diet");
        stack1.push("hectic");
        System.out.println(stack1.isEmpty());            // false
        System.out.println(stack1.pop());                // hectic
        System.out.println(stack1.isEmpty());            // false
        System.out.println(stack1.pop());                // diet
        System.out.println(stack1.isEmpty());            // false
        stack1.push("knock");
        stack1.push("very nice");
        System.out.println(stack1.isEmpty());            // false
        System.out.println(stack1.pop());                // very nice
        System.out.println(stack1.isEmpty());            // false
        System.out.println(stack1.pop());                // knock
        System.out.println(stack1.isEmpty());            // false
        System.out.println(stack1.pop());                // rouge
        System.out.println(stack1.isEmpty());            // true
        System.out.println(null == stack1.pop());        // true

        System.out.println("Test 6 int stack");
        GenericStack<Integer> stack2 = new GenericStack<>(3);
        System.out.println("Stack 2");

        stack2.push(1);
        stack2.push(2);
        stack2.push(3);
        stack2.push(4);
        stack2.push(5);
        stack2.push(6);
        stack2.push(7);
        System.out.println(stack2.pop());                // 7
        System.out.println(stack2.pop());                // 6
        System.out.println(stack2.pop());                // 5
        System.out.println(stack2.pop());                // 4
        System.out.println(stack2.pop());                // 3
        System.out.println(stack2.pop());                // 2
        System.out.println(stack2.pop());                // 1
        System.out.println(stack2.isEmpty());            // true

        System.out.println("Test 7 Char Stack");
        GenericStack<Character> stack3 = new GenericStack<>(3);

        // use the stack to reverse a string. neat!
        String apple = "tresed rof eip elppa";
        for(int i = 0; i < apple.length(); i++) {
            stack3.push(apple.charAt(i));
        }
        String out = "";
        while(!stack3.isEmpty()) {
            out += stack3.pop();
        }
        System.out.println(out);                         // apple pie for desert

        // This last part is a speed test. It's hard to say what the "right" speed is here, but if your code is wrong -- it will take a LONG time
        System.out.println("Test 8 Speed Test Started");
        long start = System.currentTimeMillis();
        GenericStack<Integer> speed = new GenericStack<>(1);
        for (int i = 0; i < 200000; i++) {
            speed.push(i);
        }
        for (int i = 200000-1; i >=0 ; i--) {
            if (i != speed.pop()) {
                System.out.println("Incorrect pop value on real-big-test");
                break;
            }
        }
        System.out.println("Speed Test Done");
        long stop = System.currentTimeMillis();
        // With efficient code, this should run well under 1 second. It takes about 0.2 second on my computer.
        // With maximally INEFFICIENT code It takes a minute or more.
        System.out.println("Time took: "+((stop-start)/1000.0));

    }
}

/*

Test 1: emptyStack
true
true
true
Test 2 Push Once
false
rouge
rouge
false
Test 3 Pop after push
rouge
true
true
true
Test 4 Push More Pop More
false
hectic
false
hectic
false
diet
false
diet
true
Test 5 Mixed Push and Pop
false
hectic
false
diet
false
false
very nice
false
knock
false
rouge
true
true
Test 6 int stack
Stack 2
7
6
5
4
3
2
1
true
Test 7 Char Stack
apple pie for desert
Test 8 Speed Test Started
Speed Test Done
Time took: 0.074 <OR SOME OTHER NUMBER!>

 */