import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int[] a = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int n;
        n = input.nextInt();
        String s = input.next();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') {
            } else if (s.charAt(i) == '1') {
            } else if (s.charAt(i) == '2') {
                a[2]++;
            } else if (s.charAt(i) == '3') {
                a[3]++;
            } else if (s.charAt(i) == '4') {
                a[2] += 2;
                a[3]++;
            } else if (s.charAt(i) == '5') {
                a[5]++;
            } else if (s.charAt(i) == '6') {
                a[3]++;
                a[5]++;
            } else if (s.charAt(i) == '7') {
                a[7]++;
            } else if (s.charAt(i) == '8') {
                a[2] += 3;
                a[7]++;
            } else if (s.charAt(i) == '9') {
                a[2]++;
                a[3] += 2;
                a[7]++;
            }
        }
        String ans = "";
        for (int i = 9; i >= 2; i--)
        {
            for (int j = 0; j < a[i]; j++)
                ans += (char)(i + '0');
        }
        System.out.println(ans);
    }
}
