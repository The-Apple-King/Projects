import java.time.LocalDate;
import java.util.Scanner;

/**
 * This class represents a date as three integers.
 * It enforces the class-rule that the private ints day, month, and year, are always "valid".
 * (so >=1 and < the appropriate upper limit)
 * (NOTE -- I can think of at least one way to break this rule, but it's pretty obscure.
 * If you figure out how to break the rule congrats!)
 */
public class MyDate {
    private static final int[] DAYS_PER_MONTH = {31,28,31,30,31,30,31,31,30,31,30,31};

    private int day, month, y;

    public MyDate(int year, int month, int day) {
        // directly set year, because there's no error checking here.
        this.y = year;
        // reuse setMonth and setDay to get the error checking for free!
        setMonth(month);
        setDay(day);
    }

    public int getYear() {
        return y;
    }

    public int getMonth() {
        return month;
    }

    public int getDay() {
        return day;
    }

    public boolean isLeapYear() {
        if (y%4 == 0) {
            return true;
        } else if (y%100 == 0) {
            return false;
        } else if (y % 400 == 0) {
            return true;
        } else {
            return false;
        }
    }

    public void setYear(int year) {
        this.y = year;
    }

    public void setMonth(int month) {
        // check if month is valid
        if (0 < month && month <= 12) {
            this.month = month;
        } else {
            System.out.println("ERROR: Not setting month to out-of-range month.");
        }
    }

    public int daysThisMonth() {
        if (isLeapYear() && month == 2) {
            return 29;
        } else {
            return DAYS_PER_MONTH[month-1]; // -1 because 0-indexed.
        }
    }

    public void setDay(int day) {
        if (0 < day && day <= daysThisMonth()) {
            this.day = day;
        } else {
            System.out.println("ERROR: Not setting day to out-of-range date.");
        }
    }

    public MyDate tomorrow() {
        if (day == 31 && month == 12) {
            return new MyDate(1, 1, y+1);
        } else if (day == daysThisMonth()) {
            return new MyDate(1, month+1, y);
        } else {
            return new MyDate(day+1, month, y);
        }
    }

    //-----------------------------------------fix-----------------------------------

    public boolean isBefore(MyDate other) {
        if (y < other.y) {
            // we are in an earlier year
            return true;
        } else if (y == other.y && month < other.month) {
            // same year, earlier month
            return true;
        } else if (y == other.y && month == other.month && day < other.day) {
            // same year and month, earlier day.
            return true;
        } else {
            return false;
        }
    }

    public boolean isEqualTo(MyDate other) {
        return y==other.y && month == other.month && day == other.day;
    }

    //----------------------------------------fix-----------------------------------------

    @Override
    public String toString() {
        // yyyy-mm-dd Kluver's personal favorite.
        return y+"-"+month+"-"+day;
    }

    public static MyDate fromString(String input) {
        input = input.replace('-',' ');
        Scanner s = new Scanner(input);
        int y = s.nextInt();
        int m = s.nextInt();
        int d = s.nextInt();
        return new MyDate(d, m, y);
    }

    public static int daysBetween(MyDate date1, MyDate date2) {

        if (date1.isEqualTo(date2)) {
            return 0;
        } else {
            if (date2.isBefore(date1)) {
                // we want date1 < date2 so swap the variables (leaving objects alone)
                MyDate tmp = date1;
                date1 = date2;
                date2 = date1;
            }
            int count = 0;
            // This is a really inefficient way to do this, but whatever.
            // we're here to lean java, not calendars.
            while (! date1.isEqualTo(date2)) {
                count++;
                date1 = date1.tomorrow();
            }
            return count;
        }
    }

    public static MyDate today() {
        // OK -- I'm "cheating" a bit here to make this function.
        // Using the Java LocalDate object to get the date.
        // we _could_ have used this code from the start, but I wouldn't at this point -- it's a lot more complicated
        // than it needs to be.
        LocalDate date = LocalDate.now();
        return new MyDate(date.getDayOfMonth(), date.getMonthValue(), date.getYear());
    }
}
