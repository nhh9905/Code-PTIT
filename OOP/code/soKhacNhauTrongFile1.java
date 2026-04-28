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
public class soKhacNhauTrongFile1 {
    public static void main(String[] args) throws Exception {
        File f = new File("DATA.in");
        Scanner sc = new Scanner(f);
        Map<Integer, Integer> freq = new HashMap<>();
        
        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            int cnt = freq.getOrDefault(n, 0);
            freq.put(n, cnt + 1);
        }
        
        for (Integer k : freq.keySet()) {
            System.out.printf("%d %d\n", k, freq.get(k));
        }
    }
}
