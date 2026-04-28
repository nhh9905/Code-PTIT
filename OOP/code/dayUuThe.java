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
public class dayUuThe {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        
        while (t-- > 0) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            int demChan = 0, demLe = 0;
            
            for (int i = 0; i < part.length; i++) {
                long x = Long.parseLong(part[i]);
                if (x % 2 == 0)
                    demChan++;
                else
                    ++demLe;
            }
            
            if ((part.length % 2 == 0 && demChan > demLe) || (part.length % 2 != 0 && demLe > demChan))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}

//2
//11 22 33 44 55 66 77
//23 34 45 56 67 78 89 90 121 131 141 151 161 171