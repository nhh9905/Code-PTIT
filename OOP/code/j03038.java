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
public class j03038 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String s = sc.nextLine();
        int cnt[] = new int[1005];
        
        for (char x:s.toCharArray()) {
            int k = x - 'a';
            cnt[k]++;
        }
        
        int dem = 0;
        for (char x = 'a'; x <= 'z'; x++) {
            int k = x - 'a';
            
            if (cnt[k] != 0) {
                ++dem;
                cnt[k] = 0;
            }
        }
        
        System.out.println(dem);
    }
}
