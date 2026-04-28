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
public class j03024 {
    public static boolean check(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) < '0' || s.charAt(i) > '9')
                return false;
        }
        
        return true;
    }
    
    public static boolean dem(String s) {
        int chan = 0, le = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) % 2 == 0)
                ++chan;
            else
                ++le;
        }
        
        return (s.length() % 2 == 0 && chan > le) || (s.length() % 2 != 0 && le > chan);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        
        while (t-- > 0) {
            String s = sc.nextLine();
            
            if (check(s)) {
                if (dem(s))
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
            else
                System.out.println("INVALID");
        }
    }
}
