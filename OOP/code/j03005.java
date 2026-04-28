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
public class j03005 {
    public static String normalize(String name) {
        name = name.replaceAll("\\s+", " ").trim().toLowerCase();
        String word[] = name.split(" ");
        String ans = "";
        
        String lastName = word[0].toUpperCase();
        for (int i = 1; i < word.length; i++) {
            word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
            
            if (i != word.length - 1)
                ans = ans.concat(word[i] + " ");
            else
                ans = ans.concat(word[i] + ", ");
        }
        
        ans = ans.concat(lastName);
        return ans;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        sc.nextLine();
        
        while (t-- > 0) {
            String s = sc.nextLine();
            String normalized = normalize(s);
            
            System.out.println(normalized);
        }
    }
}
