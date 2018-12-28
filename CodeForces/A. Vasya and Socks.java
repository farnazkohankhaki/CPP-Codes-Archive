import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner inputReader = new Scanner(System.in);
        int n, m;
        n = inputReader.nextInt();
        m = inputReader.nextInt();

        int numOfSocks = n;
        for (int i = 1; ; i++)
        {
            if (i % m != 0)
                numOfSocks--;
            if (numOfSocks == 0) {
                System.out.println(i);
                break;
            }
        }
    }
}