/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package code;

import java.util.*;
/**
 *
 * @author Asus
 */
public class hellojar {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String msv = sc.nextLine();
        String ten = sc.nextLine();
        System.out.println("Mã sinh viên: " + msv);
        System.out.println("Họ tên: " + ten);
        System.out.println("Các môn học:");
        int t = sc.nextInt();
        int tong = 0;
        
        while (t-- > 0) {
            String id = sc.nextLine();
            String mon = sc.nextLine();
            System.out.println(mon);
            int tin = sc.nextInt();
            tong += tin;
        }
        
        String qdinh = sc.nextLine();
        String qdinh_hphi = sc.nextLine();
        long hp = sc.nextLong();
        System.out.println("Học phí phải nộp là: " + hp*tong);
        System.out.println("Theo QĐ: " + qdinh);
        
        sc.close();
    }
    
}
