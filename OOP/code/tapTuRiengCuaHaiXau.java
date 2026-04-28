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
public class tapTuRiengCuaHaiXau {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        
        while (t-- > 0) {
            String s1 = sc.nextLine(), s2 = sc.nextLine();
            StringTokenizer st = new StringTokenizer(s1, " ");
            Set<String> set1 = new HashSet<>();
            while (st.hasMoreTokens()) {
                set1.add(st.nextToken());
            }
            
            StringTokenizer st1 = new StringTokenizer(s2, " ");
            Set<String> set2 = new HashSet<>();
            while (st1.hasMoreTokens()) {
                set2.add(st1.nextToken());
            }
            
            for (String x : set1) {
                if (set2.contains(x) == false)
                    System.out.print(x + " ");
            }
            System.out.println();
        }
    }
}
