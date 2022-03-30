//Owen Swearingen
//lab 9
public class AddBorder extends Transformation {

    private int width;
    private RGBColor borderColor;

    /**
     * instantiates the AddBorder transformation with the width and color of the border
     * 
     * @param width the width of the border
     * @param borderColor the color of the border
     */
    public AddBorder(int width, RGBColor borderColor){
        this.width = width;
        this.borderColor = borderColor;
    }
    
    /**
     * modifies the outer edge of the image to create a border setting it to borderColor
     */
    protected RGBColor do_transform(int x, int y, RGBColor originalColor, RGBImage image) {
        if(x<width || y<width || (x >= image.getWidth()-width && x < image.getWidth()) || (y >= image.getHeight()-width && y < image.getHeight())){
            return borderColor;
        }
        else{
            return originalColor;
        }
    }
}