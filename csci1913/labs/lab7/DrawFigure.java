import java.awt.Color;

/**
 * Draw Figure class file.
 * CSCI 1913.
 * Written by Owen Swearingen
 * Provided.
 */
public class DrawFigure {
    static ShapeDrawer pp = new ShapeDrawer(100, 100);

    public static void main(String[] args) {
        //draws stars
        pp.setStroke(Color.yellow);
        pp.setFill(Color.yellow);
        stars();

        //draws moon
        Point p = new Point(10, 10);
        Circle moon = new Circle(p, 10);
        pp.setStroke(Color.WHITE);
        pp.setFill(Color.white);
        pp.draw(moon);
        //draws moon shadow
        Point p1 = new Point(15, 10);
        Circle moonShawdow = new Circle(p1, 10);
        pp.setStroke(Color.BLACK);
        pp.setFill(Color.BLACK);
        pp.draw(moonShawdow);

        // creates a shadow for the house
        pp.setFill(Color.GRAY);
        pp.setStroke(Color.gray);
        for (int i = 25; i < 35; i++) {
            Polygon shadow = buildHouse(i, 100);
            pp.draw(shadow);
        }

        // creates the house
        Polygon house = buildHouse(25, 100);
        pp.setStroke(Color.WHITE);
        pp.setFill(Color.WHITE);
        pp.draw(house);

        // draw door
        pp.setStroke(Color.darkGray);
        pp.setFill(Color.darkGray);
        Polygon door = door(40, 100);
        pp.draw(door);
        pp.setStroke(Color.blue);
        pp.setFill(Color.blue);
        pp.draw(new Point(43, 94));

        pp.writeToFile("house.png");
    }

    /**
     * creates a house shaped polygon
     * @param x bottom left x position
     * @param y bottom left y position
     * @return a polygon in the shape of a house
     */
    public static Polygon buildHouse(int x, int y) {
        Point p1 = new Point(x, y);
        Point p2 = new Point(x + 30, y);
        Point p3 = new Point(x + 30, y - 20);
        Point p4 = new Point(x + 15, y - 40);
        Point p5 = new Point(x, y - 20);
        Point houseShape[] = new Point[] { p1, p2, p3, p4, p5 };
        return new Polygon(houseShape);
    }

    /**
     * creates a rectangle for the door
     * @param x bottom left x position
     * @param y bottom left y position
     * @return a rectangle
     */
    public static Polygon door(int x, int y) {
        Point p1 = new Point(x, y);
        Point p2 = new Point(x + 5, y);
        Point p3 = new Point(x + 5, y - 10);
        Point p4 = new Point(x, y - 10);
        Point door[] = new Point[] { p1, p2, p3, p4 };
        return new Polygon(door);
    }

    /**
     * draws 35 stars randomly across the sky
     */
    public static void stars() {
        for (int i = 0; i < 35; i++) {
            int x = (int) (Math.random() * 100);
            int y = (int) (Math.random() * 75);
            pp.draw(new Point(x, y));
        }
    }
}
