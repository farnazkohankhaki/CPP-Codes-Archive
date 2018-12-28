import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner inputReader = new Scanner(System.in);
        int a, b;
        a = inputReader.nextInt();
        b = inputReader.nextInt();

        int cnt = a;
        int burned = a;
        while(burned >= b)
        {
            cnt += burned / b;
            burned = burned / b + burned % b;
        }

        System.out.println(cnt);
    }
}