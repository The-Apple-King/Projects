//Owen Swearingen
//lab 9
public class ColorPallet extends Transformation {

    private RGBColor[] pallet;

    /**
     * instantiates the ColorPallet transformation
     * @param pallet list of colors
     */
    public ColorPallet(RGBColor[] pallet){
        this.pallet = pallet;
    }

    /**
     * finds the most similar color in pallet and sets the color to that RGB value
     */
    protected RGBColor do_transform(int x, int y, RGBColor originalColor, RGBImage image){
        double minDistance = Integer.MAX_VALUE;
        int minLocation = 0;
        for (int i = 0; i < pallet.length; i++) {
            if(RGBColor.distance(pallet[i], originalColor) < minDistance){
                minDistance = RGBColor.distance(pallet[i], originalColor);
                minLocation = i;
            }
        }
        return pallet[minLocation];
    }
}