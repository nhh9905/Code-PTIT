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
public class j02021 {
    static int arr[] = new int[15];
    static int cnt = 0;
    
    public static void print(int k) {
        for (int i = 1; i <= k; i++)
            System.out.print(arr[i]);
        System.out.print(" ");
    }
    
    public static void Try(int i, int n, int k) {
        for (int j = arr[i - 1] + 1; j <= n; j++) {
            arr[i] = j;
            
            if (i == k) {
                print(k);
                ++cnt;
            }
            else
                Try(i + 1, n, k);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt(), k = sc.nextInt();
        
        arr[0] = 0;
        Try(1, n, k);
        
        System.out.println();
        System.out.println("Tong cong co " + cnt + " to hop");
    }
}
