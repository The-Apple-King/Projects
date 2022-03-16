/**
 * Polygon class file.
 * CSCI 1913.
 * Written by Min Namgung and Daniel Kluver
 * Provided.
 *
 * In general geometry theory -- a Polygon is any shape made by connecting a
 * series of straight lines into a complete shape. A triangle, square,
 * rectangle, octagon, etc. can all be represented as a polygon with the right
 * number of points. However a circle cannot be represented as a circle is not
 * made of straight lines.
 *
 * A polygon is represented as an array of Point objects. -- the points are
 * connected in series so points[0] is connected to points[1] is connected to
 * points[2] etc. To make a closed shape the first and last points in the array
 * are also connected.
 */

public class Polygon {
    private Point[] points;

    /**
     * Create a Polygon from an array of points.
     * @param points a non-null array of points, which should have length 3 or more.
     */
    public Polygon(Point[] points) {
        this.points = points;
    }

    /**
     * Get the number of points in the polygon.
     * @return
     */
    public int getNumPoints() {
        if (points != null)
            return points.length;
        else
            return 0;
    }

    /**
     * Get a specific point in the polygon
     * @param index a number from 0 to numPoints-1
     * @return the Point object as indicated by index OR the special value null
     *     if the index is out of range
     */
    public Point getPoint(int index) {
        if (points == null)
            return null;
        else if (points.length <= index || index < 0)
            return null;
        else
            return points[index];
    }

    /**
     * get a string representation of the polygon.
     */
    public String toString() {
        String retval = "";
        for (int i = 0; i < points.length; i++) {
            if (i != 0) {
                retval += " -- ";
            }
            retval += points[i];
        }
        return retval;
    }

    public void move(double dx, double dy) {
        for (Point p : points) {
            p.move(dx, dy);
        }
    }

    /**
     * computes the left-most and top-most locations used in this shape.
     * Note -- this is not guaranteed to be one of the points in the shape, frequently it won't be.
     * Instead it returns a point whose x value is the left-most (minimum) x value and y value is the top-most (minimum)
     * y value. (Yes, I'm aware that's a little counter-intuitive, computer graphics often makes "down" mean "larger y
     * values" despite normal practice in the field of mathematics)
     */
    public Point getTopLeft() {
        double x = points[0].getX();
        double y = points[0].getY();
        for (Point p : points) {
            if (p.getX() < x) {
                x = p.getX();
            }
            if (p.getY() < y) {
                y = p.getY();
            }
        }
        return new Point(x, y);
    }

    /**
     * computes the right-most and bottom-most locations used in this shape.
     * Note -- this is not guaranteed to be one of the points in the shape, frequently it won't be.
     * Instead it returns a point whose x value is the right-most (maximum) x value and y value is the bottom-most (maximum)
     * y value. (Yes, I'm aware that's a little counter-intuitive, computer graphics often makes "down" mean "larger y
     * values" despite normal practice in the field of mathematics)
     */
    public Point getBottomRight() {
        double x = points[0].getX();
        double y = points[0].getY();
        for (Point p : points) {
            if (p.getX() > x) {
                x = p.getX();
            }
            if (p.getY() > y) {
                y = p.getY();
            }
        }
        return new Point(x, y);
    }

    /**
     * Rotate the shape around a given point.
     * @param theta the angle to rotate by (given in degrees)
     * @param center the center of the rotation
     */
    public void rotateAroundPoints(double theta, Point center) {
    	move(-center.getX(), -center.getY());
        for (Point p : points) {
            p.rotateAroundOrigin(theta);
        }
        move(center.getX(), center.getY());
    }
}