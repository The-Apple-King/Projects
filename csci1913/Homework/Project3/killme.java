import java.util.Random;

public class killme {
    
    public static void main(String[] args) {
        int[] letters = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
        int totLetters = 81;

        //stuff to test
        while(true){
        if (totLetters > 0) {
            Random rand = new Random();
            int num = rand.nextInt(totLetters);
            int accum = 0;
            int loc = 0;
            while(accum < num || (loc < 26 && letters[loc] == 0)) {
                accum += letters[loc++];
            }
            loc --;
            if(loc <= 25){ // fix this shit alex is dumb and wrote it wrong and its definitely not your fault
                System.out.println((char) (loc + 97));
            }else if(loc == 26){
                System.out.println(LetterSample.STOP);
            }else{
                System.out.println("broked");
            } 
        }
        System.out.println("endl");
    }
}
}
