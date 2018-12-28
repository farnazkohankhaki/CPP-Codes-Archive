import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner inputReader = new Scanner(System.in);
        int y;
        y = inputReader.nextInt();
        for (int i = y + 1; ; i++) {
            int[] dig = new int[10];
            boolean isAns = true;
            for (int j = 0; j < 10; j++)
                dig[j] = 0;
            int tmp = i;
            while (tmp > 0) {
                dig[tmp % 10]++;
                tmp /= 10;
            }
            for (int j = 0; j < 10; j++)
                if (dig[j] > 1)
                    isAns = false;
            if (isAns) {
                System.out.println(i);
                break;
            }
        }
    }
}
