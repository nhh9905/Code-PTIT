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
public class j03008 {
    public static boolean nt(int n) {
        return n == 2 || n == 3 || n == 5 || n == 7;
    }
    
    public static boolean check(String s) {
        int l = 0, r = s.length() - 1;
        
        while (l < r) {
            int leftDigit = s.charAt(l) - '0', rightDigit = s.charAt(r) - '0';
            
            if (nt(leftDigit) == false || nt(rightDigit) == false)
                return false;
            
            if (s.charAt(l) != s.charAt(r))
                return false;
            
            ++l; --r;
        }
        
        if (l == r) {
            int midDigit = s.charAt(l) - '0';
            if (nt(midDigit) == false)
                return false;
        }
        
        return true;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        sc.nextLine();
        
        while (t-- > 0) {
            String s = sc.nextLine();
            
            if (check(s))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
