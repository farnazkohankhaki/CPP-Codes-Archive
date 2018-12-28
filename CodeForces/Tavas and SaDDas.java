import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner inputReader = new Scanner(System.in);
        String s = inputReader.next(), t = "";
        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) == '4')
                t += '0';
            else
                t += '1';

        int x = Integer.parseInt(t, 2);
        if (s.length() == 1)
            System.out.println(x + 1);
        else
            System.out.println(x + (int)Math.pow(2, s.length()) - 1);
    }
}
