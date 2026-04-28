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
public class j03004 {
    public static String normalize(String name) {
        // \\s+: whitespace
        name = name.replaceAll("\\s+", " ").trim().toLowerCase();
        String word[] = name.split(" ");
        
        // array: length; String: length()
        for (int i = 0; i < word.length; i++) {
            word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
        }
        
        return String.join(" ", word);
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
