/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.math.*;
/**
 *
 * @author Asus
 */
public class j03039 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        
        while (t-- > 0) {
            BigInteger a = sc.nextBigInteger(), b = sc.nextBigInteger();
            BigInteger max = a.max(b), c, ans;
            
            if (max == a) {
                c = a.divide(b);
                
                ans = b.multiply(c);
                if (ans == a)
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
            else {
                c = b.divide(a);
                
                ans = a.multiply(c);
                if (ans == b)
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
        }
    }
}
