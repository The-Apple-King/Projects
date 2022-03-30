//Owen Swearingen
//lab 9
public class Brighten extends Transformation {

    private int brightness;
    /**
     * instantiates brightness transformation
     * @param brightness brightness value, positive is brighter, negative is darker
     */
    public Brighten(int brightness) {
        this.brightness = brightness;
    }

    /**
     * adds the brightness value to the R, G, and B colors to make the image brighter or darker
     */
    protected RGBColor do_transform(int x, int y, RGBColor originalColor, RGBImage image) {
        return new RGBColor(originalColor.getRed() + brightness, originalColor.getGreen() + brightness,
                originalColor.getBlue() + brightness);
    }
}