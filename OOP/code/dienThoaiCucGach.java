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
public class dienThoaiCucGach {
    public static boolean xuly(String str) {
        String tmp = "";
        str = str.toUpperCase();
        
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            int k = 0;
            if (c == 'A' || c == 'B' || c == 'C')
                k = 2;
            if (c == 'D' || c == 'E' || c == 'F')
                k = 3;
            if (c == 'G' || c == 'H' || c == 'I')
                k = 4;
            if (c == 'J' || c == 'K' || c == 'L')
                k = 5;
            if (c == 'M' || c == 'N' || c == 'O')
                k = 6;
            if (c == 'P' || c == 'Q' || c == 'R' || c == 'S')
                k = 7;
            if (c == 'T' || c == 'U' || c == 'V')
                k = 8;
            if (c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
                k = 9;
            tmp += String.valueOf(k);
        }
        
        int l = 0, r = tmp.length() - 1;
        while (l < r) {
            if (tmp.charAt(l) != tmp.charAt(r))
                return false;
            ++l; --r;
        }
        
        return true;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        
        while (n-- > 0) {
            String str = sc.nextLine();
            if (xuly(str) == true)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}

//2
//BOHIMA
//IamACoder