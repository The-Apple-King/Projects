
public class TestMyDate {

	public static void main(String[] args) {
		
		// Test 1 -  Test if the data type implements Comparable
		Comparable<MyDate> comtest1 = new MyDate(2022, 5, 3);
		Comparable<MyDate> comtest2 = new MyDate(1, 2, 3);
		
		System.out.println(comtest1);                        // 2022-5-3
		System.out.println(comtest2);                        // 1-2-3
		
		// Test 2 -  Test if compareTo is correct
		MyDate mydate0 = new MyDate(2011, 4, 1);
		MyDate mydate1 = new MyDate(2030, 4, 1);
		MyDate mydate2 = new MyDate(2030, 4, 1);
        System.out.println(mydate1.compareTo(mydate2) == 0); // true
        System.out.println(mydate1.compareTo(mydate2) < 0);  // false
        System.out.println(mydate1.compareTo(mydate2) > 0);  // false
        
        // different year
        System.out.println(mydate0.compareTo(mydate1) == 0); // false
        System.out.println(mydate0.compareTo(mydate1) < 0);  // true
        System.out.println(mydate0.compareTo(mydate1) > 0);  // false
		
        //same year different month
        MyDate mydate3 = new MyDate(2030, 5, 1);
        System.out.println(mydate3.compareTo(mydate2) == 0); // false
        System.out.println(mydate3.compareTo(mydate2) > 0);  // true
        System.out.println(mydate3.compareTo(mydate2) < 0);  // false
        
        // same year/month different day
        MyDate mydate4 = new MyDate(2030, 4, 12);
        System.out.println(mydate4.compareTo(mydate2) == 0); // false
        System.out.println(mydate4.compareTo(mydate2) > 0);  // true
        System.out.println(mydate4.compareTo(mydate2) < 0);  // false


        System.out.println(mydate2.compareTo(mydate4) == 0); // false
        System.out.println(mydate2.compareTo(mydate4) > 0);  // false
        System.out.println(mydate2.compareTo(mydate4) < 0);  // true
        
        
        // Test 3 - if Equals is overloaded correctly
        System.out.println(mydate1.equals(comtest1));       // false
        System.out.println(mydate1.equals(mydate2));        // true
        
        System.out.println(mydate1.equals(mydate0));        // false
        System.out.println(mydate1.equals(mydate3));        // false
        System.out.println(mydate3.equals(mydate4));        // false

        System.out.println(mydate3.equals(null));           // false
        //System.out.println(mydate3.equals("today"));        // false
        //System.out.println(mydate3.equals("2030-5-1"));     // false

        
        
	}

}



//Expected prints:
/*

2022-5-3
1-2-3
true
false
false
false
true
false
false
true
false
false
true
false
false
false
true
false
true
false
false
false
false
false
false

*/
