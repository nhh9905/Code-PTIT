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
public class j03007 {
    public static boolean check(String s) {
        int l = 0, r = s.length() - 1;
        
        if (s.charAt(l) != '8' || s.charAt(r) != '8')
            return false;
        
        int sum = 0;
        while (l < r) {
            int leftDigit = s.charAt(l) - '0', rightDigit = s.charAt(r) - '0';
            sum += leftDigit;
            sum += rightDigit;
            
            if (s.charAt(l) != s.charAt(r))
                return false;
            
            ++l; --r;
        }
        
        if (l == r) {
            int midDigit = s.charAt(l) - '0';
            sum += midDigit;
        }
        
        return sum % 10 == 0;
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
