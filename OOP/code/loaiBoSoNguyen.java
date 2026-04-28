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
public class loaiBoSoNguyen {
    public static void main(String[] args) throws Exception {
        File f = new File("DATA.in");
        Scanner sc = new Scanner(f);
        List<String> list = new ArrayList<>();
        
        while (sc.hasNextLine()) {
            String line = sc.nextLine().trim();
            
            if (line.isEmpty())
                continue;
            
            String word[] = line.split(" ");
            for (String x : word) {
                try {
                    Integer.parseInt(x);
                } catch (NumberFormatException e) {
                    list.add(x);
                }
            }
        }
        
        Collections.sort(list);
        for (String x : list)
            System.out.print(x + " ");
    }
}
