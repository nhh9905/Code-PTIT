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
public class soNguyenToLonNhatTrongFile {
    static boolean check[] = new boolean[1000005];
    static void sang() {
        check[0] = check[1] = true;
        for (int i = 2; i * i <= 1000000; i++) {
            if (check[i] == false) {
                for (int j = i * i; j <= 1000000; j += i)
                    check[j] = true;
            }
        }
    }
    
    public static void main(String[] args) throws Exception {
        FileInputStream f = new FileInputStream("DATA.in");
        ObjectInputStream ois = new ObjectInputStream(f);
        TreeMap<Integer, Integer> freq = new TreeMap<>(Comparator.reverseOrder());
        sang();
        int cnt = 0;
        
        try {
            ArrayList<Integer> tmp = (ArrayList<Integer>) ois.readObject();
            for (int x : tmp) {
                if (check[x] == false) {
                    freq.put(x, freq.getOrDefault(x, 0) + 1);
                }
            }
            
            for (int k : freq.keySet()) {
                if (cnt < 10) {
                    System.out.println(k + " " + freq.get(k));
                }
                ++cnt;
            }
        } catch (EOFException e) {
            
        }
    }
}
