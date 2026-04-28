/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.math.*;
/**
 *
 * @author Asus
 */
public class chiaHetCho11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        
        while (t-- > 0) {
            BigInteger x = sc.nextBigInteger();
            if (x.mod(BigInteger.valueOf(11)).equals(BigInteger.ZERO))
                System.out.println(1);
            else
                System.out.println(0);
        }
    }
}

//2
//76945
//363588395960667043875487