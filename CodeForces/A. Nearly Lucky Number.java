import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner inputReader = new Scanner(System.in);
        long n;
        n = inputReader.nextLong();
        int cnt = 0;
        while (n > 0) {
            if (n % 10 == 7 || n % 10 == 4)
                cnt++;
            n /= 10;
        }
        if (cnt == 4 || cnt == 7)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
