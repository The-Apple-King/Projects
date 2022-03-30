//Owen Swearingen
//lab 9
public class Stamp extends Transformation {

    private RGBImage stamp;

    /**
     * instantiates the Stamp Transformation
     * @param image the stamp to use
     */
    public Stamp(RGBImage image) {
        stamp = image;
    }
    /**
     * finds the average of each RGB value for the original image and the stamp and returns it 
     */
    protected RGBColor do_transform(int x, int y, RGBColor originalColor, RGBImage image) {
        if (x < stamp.getWidth() && y < stamp.getHeight()) {
            int red = (originalColor.getRed() + stamp.getColor(x, y).getRed()) / 2;
            int green = (originalColor.getGreen() + stamp.getColor(x, y).getGreen()) / 2;
            int blue = (originalColor.getBlue() + stamp.getColor(x, y).getBlue()) / 2;
            return new RGBColor(red, green, blue);
        } else {
            return originalColor;
        }
    }
}