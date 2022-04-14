import java.util.Scanner;

public class Gcd {

    static int gcd(int a, int b){
        return a == 0 ? b : gcd(b%a, a);
    }

    public static void main(String[] args) {
        System.out.println(gcd(10, 5));
    } 
}
