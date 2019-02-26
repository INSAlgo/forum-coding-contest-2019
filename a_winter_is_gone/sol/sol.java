import java.util.Scanner;

public class a_winter_is_gone {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int best_arrow = 1;
        double best_dst = Double.MAX_VALUE;
        for(int i=1; i<=n; ++i) {
            double x, y;
            x = sc.nextDouble();
            y = sc.nextDouble();
            if(Math.sqrt(x*x + y*y) < best_dst) {
                best_dst = Math.sqrt(x*x + y*y);
                best_arrow = i;
            }
        }
        System.out.println(best_arrow);
    }
}