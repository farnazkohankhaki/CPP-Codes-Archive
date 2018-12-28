import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner inputReader = new Scanner(System.in);
        int n = inputReader.nextInt(), k = inputReader.nextInt(), ans = 0;
        ArrayList<Integer> x = new ArrayList<Integer>();
        for (int i = 0; i < n; i++)
            x.add(inputReader.nextInt() - 1);
        Collections.sort(x);
        while(x.size() > 0)
        {
            ans += 2 * x.get(x.size() - 1);
            int size = x.size();
            for (int i = size - 1; i >= size - Math.min(k, size); i--)
                x.remove(i);
        }
        System.out.println(ans);
    }
}