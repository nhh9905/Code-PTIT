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
public class j02034 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int arr[] = new int[n], dem[] = new int[205], cnt = 0, max = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            ++dem[arr[i]];
            max = Math.max(max, arr[i]);
        }
        
        for (int i = 1; i <= max; i++) {
            if (dem[i] == 0) {
                System.out.println(i);
                ++cnt;
            }
        }
        
        if (cnt == 0)
            System.out.println("Excellent!");
    }
}
