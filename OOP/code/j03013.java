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
public class j03013 {
    public static long mod = (long)1e9 + 7;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        sc.nextLine();
        
        while (t-- > 0) {
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            
            String ans = a.subtract(b).abs().toString();
            if (ans.length() != Math.max(a.toString().length(), b.toString().length()))
                ans = '0' + ans;
            
            System.out.println(ans);
        }
    }
}