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
public class j01014 {
    public static long nt(long n) {
        long ans = 0;
        
        for (long i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                ans = Math.max(ans, i);
            }
        }
        
        if (n > 1)
            ans = Math.max(ans, n);
        return ans;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while (t-- > 0) {
            long n = sc.nextLong();
            System.out.println(nt(n));
        }
    }
}
