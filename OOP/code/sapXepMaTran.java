/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
/**
 *
 * @author Asus
 */
public class sapXepMaTran {
    public static void main(String[] args) throws Exception {
        File f = new File("MATRIX.in");
        Scanner sc = new Scanner(f);
        
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            int n = Integer.parseInt(part[0]), m = Integer.parseInt(part[1]);
            int i = Integer.parseInt(part[2]);
            int a[][] = new int[n + 1][m + 1];
            
            for (int k = 1; k <= n; k++) {
                for (int j = 1; j <= m; j++) {
                    a[k][j] = sc.nextInt();
                }
            }
            sc.nextLine();
            
            int tmp[] = new int[n + 1];
            for (int j = 1; j <= n; j++) {
                tmp[j] = a[j][i];
            }
            
            Arrays.sort(tmp, 1, n + 1);
            for (int j = 1; j <= n; j++)
                a[j][i] = tmp[j];
            
            for (int k = 1; k <= n; k++) {
                for (int j = 1; j <= m; j++) {
                    System.out.print(a[k][j] + " ");
                }
                System.out.println();
            }
        }
    }
}
