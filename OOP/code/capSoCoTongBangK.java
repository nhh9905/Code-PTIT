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
public class capSoCoTongBangK {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        
        while (t-- > 0) {
            int n = sc.nextInt();
            long k = sc.nextLong();
            long a[] = new long[n];
            Map<Long, Long> m = new HashMap<>();
            long res = 0;
            
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
                long target = k - a[i];
                
                if (m.containsKey(target))
                    res += m.get(target);
                
                m.put(a[i], m.getOrDefault(a[i], 0L) + 1);
            }
            
            System.out.println(res);
        }
    }
}

//4
//4 6
//1 5 7 -1
//5 6
//1 5 7 -1 5
//4 2
//1 1 1 1
//13 11
//10 12 10 15 -1 7 6 5 4 2 1 1 1