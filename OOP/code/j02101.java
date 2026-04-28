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
public class j02101 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int arr[] = new int[n*n];
            
            for (int i = 0; i < n*n; i++)
                arr[i] = sc.nextInt();
            
            int idx = 0, cnt = 1;
            for (int i = 0; i < n; i++) {
                if (cnt % 2 == 1) {
                    for (int j = idx; j < idx + n; j++)
                        System.out.print(arr[j] + " ");
                }
                else {
                    for (int j = idx + n - 1; j >= idx; j--)
                        System.out.print(arr[j] + " ");
                }
                
                ++cnt;
                idx += n;
            }
            System.out.println();
        }
    }
}
