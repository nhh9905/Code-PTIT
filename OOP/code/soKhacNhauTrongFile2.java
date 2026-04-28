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
public class soKhacNhauTrongFile2 {
    public static void main(String[] args) throws Exception {
        // Đọc file nhị phân
        FileInputStream f = new FileInputStream("DATA.IN");
        DataInputStream sc = new DataInputStream(f);
        TreeMap<Integer, Integer> freq = new TreeMap<>();
        
        try {
            while (true) {
                int n = sc.readInt();
                freq.put(n, freq.getOrDefault(n, 0) + 1);
            }
        } catch (EOFException e) {
            
        }
        
        for (Integer k : freq.keySet()) {
            System.out.printf("%d %d\n", k, freq.get(k));
        }
    }
}
