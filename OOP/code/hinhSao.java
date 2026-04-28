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
public class hinhSao {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int deg[] = new int[n + 5];
        
        for (int i = 0; i < n - 1; i++) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            int u = Integer.parseInt(part[0]), v = Integer.parseInt(part[1]);
            ++deg[u];
            ++deg[v];
        }
        
        int center = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == n - 1)
                ++center;
            else if (deg[i] != 1 && deg[i] != 0) {
                System.out.println("No");
                return;
            }
        }
        
        if (center == 1)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}

//5
//1 2
//1 3
//1 4
//1 5