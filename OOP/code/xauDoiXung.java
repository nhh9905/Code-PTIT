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
public class xauDoiXung {
    public static boolean check(String str) {
        int l = 0, r = str.length() - 1, cnt = 0, n = str.length();
        while (l < r) {
            if (str.charAt(l) != str.charAt(r))
                ++cnt;
            ++l;
            --r;
        }
        
        if ((n % 2 == 0 && cnt == 1) || (n % 2 != 0 && cnt <= 1))
            return true;
        return false;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        
        while (n-- > 0) {
            String str = sc.nextLine();
            if (check(str) == true)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}

//3
//abccaa
//abbcca
//abcda