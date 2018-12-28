import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        final String[] C1 = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        final String[] C2 = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        final String[] C3 = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

        Scanner inputReader = new Scanner(System.in);
        int x = inputReader.nextInt();

        if (x == 0)
        {
            System.out.println("zero");
        }
        else if (x < 10)
        {
            System.out.println(C1[x]);
        }
        else if (x < 20)
        {
            System.out.println(C2[x % 10]);
        }
        else
        {
            if (x % 10 == 0)
                System.out.println(C3[x / 10]);
            else
                System.out.println(C3[x / 10] + "-" + C1[x % 10]);
        }
    }
}
