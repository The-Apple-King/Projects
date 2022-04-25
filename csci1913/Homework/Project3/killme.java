import java.util.Random;

public class killme {
    
    public static void main(String[] args) {
        int[] letters = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int totLetters = 2;

        //stuff to test
        while(true){
        if (totLetters > 0) {
            Random rand = new Random();
            int num = 1+rand.nextInt(totLetters);
            int accum = 0;
            int loc = -1;
            while(accum < num/* || (loc < 26 && letters[loc] == 0)*/) {//letters[loc] == 0 is fucking this
                loc++;
                accum += letters[loc];
            }
            if(num == accum){
                System.out.println("num == accum");
            }
            if(loc <= 25){ // fix this shit alex is dumb and wrote it wrong and its definitely not your fault
                System.out.println((char) (loc + 97));
            }else if(loc == 26){
                System.out.println(LetterSample.STOP);
            }else{
                System.out.println("fucked");
            }
        }
        System.out.println("endl");
    }
}
}
