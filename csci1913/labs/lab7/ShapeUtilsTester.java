public class ShapeUtilsTester {
    public static void main(String[] args) {
        // Tests related to circle functions
		Circle c = new Circle(new Point(4, 5), 7);

		System.out.println("Circle Function Tests 1");
		// writing the tests this way so that we ensure these functions return double.
		double d = ShapeUtils.getPerimeter(c);
        System.out.println(d);                           // 43.982297150257104
        d = ShapeUtils.getArea(c);
        System.out.println(d);                           // 153.93804002589985
        Point p = ShapeUtils.getBottomRight(c);
        System.out.println(p);                           // (11.0, 12.0)
        p = ShapeUtils.getTopLeft(c);
        System.out.println(p);                           // (-3.0, -2.0)

        System.out.println("Circle Function Tests 2");
		c.setCenter(new Point(6.3, 9.1));
        System.out.println(ShapeUtils.getPerimeter(c));  // 43.982297150257104
        System.out.println(ShapeUtils.getArea(c));       // 153.93804002589985
        System.out.println(ShapeUtils.getBottomRight(c));// (13.3, 16.1)
        System.out.println(ShapeUtils.getTopLeft(c));    // (-0.7, 2.1)
                                                         // This might show up with a lot more decimal places and sound rounding issues
                                                         // this happens with doubles and we only check for accuracy within a range of 0.00001

        System.out.println("Circle Function Tests 3");
        c.setRadius(15);
        System.out.println(ShapeUtils.getPerimeter(c));  // 94.24777960769379
        System.out.println(ShapeUtils.getArea(c));       // 706.8583470577034
        System.out.println(ShapeUtils.getBottomRight(c));// (21.3, 24.1)
        System.out.println(ShapeUtils.getTopLeft(c));    // (-8.7, -5.9)

        System.out.println("Circle Function Tests 4");
        c.setRadius(0);
        System.out.println(ShapeUtils.getPerimeter(c));  // 0
        System.out.println(ShapeUtils.getArea(c));       // 0
        System.out.println(ShapeUtils.getBottomRight(c));// (6.3, 9.1)
        System.out.println(ShapeUtils.getTopLeft(c));    // (6.3, 9.1)

        System.out.println("IsThereOverlap tests");
        // easy no -- two circles way apart
        Circle c1 = new Circle(new Point(-10, -10), 0.1);
        Circle c2 = new Circle(new Point(10, 8.2), 1);
        System.out.println(ShapeUtils.isThereOverlap(c1,c2)); // false
        // easy yes -- it's the same circle twice
        System.out.println(ShapeUtils.isThereOverlap(c1,c1)); // true
        // more interesting no -- close, but not touching
        c1 = new Circle(new Point(0, 0), 1);
        c2 = new Circle(new Point(2, 0), 0.99);
        System.out.println(ShapeUtils.isThereOverlap(c1,c2)); // false
        // easy overlapping yes (draw them if you don't believe me!)
        c1 = new Circle(new Point(0, 0), 1);
        c2 = new Circle(new Point(1, 1), 1);
        System.out.println(ShapeUtils.isThereOverlap(c1,c2)); // true
        // Interesting case -- they are tangent -- touching at one point
        // we don't call that overlapping.
        c1 = new Circle(new Point(0, 0), 1);
        c2 = new Circle(new Point(0, -2), 1);
        System.out.println(ShapeUtils.isThereOverlap(c1,c2)); // false
        // Another interesting case -- c2 is entirely inside c1!
        c1 = new Circle(new Point(10, 15), 20);
        c2 = new Circle(new Point(3.1, 2.4), 3);
        System.out.println(ShapeUtils.isThereOverlap(c1,c2)); // true


        System.out.println("getCenter and get Perimeter tests");
        // Polygon function tests:
        Point[] points = new Point[3];
        points[0] = new Point(0.0, 0.0);
        points[1] = new Point(1.0, 0.0);
        points[2] = new Point(2.0, 3.0);
        Polygon polygon1 = new Polygon(points);
        Point p0 = ShapeUtils.getCenter(polygon1);
        System.out.println(p0);                          // (1.0, 1.0)

        Point[] points2 = new Point[4];
        points2[0] = new Point(12.0, 15.0);
        points2[1] = new Point(13.0, -14.0);
        points2[2] = new Point(-20.0, 18.0);
        points2[3] = new Point(-16.0, -28.0);
        Polygon polygon2 = new Polygon(points2);
        Point p1 = ShapeUtils.getCenter(polygon2);
        System.out.println(p1);                          // (-2.75, -2.25)

        points2 = new Point[5];
        points2[0] = new Point(12.0, 15.0);
        points2[1] = new Point(13.0, -14.0);
        points2[2] = new Point(-20.0, 18.0);
        points2[3] = new Point(-10.0, 17.0);
        points2[4] = new Point(-16.0, -28.0);
        polygon2 = new Polygon(points2);
        Point p2 = ShapeUtils.getCenter(polygon2);
        System.out.println(p2);                          // (-4.2, 1.6)


        points2 = new Point[3];
        points2[0] = new Point(12.0, 15.0);
        points2[1] = new Point(13.0, -14.0);
        points2[2] = new Point(-20.0, 18.0);
        polygon2 = new Polygon(points2);
        double d1 = ShapeUtils.getPerimeter(polygon2);
        System.out.println(d1);                          // 107.12493335531502


        points2 = new Point[4];
        points2[0] = new Point(12.0, 15.0);
        points2[1] = new Point(13.0, -14.0);
        points2[2] = new Point(-20.0, 18.0);
        points2[3] = new Point(-16.0, -28.0);
        polygon2 = new Polygon(points2);
        d1 = ShapeUtils.getPerimeter(polygon2);
        System.out.println(d1);                          // 172.4709679604694

        points2 = new Point[5];
        points2[0] = new Point(12.0, 15.0);
        points2[1] = new Point(13.0, -14.0);
        points2[2] = new Point(-20.0, 18.0);
        points2[3] = new Point(-10.0, 17.0);
        points2[4] = new Point(-16.0, -28.0);
        polygon2 = new Polygon(points2);
        d1 = ShapeUtils.getPerimeter(polygon2);
        System.out.println(d1);                          // 181.74549591039417

        System.out.println("Point functions");
        //Point function tests:
        p1 = new Point(1.0, 1.0);
        p2 = new Point(1.0, 0.0);
        d1 = ShapeUtils.distance(p1, p2);
        System.out.println(d1);                          // 1.0

        Point p3 = new Point(23.6, -34.5);
        double d2 = ShapeUtils.distance(p1, p3);
        System.out.println(d2);                          //42.083369636948035

        p1 = new Point(1.0, 1.0);
        Point p4 = new Point(-23.6, 17.5);
        double d3 = ShapeUtils.distance(p1, p4);
        System.out.println(d3);                          // 29.621107339193113
    }
}

/*
Circle Function Tests 1
43.982297150257104
153.93804002589985
(11.0, 12.0)
(-3.0, -2.0)
Circle Function Tests 2
43.982297150257104
153.93804002589985
(13.3, 16.1)
(-0.7, 2.1)
Circle Function Tests 3
94.24777960769379
706.8583470577034
(21.3, 24.1)
(-8.7, -5.9)
Circle Function Tests 4
0.0
0.0
(6.3, 9.1)
(6.3, 9.1)
IsThereOverlap tests
false
true
false
true
false
true
getCenter and get Perimeter tests
(1.0, 1.0)
(-2.75, -2.25)
(-4.2, 1.6)
107.12493335531502
172.4709679604694
181.74549591039417
Point functions
1.0
42.083369636948035
29.621107339193113
 */