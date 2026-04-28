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
public class chuanHoaXauHoTenTrongFile {
    public static void main(String[] args) throws Exception {
        File f = new File("DATA.in");
        Scanner sc = new Scanner(f);
        
        while (sc.hasNextLine()) {
            String hoTen = sc.nextLine();
            hoTen = hoTen.replaceAll("\\s+", " ").trim().toLowerCase();
            
            if (hoTen.equals("end") == true)
                continue;
            
            String words[] = hoTen.split("\\s+");
            for (int i = 0; i < words.length; i++) {
                words[i] = words[i].substring(0, 1).toUpperCase() + words[i].substring(1);
            }
            
            String tenMoi = String.join(" ", words);
            System.out.println(tenMoi);
        }
    }
}
