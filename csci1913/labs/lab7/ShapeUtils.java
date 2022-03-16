/**
 * Shape Drawer class file.
 * CSCI 1913.
 * Written by Owen Swearingen
 * Provided.
 */
public class ShapeUtils {
    /**
     * uses distance formula to find distance between points
     * @param p1 point 1
     * @param p2 point 2
     * @return distance between two points
     */
    public static double distance(Point p1, Point p2) {
        double diffX = p2.getX() - p1.getX();
        double diffY = p2.getY() - p1.getY();
        diffX *= diffX;
        diffY *= diffY;
        return Math.sqrt(diffX + diffY);
    }

    /**
     * adds up all x's and y's and averages them to find center
     * @param poly the shape to find center of
     * @return average of all points locations
     */
    public static Point getCenter(Polygon poly) {
        if (poly.getNumPoints() > 0) {
            double x = 0;
            double y = 0;
            for (int i = 0; i < poly.getNumPoints(); i++) {
                x += poly.getPoint(i).getX();
                y += poly.getPoint(i).getY();
            }
            return new Point(x / poly.getNumPoints(), y / poly.getNumPoints());
        }
        return null;
    }

    /**
     * uses distance formula between each point of the polygon
     * @param poly polygon to find perimeter of
     * @return length of the perimeter
     */
    public static double getPerimeter(Polygon poly) {
        double perimeter = 0;
        for (int i = 0; i < poly.getNumPoints() - 1; i++) {
            perimeter += distance(poly.getPoint(i), poly.getPoint(i + 1));
        }
        perimeter += distance(poly.getPoint(0), poly.getPoint(poly.getNumPoints()-1));
        return perimeter;
    }

    /**
     * uses circumference formula to find circumference of a circle
     * @param c cirlce to find circumference of
     * @return circumference
     */
    public static double getPerimeter(Circle c) {
        return (Math.PI * (2*c.getRadius()));
    }

    /**
     * uses area formula to find area of circle
     * @param c circle to find the area of
     * @return area
     */
    public static double getArea(Circle c) {
        return Math.PI * c.getRadius()*c.getRadius();
    }
    /**
     * uses distance formula to find distance from center then 
     * tests if both radii added together are more than the distance
     * @param c1 circle 1
     * @param c2 circle 2
     * @return if there is overlap
     */
    public static boolean isThereOverlap(Circle c1, Circle c2) {
        double distance = distance(c1.getCenter(), c2.getCenter());
        return distance < (c1.getRadius()+c2.getRadius());
    }

    /**
     * uses radius and center to find top left corner
     * @param c circle
     * @return top left of circle
     */
    public static Point getTopLeft(Circle c) {
        double x = c.getCenter().getX()-c.getRadius();
        double y = c.getCenter().getY()-c.getRadius();
        return new Point(x, y);
    }

    /**
     * uses radius and center to find bottom right corner
     * @param c circle
     * @return bottom right of circle
     */
    public static Point getBottomRight(Circle c) {
        double x = c.getCenter().getX()+c.getRadius();
        double y = c.getCenter().getY()+c.getRadius();
        return new Point(x, y);
    }
}