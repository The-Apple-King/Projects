public class Brighten(){

    private int brightness

    public Brighten(int brightness){
        this.brightness = brightness
    }

    public RGBImage brightenImage(RGBImage image){
        RGBImage retVal = new RGBImage(image.getWidth(), image.getHeight());
        for (int x = 0; x < image.getWidth(); x++) {
            for (int y = 0; y < image.getHeight(); y++) {
                retVal.setColor(x, y, do_transform(x, y, image.getColor(x, y), image));
            }
        }
        return retVal;
    }
    protected RGBColor do_transform(int x, int y, RGBColor originalColor, RGBImage image) {
        
        return new RGBColor(originalColor.getRed()+brightness, originalColor.getGreen()+brightness, originalColor.getBlue()+brightness);
    }
}