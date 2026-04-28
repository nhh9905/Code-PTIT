/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.math.BigInteger;
/**
 *
 * @author Asus
 */
public class chiaHet {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        
        while (t-- > 0) {
            String a = sc.next(), b = sc.next();
            BigInteger x = new BigInteger(a), y = new BigInteger(b);
            
            if (x.mod(y).equals(BigInteger.ZERO) || y.mod(x).equals(BigInteger.ZERO))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
