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
public class sapXepDanhSachSinhVien {
    public static class sinhVien {
        private String ma, ten, sdt, email;

        public sinhVien() {
        }

        public sinhVien(String ma, String ten, String sdt, String email) {
            this.ma = ma;
            this.ten = ten;
            this.sdt = sdt;
            this.email = email;
        }

        public String getTen() {
            return ten;
        }
        
        public String layTen() {
            String word[] = ten.split(" ");
            return word[word.length - 1];
        }

        public String getMa() {
            return ma;
        }
        
        @Override
        public String toString() {
            return ma + " " + ten + " " + sdt + " " + email;
        }
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("SINHVIEN.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            String sdt = sc.nextLine();
            String email = sc.nextLine();
            list.add(new sinhVien(ma, ten, sdt, email));
        }
        
        list.sort((a, b) -> {
            if (!a.layTen().equals(b.layTen()))
                return a.layTen().compareTo(b.layTen());
            if (!a.getTen().equals(b.getTen()))
                return a.getTen().compareTo(b.getTen());
            return a.getMa().compareTo(b.getMa());
        });
        
        for (sinhVien sv : list)
            System.out.println(sv);
    }
}
