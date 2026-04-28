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
public class lietKeTuKhacNhau {
    public static void main(String[] args) throws Exception {
        File f = new File("VANBAN.in");
        Scanner sc = new Scanner(f);
        Set<String> set = new TreeSet<>();
        
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            String words[] = line.split("\\s+");
            
            for (String word : words) {
                word = word.toLowerCase();
                set.add(word);
            }
            
        }
        for (String x : set)
            System.out.println(x);
    }
}
