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
public class j07002 {
    public static void main(String[] args) throws Exception {
        File f = new File("DATA.in");
        Scanner sc = new Scanner(f);
        long sum = 0;
        
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            if (line.isEmpty())
                continue;
            
            String tokens[] = line.trim().split("\\s+");
            for (String token:tokens) {
                try {
                    int num = Integer.parseInt(token);
                    sum += num;
                }
                catch (NumberFormatException e) {
                    
                }
            }
            
        }
        
        System.out.println(sum);
    }
}
