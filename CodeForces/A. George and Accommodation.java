import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner inputReader = new Scanner(System.in);
        int n;
        n = inputReader.nextInt();
        int[] roomP = new int[n];
        int[] roomQ = new int[n];
        for (int i = 0; i < n ; i++) {
            roomP[i] = inputReader.nextInt();
            roomQ[i] = inputReader.nextInt();
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (roomQ[i] - roomP[i] > 1)
                cnt++;

        System.out.println(cnt);
    }
}