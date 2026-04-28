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
public class j02022 {
    static boolean used[] = new boolean[15];
    static int x[] = new int[15];
    
    public static boolean check(int n) {
        for (int i = 1; i < n; i++) {
            if (Math.abs(x[i] - x[i + 1]) == 1)
                return false;
        }
        return true;
    }
    
    public static void print(int n) {
        for (int i = 1; i <= n; i++)
            System.out.print(x[i]);
        System.out.println();
    }
    
    public static void Try(int i, int n) {
        for (int j = 1; j <= n; j++) {
            if (used[j] == false) {
                x[i] = j;
                used[j] = true;
                
                if (i == n) {
                    if (check(n))
                        print(n);
                }
                else
                    Try(i + 1, n);
                
                used[j] = false;
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            
            Try(1, n);
        }
    }
}
