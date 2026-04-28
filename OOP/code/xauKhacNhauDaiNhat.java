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
public class xauKhacNhauDaiNhat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        
        while (n-- > 0) {
            String str1 = sc.nextLine();
            String str2 = sc.nextLine();
            
            if (str1.equals(str2)) {
                System.out.println("-1");
                continue;
            }
            
            System.out.println(Math.max(str1.length(), str2.length()));
        }
        
        sc.close();
    }
}

//2
//abcd
//defgh
//a
//a