package lab13;

public class CallTreeTests {
    public static void main(String[] args) {


        CallTree tree = new CallTree("Mats");
        // test initial conditions
        System.out.println(tree.inCallTree("Mats"));                      // true
        System.out.println(tree.inCallTree("Daniel"));                    // false
        System.out.println(tree.getFirstCall("Mats") == null);            // true
        System.out.println(tree.getCallCount());                          // 0


        boolean result = tree.shouldCall("Mats", "Daniel", "Min");
        System.out.println(result);                                       // true
        System.out.println(tree.inCallTree("Mats"));                      // true
        System.out.println(tree.inCallTree("Daniel"));                    // true
        System.out.println(tree.inCallTree("Min"));                       // true
        System.out.println(tree.getCallCount());                          // 1
        System.out.println(tree.getFirstCall("Mats"));                    // Daniel
        System.out.println(tree.getFirstCall("Daniel") == null);          // true
        System.out.println(tree.getSecondCall("Mats"));                   // Min

        // test tree to tree independence
        CallTree ct2 = new CallTree("Daniel");
        System.out.println(tree.inCallTree("Mats"));                      // true
        System.out.println(tree.inCallTree("Daniel"));                    // true
        System.out.println(ct2.inCallTree("Mats"));                       // false
        System.out.println(ct2.inCallTree("Daniel"));                     // true
        result = ct2.shouldCall("Daniel", "Min", "Carson");
        System.out.println(result);                                       // true
        System.out.println(tree.getFirstCall("Daniel") == null);          // true

        // Attempt invalid adds.
        // already in tree!
        result = tree.shouldCall("Daniel", "Min", "Carson");
        System.out.println(result);                                       // false
        System.out.println(tree.getCallCount());                          // 1

        // already in tree (right)!
        result = tree.shouldCall("Min", "Carson", "Mats");
        System.out.println(result);                                       // false
        System.out.println(tree.getCallCount());                          // 1

        // Already has people to call
        result = tree.shouldCall("Mats", "Asa", "Carson");
        System.out.println(result);                                       // false
        System.out.println(tree.getCallCount());                          // 1

        // not in Tree
        result = tree.shouldCall("Carson", "Asa", "Mitra");
        System.out.println(result);                                       // false
        System.out.println(tree.getCallCount());                          // 1

        // ok let's build out a tree then
        result = tree.shouldCall("Min", "Asa", "Anwaar");
        System.out.println(result);                                       // true
        System.out.println(tree.getCallCount());                          // 2

        result = tree.shouldCall("Daniel", "Mitra", "Carson");
        System.out.println(result);                                       // true
        System.out.println(tree.getCallCount());                          // 2

        result = tree.shouldCall("Carson", "Alex", "Sriram");
        System.out.println(result);                                       // true
        System.out.println(tree.getCallCount());                          // 3

        // check condition after adds.
        System.out.println(tree.getFirstCall("Carson"));                  // Alex
        System.out.println(tree.getSecondCall("Daniel"));                 // Carson

        System.out.println(tree.inCallTree("Mitra"));                     // true
        System.out.println(tree.inCallTree("Carson"));                    // true
        System.out.println(tree.inCallTree("Asa"));                       // true
        System.out.println(tree.inCallTree("Lily"));                      // false

        System.out.println(tree.getRemainingCalls("Min"));                // 1
        System.out.println(tree.getRemainingCalls("Daniel"));             // 2

    }
}
/*

true
false
true
0
true
true
true
true
1
Daniel
true
Min
true
true
false
true
true
true
false
1
false
1
false
1
false
1
true
2
true
2
true
3
Alex
Carson
true
true
true
false
1
2

*/
