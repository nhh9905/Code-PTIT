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
public class chuanHoaDanhSachSinhVien {
    public static class sinhVien {
        private String ma, ten, lop, ngaySinh;
        private double gpa;
        private static int cnt = 1;

        public sinhVien() {
        }

        public sinhVien(String ten, String lop, String ngaySinh, double gpa) {
            this.ma = String.format("B20DCCN%03d", cnt++);
            this.ten = ten;
            this.lop = lop;
            this.ngaySinh = ngaySinh;
            this.gpa = gpa;
        }
        
        public String chuanHoaTen() {
            ten = ten.replaceAll("\\s+", " ").trim().toLowerCase();
            String word[] = ten.split(" ");
            
            for (int i = 0; i < word.length; i++)
                word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
            
            return String.join(" ", word);
        }
        
        public String chuanHoaNgaySinh() {
            String part[] = ngaySinh.split("/");
            for (int i = 0; i < 2; i++) {
                if (part[i].length() == 1)
                    part[i] = "0" + part[i];
            }
                
            return String.join("/", part);
        }

        @Override
        public String toString() {
            return ma + " " + chuanHoaTen() + " " + lop + " " + chuanHoaNgaySinh() + " " + String.format("%.2f", gpa);
        }
        
        
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("SINHVIEN.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String lop = sc.nextLine();
            String ngaySinh = sc.nextLine();
            double gpa = Double.parseDouble(sc.nextLine());
            list.add(new sinhVien(ten, lop, ngaySinh, gpa));
        }
        
        for (sinhVien sv : list)
            System.out.println(sv);
    }
}
