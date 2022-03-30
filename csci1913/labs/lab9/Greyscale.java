//Owen Swearingen
//lab 9
public class Greyscale extends Transformation {

    /**
     * takes the average of the RGB values and sets R, G, and B to the average to make image greyscale
     */
    protected RGBColor do_transform(int x, int y, RGBColor originalColor, RGBImage image) {
        int average = originalColor.getRed() + originalColor.getGreen() + originalColor.getBlue();
        average /= 3;
        return new RGBColor(average, average, average);
    }
}