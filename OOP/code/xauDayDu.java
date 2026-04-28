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
public class xauDayDu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        
        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            int k = sc.nextInt();
            sc.nextLine();
            Set<Character> set = new HashSet<>();
            
            for (char c : str.toCharArray()) {
                set.add(c);
            }
            
            if (set.size() + k >= 26)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}