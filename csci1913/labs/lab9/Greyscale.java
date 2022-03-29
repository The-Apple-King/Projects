public class Greyscale {

    public RGBImage greyscale(RGBImage image){
            RGBImage retVal = new RGBImage(image.getWidth(), image.getHeight());
            for (int x = 0; x < image.getWidth(); x++) {
                for (int y = 0; y < image.getHeight(); y++) {
                    retVal.setColor(x, y, do_transform(x, y, image.getColor(x, y), image));
                }
            }
            return retVal;
    }

    protected RGBColor do_transform(int x, int y, RGBColor originalColor, RGBImage image) {
        int average = originalColor.getRed() + originalColor.getGreen() + originalColor.getBlue();
        avrage/=3;
        return new RGBColor(average, average, average);
    }
}