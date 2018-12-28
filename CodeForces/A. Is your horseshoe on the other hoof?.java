import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner inputReader = new Scanner(System.in);
        int[] a = new int[4], comp = new int[4];
        for (int i = 0; i < 4; i++) {
            a[i] = inputReader.nextInt();
            comp[i] = i;
        }

        int cnt = 0;
        for (int i = 1; i < 4; i++) {
            for (int j = 0; j < i; j++)
                if (a[i] == a[j]) {
                    comp[i] = comp[j];
                    cnt++;
                    break;
                }
        }

    System.out.println(cnt);

    }
}