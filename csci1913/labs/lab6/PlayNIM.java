import java.util.Scanner;
import java.util.Arrays;

public class PlayNIM {

    public static void main(String[] args) {

        int[] tokenCount = NIM.createTokenCounts(5, 4);
        System.out.println(Arrays.toString(tokenCount));
        try (Scanner object = new Scanner(System.in)) {

            while (!NIM.isOver(tokenCount)) {
                String row = "a";
                String takes = "a";

                while (!NIM.isValidMove(tokenCount, row, takes)) {
                    NIM.drawBoard(tokenCount);

                    System.out.println();
                    System.out.println("Choose a row 1 - ");
                    row = object.nextLine();

                    System.out.println("How many tokens to take, 0 to 3 (no more than are available) ");
                    takes = object.nextLine();

                    if (!NIM.isValidMove(tokenCount, row, takes)) {
                        System.out.println("Invalid move");
                    }
                }

                int intRow = Integer.parseInt(row) - 1;
                int intTakes = Integer.parseInt(takes);
                tokenCount = NIM.update(tokenCount, intRow, intTakes);
            }

            System.out.println("Game over, the last player lost!");
        }
    }

}
