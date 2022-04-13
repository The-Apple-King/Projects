/*
 * CSCI 1913
 * Lab 08
 * Author: Min Namgung and Daniel Kluver
 *
 * Test File for Crafting Item
 * */



public class CraftingItemTest {

	public static void main(String[] args) {

		CraftingItem item1 = new CraftingItem("wood", 2.5);
		CraftingItem item2 = new CraftingItem("nail", 1.5);
		// item3 will also have name "nail" -- I'm doing it this way
		// to make sure the java compiler creates a second string object for "nail"
		// it's SURPRISINGLY HARD to get java to not re-use existing string objects.
		CraftingItem item3 = new CraftingItem(new String(new char[]{'n', 'a', 'i', 'l'}), 1.5);

		CraftingItem recipe1 = new CraftingItem("nailbat", new String[]{"wood", "nail", "nail", "nail"});
		CraftingItem recipe2 = new CraftingItem("shuriken", new String[]{"tape", "nail", "nail", "nail", "nail"});
		CraftingItem recipe3 = new CraftingItem("wood", new String[]{"tree", "axe"});

		// similar thing going on here
		CraftingItem recipe3_also = new CraftingItem(new String(new char[]{'w', 'o', 'o', 'd'}), new String[]{new String(new char[]{'t', 'r', 'e', 'e'}), "axe"});
		CraftingItem recipe4 = new CraftingItem("spear", new String[]{"wood", "tape", "nail", "nail"});
		CraftingItem recipe5 = new CraftingItem("walkingstickspear", new String[]{"walkingstick", "nailbat", "shuriken", "nail"});
		CraftingItem recipe6 = new CraftingItem("spearWall", new String[]{"spear", "spear", "spear", "spear", "tape"});

		// TEST ITEM 1
		System.out.println(item1.isRecipe());            // false
		System.out.println(item1.isBasicPart());         // true
		System.out.println(item1.getName());             // wood
		System.out.println(item1.getNumParts());         // 0

		// TEST ITEM 2
		System.out.println(item2.isRecipe());            // false
		System.out.println(item2.isBasicPart());         // true
		System.out.println(item2.getName());             // nail
		System.out.println(item2.getNumParts());         // 0

		// TEST REC 4
		System.out.println(recipe4.isRecipe());          // true
		System.out.println(recipe4.isBasicPart());       // false
		System.out.println(recipe4.getName());           // spear
		System.out.println(recipe4.getNumParts());       // 4

		// TEST REC 6
		System.out.println(recipe6.isRecipe());          // true
		System.out.println(recipe6.isBasicPart());       // false
		System.out.println(recipe6.getName());           // spearWall
		System.out.println(recipe6.getNumParts());       // 5

		// tests for getPart
		System.out.println(item1.getPart(0));            // null
		System.out.println(item2.getPart(3));            // null
		System.out.println(recipe5.getPart(-1));         // null
		System.out.println(recipe5.getPart(2));          // shuriken
		System.out.println(recipe5.getPart(1));          // nailbat
		System.out.println(recipe5.getPart(4));          // null

		// TEST toString
		String toString = item1.toString();
		System.out.println("toString: " + toString);     // toString: name: wood, cost: 2.5, parts: null
		toString = item2.toString();
		System.out.println("toString: " + toString);     // toString: name: nail, cost: 1.5, parts: null
		toString = recipe1.toString();
		System.out.println("toString: " + toString);     // toString: name: nailbat, cost: 0.0, parts: [wood, nail, nail, nail]
		toString = recipe2.toString();
		System.out.println("toString: " + toString);     // toString: name: shuriken, cost: 0.0, parts: [tape, nail, nail, nail, nail]

		// TEST equals
		//System.out.println(item1.equals("wood"));        // false
		System.out.println(item1.equals(item2));         // false
		System.out.println(item2.equals(item3));         // true
		System.out.println(item1.equals(recipe3));       // false
		System.out.println(recipe3.equals(item1));       // false
		System.out.println(recipe3.equals(recipe3_also));// true
	}

}

/*
EXPECTED OUTPUT:


false
true
wood
0
false
true
nail
0
true
false
spear
4
true
false
spearWall
5
null
null
null
shuriken
nailbat
null
toString: name: wood, cost: 2.5, parts: null
toString: name: nail, cost: 1.5, parts: null
toString: name: nailbat, cost: 0.0, parts: [wood, nail, nail, nail]
toString: name: shuriken, cost: 0.0, parts: [tape, nail, nail, nail, nail]
false
false
true
false
false
true


 */