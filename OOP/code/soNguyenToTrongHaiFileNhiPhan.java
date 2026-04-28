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
public class soNguyenToTrongHaiFileNhiPhan {
    static boolean d[] = new boolean[10005];
    
    public static void sang() {
        Arrays.fill(d, true);
        d[0] = d[1] = false;
        for (int i = 2; i < Math.sqrt(10000); i++) {
            if (d[i] == true) {
                for (int j = i * i; j <= 10000; j += i)
                    d[j] = false;
            }
        }
    }
    
    public static void main(String[] args) throws Exception {
        sang();
        FileInputStream f = new FileInputStream("DATA1.in");
        BufferedInputStream bis = new BufferedInputStream(f);
        ObjectInputStream ois = new ObjectInputStream(bis);
        Map<Integer, Integer> m1 = new LinkedHashMap<>();
        try {
            ArrayList<Integer> tmp = (ArrayList<Integer>)ois.readObject();
            for (int x : tmp) {
                if (d[x] == true) {
                    m1.put(x, m1.getOrDefault(x, 0) + 1);
                }
            }
        } catch (EOFException e) {
            
        }
        ois.close();
        f.close();
        bis.close();
        
        f = new FileInputStream("DATA2.in");
        bis = new BufferedInputStream(f);
        ois = new ObjectInputStream(bis);
        Map<Integer, Integer> m2 = new LinkedHashMap<>();
        try {
            ArrayList<Integer> tmp = (ArrayList<Integer>)ois.readObject();
            for (int x : tmp) {
                if (d[x] == true) {
                    m2.put(x, m2.getOrDefault(x, 0) + 1);
                }
            }
        } catch (EOFException e) {
            
        }
        ois.close();
        f.close();
        bis.close();
        
        for (int i = 2; i <= 10000; i++) {
            if (m1.containsKey(i) && m2.containsKey(i))
                System.out.println(i + " " + m1.get(i) + " " + m2.get(i));
        }
    }
}
