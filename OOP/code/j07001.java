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
public class j07001 {
    public static void main(String[] args) throws Exception {
        File f = new File("DATA.in");
        Scanner sc = new Scanner(f);
        
        while (sc.hasNextLine()) {
            String line = sc.nextLine().trim();
            System.out.println(line);
        }
    }
}
