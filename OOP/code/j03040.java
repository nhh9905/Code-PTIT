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
public class j03040 {
    public static boolean check1(String s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '.')
                continue;
            
            if (s.charAt(i) >= s.charAt(i + 1) && s.charAt(i) != '.' && s.charAt(i + 1) != '.')
                return false;
        }
        
        return true;
    }
    
    public static boolean check2(String s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '.')
                continue;
            
            if (s.charAt(i) != s.charAt(i + 1) && s.charAt(i) != '.' && s.charAt(i + 1) != '.')
                return false;
        }
        
        return true;
    }
    
    public static boolean check3(String s) {
        return (s.charAt(0) == s.charAt(1) && s.charAt(1) == s.charAt(2)) && (s.charAt(4) == s.charAt(5));
    }
    
    public static boolean check4(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '.')
                continue;
            
            if (s.charAt(i) != '6' && s.charAt(i) != '8')
                return false;
        }
        
        return true;
    }
    
    public static boolean check(String s) {
        return check1(s) == true || check2(s) == true || check3(s) == true || check4(s) == true;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        sc.nextLine();
        
        while (t-- > 0) {
            String s = sc.nextLine();
            String num = s.substring(5);
            
            if (check(num) == true)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
