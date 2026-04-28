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
public class j03027 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        StringBuilder s = new StringBuilder(sc.nextLine());
        
        for (int i = 0; i < s.length() - 1; ) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                s.delete(i, i + 2);
                
                if (i > 0)
                    --i;
            }
            else
                ++i;
        }
        if (s.length() != 0)
            System.out.println(s);
        else
            System.out.println("Empty String");
    }
}
