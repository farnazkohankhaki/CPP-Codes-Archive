import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner inputReader = new Scanner(System.in);
        int a, b, s;
        a = inputReader.nextInt();
        b = inputReader.nextInt();
        s = inputReader.nextInt();
        long t = (long)Math.abs(a) + (long)Math.abs(b);
        t -= s;
        if (t <= 0 && t % 2 == 0)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
