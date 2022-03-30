//Owen Swearingen
//lab 9
public class TransformationUtils extends Transformation {

    /**
     * loops through tranformation array and applies them to the file at inptFle and then saves and outputs them to otpFle
     * @param transformations array of transformations
     * @param inptFle string name of input
     * @param otpFle string name of output
     */
    public static void transformMany(Transformation[] transformations, String inptFle, String otpFle) {
        RGBImage image = RGBImageUtil.load(inptFle);
        for (int i = 0; i < transformations.length; i++) {
            image = transformations[i].transform(image);
        }
        RGBImageUtil.saveImage(image, otpFle);
    }
}