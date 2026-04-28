/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
/**
 *
 * @author Asus
 */
public class j01013 {
    static int max = (int)2e6;
    
    static ArrayList<Integer> prime = new ArrayList<>();
    static boolean check[] = new boolean[max + 5];
    public static void sang() {
        check[1] = true;
        
        for (int i = 2; i*i <= max; i++) {
            if (check[i] == false) {
                for (int j = i*i; j <= max; j += i)
                    check[j] = true;
            }
        }
        
        for (int i = 2; i <= max; i++) {
            if (check[i] == false)
                prime.add(i);
        }
    }
    
    public static void main(String[] args) {
        sang();
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        long sum = 0;
        
        for (int i = 1; i <= t; i++) {
            int n = sc.nextInt();
            if (check[n] == false) {
                sum += n;
                continue;
            }
            
            for (int p:prime) {
                if (p*p > n)
                    break;
                
                while (n % p == 0) {
                    sum += p;
                    n /= p;
                }
            }
            
            if (n > 1)
                sum += n;
        }
        
        System.out.println(sum);
    }
}
