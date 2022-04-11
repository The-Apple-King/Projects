/*
 * CSCI 1913 Lab 10
 * Tuple.java Test files
 * Author: Min Namgung
 * 
 * */


import java.util.Random;

public class TestTuple {
	
	
	public static void main(String[] args) {
		
		// Test 1 - Different data type init tests
		Tuple<String> strTup = new Tuple<>(new String[]{"apple", "dog", "cart"});
		Tuple<Integer> intTup = new Tuple<>(new Integer[]{3, 7, 9, 15, 6});

		MyDate mydate = new MyDate(2023, 5, 7);
		Tuple<MyDate> myDateTup = new Tuple<>(new MyDate[]{mydate});
		Tuple<MyDate> myDateTup2 = new Tuple<>(new MyDate[]{
				new MyDate(2022, 1, 14),
				new MyDate(2022, 2, 1),
				new MyDate(2022, 2, 24),
				null,
				new MyDate(2022, 3, 8),
				new MyDate(2022, 4, 2),

		});

		Tuple<Random> randTup = new Tuple<>(new Random[0]);

		System.out.println(strTup);                      // (apple, dog, cart)
		System.out.println(intTup);                      // (3, 7, 9, 15, 6)
		System.out.println(myDateTup);                   // (2023-5-7)
		System.out.println(myDateTup2);                  // (2022-1-14, 2022-2-1, 2022-2-24, null, 2022-3-8, 2022-4-2)
		System.out.println(randTup);                     // ()


		// Test 2 - Group basic tests
		System.out.println(strTup.getLength());          // 3
		System.out.println(intTup.getLength());          // 5
		System.out.println(myDateTup.getLength());       // 1
		System.out.println(myDateTup2.getLength());      // 6
		System.out.println(randTup.getLength());         // 0

		System.out.println(strTup.get(0));               // apple
		System.out.println(strTup.get(-1));              // null
		System.out.println(strTup.get(1));               // dog

		System.out.println(intTup.get(2));               // 9
		System.out.println(intTup.get(0));               // 3
		System.out.println(intTup.get(-1));              // null
		System.out.println(intTup.get(1));               // 7

		System.out.println(myDateTup.get(-1));           // null
		System.out.println(myDateTup.get(0));            // 2023-5-7
		System.out.println(myDateTup.get(1));            // null

		System.out.println(myDateTup2.get(1));           // 2022-2-1
		System.out.println(myDateTup2.get(3));           // null
		System.out.println(randTup.get(0));              // null

		Tuple<String> strTupObj1 = new Tuple<>(new String[]{"apple", "dog", "cart"});
		Tuple<String> strTupObj2 = new Tuple<>(new String[]{"banana", "dog", "cart", "school"});
		Tuple<String> strTupObj3 = new Tuple<>(new String[]{"apple", "dog", "cart", "school"});
		Tuple<Integer> intTupObj1 = new Tuple<>(new Integer[]{3, 7, 9, 15, 6});
		Tuple<Integer> intTupObj2 = new Tuple<>(new Integer[]{3, 7, 9, 6});
		Tuple<Integer> intTupObj3 = new Tuple<>(new Integer[]{3, 7, 9, 6, 0, 8});

		MyDate mydatetest1 = new MyDate(2023, 5, 7);
		Tuple<MyDate> myDateTupObj1 = new Tuple<>(new MyDate[]{mydatetest1});
		MyDate mydatetest2 = new MyDate(2022, 4, 1);
		Tuple<MyDate> myDateTupObj2 = new Tuple<>(new MyDate[]{mydatetest2});

		System.out.println(strTup.equals(strTupObj1));       // true
		System.out.println(strTup.equals(strTupObj2));       // false
		System.out.println(strTup.equals(strTupObj3));       // false
		System.out.println(intTup.equals(intTupObj1));       // true
		System.out.println(intTup.equals(intTupObj2));       // false
		System.out.println(intTup.equals(intTupObj3));       // false
		System.out.println(myDateTup.equals(myDateTupObj1)); // true
		System.out.println(myDateTup.equals(myDateTupObj2)); // false


		// Test 3 - Tests for contains()
		String ele1 = new String("cart");
		String ele2 = new String("mart");
		String ele3 = null;
		System.out.println(strTup.contains(ele1));       // true
		System.out.println(strTup.contains(ele2));       // false
		System.out.println(strTup.contains(ele3));       // false
		System.out.println(strTup.contains(null));       // false

		int eleint1 = 5;
		int eleint2 = 15;
		int eleint3 = 6;
		System.out.println(intTup.contains(eleint1));    // false
		System.out.println(intTup.contains(eleint2));    // true
		System.out.println(intTup.contains(eleint3));    // true
		System.out.println(intTup.contains(null));       // false

		MyDate eledate1 = new MyDate(2023, 5, 7);
		MyDate eledate2 = new MyDate(2021, 5, 7);
		MyDate eledate3 = new MyDate(2022, 2, 24);
		MyDate eledate4 = new MyDate(2022, 3, 8);
		System.out.println(myDateTup.contains(eledate1));  // true
		System.out.println(myDateTup.contains(eledate2));  // false
		System.out.println(myDateTup.contains(null));      // false

		System.out.println(myDateTup2.contains(eledate1)); // false
		System.out.println(myDateTup2.contains(eledate3)); // true
		System.out.println(myDateTup2.contains(eledate4)); // true
		System.out.println(myDateTup2.contains(null));     // true
		
		MyDate mydateSort1 = new MyDate(2023, 1, 7);
		Tuple<MyDate> myDateTupObjSort1 = new Tuple<>(new MyDate[]{mydateSort1});

		System.out.println(myDateTup.contains(mydatetest1)); // true
		System.out.println(myDateTupObjSort1.contains(mydateSort1)); //true
		


		// Test 4 - Tests for isSorted()
		System.out.println(Tuple.isSorted(myDateTup));   // true
		System.out.println(Tuple.isSorted(myDateTup2));  // false

		Tuple<Integer> intTupSort1 = new Tuple<>(new Integer[]{1, 2, 3, 4, 5});
		System.out.println(Tuple.isSorted(intTup));      // false
		System.out.println(Tuple.isSorted(intTupSort1)); // true

		Tuple<String> strTupObjSort1 = new Tuple<>(new String[]{"banana", "cart", "dog"});
		Tuple<String> strTupObjSort2 = new Tuple<>(new String[]{"banana", "cart", "dog", null});
		System.out.println(Tuple.isSorted(strTupObjSort1)); // true
		System.out.println(Tuple.isSorted(strTupObjSort2)); // false
  		System.out.println(Tuple.isSorted(strTup));         // false

		
	}

}


//Expected prints:
/*

(apple, dog, cart)
(3, 7, 9, 15, 6)
(2023-5-7)
(2022-1-14, 2022-2-1, 2022-2-24, null, 2022-3-8, 2022-4-2)
()
3
5
1
6
0
apple
null
dog
9
3
null
7
null
2023-5-7
null
2022-2-1
null
null
true
false
false
true
false
false
true
false
true
false
false
false
false
true
true
false
true
false
false
false
true
true
true
true
true
true
false
false
true
true
false
false

*/
