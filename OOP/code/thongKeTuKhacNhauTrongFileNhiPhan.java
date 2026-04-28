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
public class thongKeTuKhacNhauTrongFileNhiPhan {
    public static void main(String[] args) throws Exception {
        FileInputStream f = new FileInputStream("DATA.in");
        ObjectInputStream ois = new ObjectInputStream(f);
        TreeMap<String, Integer> map = new TreeMap<>(Collections.reverseOrder());
        
        try {
            ArrayList<String> list = (ArrayList<String>)ois.readObject();
            for (String str : list) {
                str = str.replaceAll("[,\\.\\?!:;()\\-/]", " ").trim().toLowerCase();
                String part[] = str.trim().split("\\s+");
                
                for (int i = 0; i < part.length; i++) {
                    map.put(part[i], map.getOrDefault(part[i], 0) + 1);
                }
                
                for (String x : map.descendingKeySet())
                    System.out.println(x + " " + map.get(x));
            }
        } catch (Exception e) {
            
        }
    }
}
