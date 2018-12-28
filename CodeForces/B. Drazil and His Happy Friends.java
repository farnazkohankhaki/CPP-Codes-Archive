import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner inputReader = new Scanner(System.in);
        int m, n, g, b;
        final int MAX_N = 200 + 20;
        boolean[] x = new boolean[MAX_N], y = new boolean[MAX_N];
        m = inputReader.nextInt();
        n = inputReader.nextInt();
        b = inputReader.nextInt();

        for (int i = 0; i < b; i++)
        {
            int tmp;
            tmp = inputReader.nextInt();
            x[tmp] = true;
        }
        g = inputReader.nextInt();
        for (int i = 0; i < g; i++)
        {
            int tmp;
            tmp = inputReader.nextInt();
            y[tmp] = true;
        }
        for (int i = 0; i < 4 * m * n; i++)
        {
            if (!y[i % n] && !x[i % m])
                continue;
            y[i % n] = true;
            x[i % m] = true;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (y[i])
                cnt++;
        for (int i = 0; i < m; i++)
            if (x[i])
                cnt++;
        if (cnt == n + m)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
