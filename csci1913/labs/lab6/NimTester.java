import java.util.Arrays;

public class NimTester {
    public static void main(String[] args) {
        int[] tokens;
        int[] result;

        System.out.println("createTokenCounts");
        tokens = NIM.createTokenCounts(0, 0);
        System.out.println(Arrays.toString(tokens));     // []
        tokens = NIM.createTokenCounts(5, 5);
        System.out.println(Arrays.toString(tokens));     // [5, 4, 3, 2, 1]
        tokens = NIM.createTokenCounts(4, 3);
        System.out.println(Arrays.toString(tokens));     // [3, 2, 1, 1]
        tokens = NIM.createTokenCounts(7, 9);
        System.out.println(Arrays.toString(tokens));     // [9, 8, 7, 6, 5, 4, 3]
        tokens = NIM.createTokenCounts(1, 1);
        System.out.println(Arrays.toString(tokens));     // [1]
        tokens = NIM.createTokenCounts(5, 7);
        System.out.println(Arrays.toString(tokens));     // [7, 6, 5, 4, 3]
        tokens = NIM.createTokenCounts(8, 4);
        System.out.println(Arrays.toString(tokens));     // [4, 3, 2, 1, 1, 1, 1, 1]
        tokens = NIM.createTokenCounts(6, 1);
        System.out.println(Arrays.toString(tokens));     // [1, 1, 1, 1, 1, 1]
        tokens = NIM.createTokenCounts(13, 9);
        System.out.println(Arrays.toString(tokens));     // [9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 1, 1, 1]

        System.out.println("isValidMove");
        tokens = new int[]{5, 4, 3, 2};
        System.out.println(NIM.isValidMove(tokens, "1", "2")); // true
        tokens = new int[]{8, 7, 6, 5, 4};
        System.out.println(NIM.isValidMove(tokens, "5", "2")); // true
        tokens = new int[] {4, 3};
        System.out.println(NIM.isValidMove(tokens, "1", "1")); // true
        tokens = new int[] {4, 3};
        System.out.println(NIM.isValidMove(tokens, "3", "4")); // false
        tokens = new int[] {5, 4, 3, 2};
        System.out.println(NIM.isValidMove(tokens, "5", "4")); // false
        tokens = new int[] {5, 4, 3, 2};
        System.out.println(NIM.isValidMove(tokens, "a", "a")); // false
        tokens = new int[] {5, 4, 3, 2};
        System.out.println(NIM.isValidMove(tokens, "a", "2")); // false
        tokens = new int[] {5, 4, 3, 2};
        System.out.println(NIM.isValidMove(tokens, "1", "a")); // false
        tokens = new int[] {5, 4, 3, 2};
        System.out.println(NIM.isValidMove(tokens, "0", "1")); // false
        tokens = new int[] {5, 4, 3, 2};
        System.out.println(NIM.isValidMove(tokens, "4", "3")); // false
        tokens = new int[] {5, 4, 3, 2};
        System.out.println(NIM.isValidMove(tokens, "1", "4")); // false
        tokens = new int[] {5, 4, 3, 2};
        System.out.println(NIM.isValidMove(tokens, "3", "3")); // true

        System.out.println("update");
        tokens = new int[] {3, 2, 1};
        result = NIM.update(tokens, 2, 1);
        System.out.println(Arrays.toString(tokens) +" "+ Arrays.toString(result));
        tokens = new int[] {4, 3, 2, 1, 0};              // [3, 2, 1] [3, 2, 0]
        result = NIM.update(tokens, 3, 1);
        System.out.println(Arrays.toString(tokens) +" "+ Arrays.toString(result));
        tokens = new int[] {9, 8, 7, 6, 5, 4, 3};        // [4, 3, 2, 1, 0] [4, 3, 2, 0, 0]
        result = NIM.update(tokens, 6, 2);
        System.out.println(Arrays.toString(tokens) +" "+ Arrays.toString(result));
        tokens = new int[] {8, 7, 6, 5};                 // [9, 8, 7, 6, 5, 4, 3] [9, 8, 7, 6, 5, 4, 1]
        result = NIM.update(tokens, 0, 3);
        System.out.println(Arrays.toString(tokens) +" "+ Arrays.toString(result));
        tokens = new int[] {5, 4, 3, 2, 1};              // [8, 7, 6, 5] [5, 7, 6, 5]
        result = NIM.update(tokens, 1, 1);
        System.out.println(Arrays.toString(tokens) +" "+ Arrays.toString(result));
        tokens = new int[] {4, 3, 2, 1};                 // [5, 4, 3, 2, 1] [5, 3, 3, 2, 1]
        result = NIM.update(tokens, 1, 2);
        System.out.println(Arrays.toString(tokens) +" "+ Arrays.toString(result));
                                                         // [4, 3, 2, 1] [4, 1, 2, 1]
        System.out.println("drawBoard");
        tokens = new int[] {5,4,3,2,1};
        System.out.println("before call");
        NIM.drawBoard(tokens);
        System.out.println("after call");
// before call
// Game board.
//
// ====================
// 1 $$$$$
// 2 $$$$
// 3 $$$
// 4 $$
// 5 $
// ====================
// after call

        tokens = new int[] {5,4,3,4,1,0,0,9,1};
        System.out.println("before call");
        NIM.drawBoard(tokens);
        System.out.println("after call");
// before call
// Game board.
//
// ====================
// 1 $$$$$
// 2 $$$$
// 3 $$$
// 4 $$$$
// 5 $
// 6
// 7
// 8 $$$$$$$$$
// 9 $
// ====================
// after call

        tokens = new int[] {1};
        System.out.println("before call");
        NIM.drawBoard(tokens);
        System.out.println("after call");
// before call
// Game board.
//
// ====================
// 1 $
// ====================
// after call

        System.out.println("isOver");
        System.out.println(NIM.isOver(new int[]{0}));                 // true
        System.out.println(NIM.isOver(new int[]{1,4,1,3,1,0}));       // false
        System.out.println(NIM.isOver(new int[]{0,1,2,3,2}));         // false
        System.out.println(NIM.isOver(new int[]{1,2,3,4,0}));         // false
        System.out.println(NIM.isOver(new int[]{0,0,0,0,0,0,0,0}));   // true
        System.out.println(NIM.isOver(new int[]{1,2,0,2,1,3}));       // false

    }
}

/*

total expected output

createTokenCounts
[]
[5, 4, 3, 2, 1]
[3, 2, 1, 1]
[9, 8, 7, 6, 5, 4, 3]
[1]
[7, 6, 5, 4, 3]
[4, 3, 2, 1, 1, 1, 1, 1]
[1, 1, 1, 1, 1, 1]
[9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 1, 1, 1]
isValidMove
true
true
true
false
false
false
false
false
false
false
false
true
update
[3, 2, 1] [3, 2, 0]
[4, 3, 2, 1, 0] [4, 3, 2, 0, 0]
[9, 8, 7, 6, 5, 4, 3] [9, 8, 7, 6, 5, 4, 1]
[8, 7, 6, 5] [5, 7, 6, 5]
[5, 4, 3, 2, 1] [5, 3, 3, 2, 1]
[4, 3, 2, 1] [4, 1, 2, 1]
drawBoard
before call
Game board

====================
1 $$$$$
2 $$$$
3 $$$
4 $$
5 $
====================
after call
before call
Game board

====================
1 $$$$$
2 $$$$
3 $$$
4 $$$$
5 $
6
7
8 $$$$$$$$$
9 $
====================
after call
before call
Game board

====================
1 $
====================
after call
isOver
true
false
false
false
true
false

 */