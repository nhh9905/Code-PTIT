/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
import java.math.BigInteger;
/**
 *
 * @author Asus
 */
public class tachDoiVaTinhTong {
    public static void main(String[] args) throws Exception {
        File f = new File("DATA.in");
        Scanner sc = new Scanner(f);
        
        String line = sc.next();
        int n = line.length();
        while (n > 1) {
            String left = line.substring(0, n/2);
            String right = line.substring(n/2);
            BigInteger l = new BigInteger(left), r = new BigInteger(right);
            BigInteger sum = l.add(r);
            line = sum.toString();
            n = line.length();
            System.out.println(sum);
        }
    }
}
