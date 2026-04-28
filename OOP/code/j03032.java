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
public class j03032 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        sc.nextLine();
        
        while (t-- > 0) {
            String s = sc.nextLine();
            
            String word[] = s.split(" ");
            for (String x:word) {
                for (int i = x.length() - 1; i >= 0; i--)
                    System.out.print(x.charAt(i));
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}
