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
public class j02106 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int arr[][] = new int[n][3], ans = 0;
        
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < 3; j++) {
                arr[i][j] = sc.nextInt();
                
                if (arr[i][j] == 1)
                    ++cnt;
            }
            
            int cnt0 = 3 - cnt;
            if (cnt > cnt0)
                ++ans;
        }
        
        System.out.println(ans);
    }
}
