/*
 * CSCI 1913
 * Lab 08
 * Author: Min Namgung
 *
 * Test File
 * */


import java.util.Arrays;

public class CraftingLibraryTest {

	public static void main(String[] args) {

		CraftingItem item1 = new CraftingItem("wood", 2.5);
		CraftingItem item2 = new CraftingItem("nail", 1.5);
		CraftingItem item3 = new CraftingItem("tape", 2);
		CraftingItem recipe1 = new CraftingItem("nailbat", new String[]{"wood", "nail", "nail", "nail"});
		CraftingItem recipe2 = new CraftingItem("shuriken", new String[]{"tape", "nail", "nail", "nail", "nail"});
		CraftingItem recipe3 = new CraftingItem("walkingstick", new String[]{"wood", "wood", "tape"});
		CraftingItem recipe4 = new CraftingItem("spear", new String[]{"wood", "tape", "nail", "nail"});
		CraftingItem recipe5 = new CraftingItem("walkingstickspear", new String[]{"walkingstick", "nailbat", "shuriken", "nail"});
		CraftingItem recipe6 = new CraftingItem("spearWall", new String[]{"spear", "spear", "spear", "spear", "tape"});

		// test ADD_AND_SIZE just does this block of code for getNumItems
		// test ADD_AND_GET_NAMES does this block of code for getItemNames
		CraftingLibrary library = new CraftingLibrary();
		System.out.println(library.getNumItems());        // 0
		System.out.println(Arrays.toString(library.getItemNames())); // []

		System.out.println(library.addItem(item1));      // true
		System.out.println(library.getNumItems());        // 1
		System.out.println(Arrays.toString(library.getItemNames())); // [wood]

		System.out.println(library.addItem(item2));      // true
		System.out.println(library.getNumItems());       // 2
		System.out.println(Arrays.toString(library.getItemNames())); // [wood, nail]

		System.out.println(library.addItem(item3));      // true
		System.out.println(library.getNumItems());       // 3
		System.out.println(Arrays.toString(library.getItemNames())); // [wood, nail, tape]

		System.out.println(library.addItem(recipe1));    // true
		System.out.println(library.getNumItems());       // 4
		System.out.println(Arrays.toString(library.getItemNames())); // [wood, nail, tape, nailbat]

		System.out.println(library.addItem(recipe2));    // true
		System.out.println(library.getNumItems());       // 5
		System.out.println(Arrays.toString(library.getItemNames())); // [wood, nail, tape, nailbat, shuriken]

		System.out.println(library.addItem(recipe3));    // true
		System.out.println(library.getNumItems());       // 6
		System.out.println(Arrays.toString(library.getItemNames())); // [wood, nail, tape, nailbat, shuriken, walkingstick]

		System.out.println(library.addItem(recipe4));    // true
		System.out.println(library.getNumItems());       // 7
		System.out.println(Arrays.toString(library.getItemNames())); // [wood, nail, tape, nailbat, shuriken, walkingstick, spear]

		System.out.println(library.addItem(recipe5));    // true
		System.out.println(library.getNumItems());       // 8
		System.out.println(Arrays.toString(library.getItemNames())); // [wood, nail, tape, nailbat, shuriken, walkingstick, spear, walkingstickspear]

		System.out.println(library.addItem(recipe6));    // true
		System.out.println(library.getNumItems());       // 9
		System.out.println(Arrays.toString(library.getItemNames())); // [wood, nail, tape, nailbat, shuriken, walkingstick, spear, walkingstickspear, spearWall]


		System.out.println(library.getItem(-1));         // null
		System.out.println(library.getItem(0));          // name: wood, cost: 2.5, parts: null
		System.out.println(library.getItem(3));          // name: nailbat, cost: 0.0, parts: [wood, nail, nail, nail]
		System.out.println(library.getItem(6));          // name: spear, cost: 0.0, parts: [wood, tape, nail, nail]
		System.out.println(library.getItem(9));          // null

		System.out.println(library.getcost("wood"));     // 2.5
		System.out.println(library.getcost("tape"));     // 2.0
		System.out.println(library.getcost("nailbat"));  // 7.0
		System.out.println(library.getcost("spear"));    // 7.5
		System.out.println(library.getcost("walkingstickspear")); // 23.5
		System.out.println(library.getcost("duck"));     // 0.0

		library = new CraftingLibrary();
		for (int i = 0; i < 100; i++) {
			boolean res = library.addItem(new CraftingItem("generic item"+i,i));
			if (!res) {
				System.out.println("Fail!"); // should not print
			}
		}
		System.out.println(library.getNumItems());       // 100
		System.out.println(library.addItem(item1));      // false


	}

}

/*
EXPECTED OUTPUT

0
[]
true
1
[wood]
true
2
[wood, nail]
true
3
[wood, nail, tape]
true
4
[wood, nail, tape, nailbat]
true
5
[wood, nail, tape, nailbat, shuriken]
true
6
[wood, nail, tape, nailbat, shuriken, walkingstick]
true
7
[wood, nail, tape, nailbat, shuriken, walkingstick, spear]
true
8
[wood, nail, tape, nailbat, shuriken, walkingstick, spear, walkingstickspear]
true
9
[wood, nail, tape, nailbat, shuriken, walkingstick, spear, walkingstickspear, spearWall]
null
name: wood, cost: 2.5, parts: null
name: nailbat, cost: 0.0, parts: [wood, nail, nail, nail]
name: spear, cost: 0.0, parts: [wood, tape, nail, nail]
null
2.5
2.0
7.0
7.5
23.5
0.0
100
false


 */