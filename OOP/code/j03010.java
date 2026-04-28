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
public class j03010 {
    static Map<String, Integer> freq = new HashMap<>();
    static ArrayList<String> emails = new ArrayList<>();
    
    public static String normalize(String name) {
        name = name.replaceAll("\\s+", " ").trim().toLowerCase();
        String word[] = name.split(" ");
        String ans = "";
        ans = ans.concat(word[word.length - 1]);
        
        for (int i = 0; i < word.length - 1; i++) {
            ans = ans.concat(word[i].substring(0, 1));
        }
        emails.add(ans);
        
        for (String email:emails) {
            if (ans.equals(email) == true) {
                int cnt = freq.getOrDefault(email, 0);
            
                if (cnt != 0)
                    ans = ans.concat(String.valueOf(cnt + 1));

                freq.put(email, cnt + 1);
            }
        }
        
        ans = ans.concat("@ptit.edu.vn");
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

//4
//    nGUYEn    quaNG   vInH  
//   tRan   thi THU    huOnG
//   nGO   quoC  VINH
// lE            tuAn    aNH