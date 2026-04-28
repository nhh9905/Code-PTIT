/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
/**
 *
 * @author Asus
 */
public class lietKeSinhVienTheoNganh {
    public static class sinhVien {
        private String ma, ten, lop, email;

        public sinhVien() {
        }

        public sinhVien(String ma, String ten, String lop, String email) {
            this.ma = ma;
            this.ten = ten;
            this.lop = lop;
            this.email = email;
        }

        public String getLop() {
            return lop;
        }
        
        public String getCum() {
            return ma.substring(3, 7);
        }
        
        public String getNganh() {
            if (getCum().equals("DCKT"))
                return "Ke toan";
            if (getCum().equals("DCCN"))
                return "Cong nghe thong tin";
            if (getCum().equals("DCAT"))
                return "An toan thong tin";
            if (getCum().equals("DCVT"))
                return "Vien thong";
            return "Dien tu";
        }
        
        public boolean nganhHopLe(String nganh) {
            String cum = getCum();

            if (nganh.equals("Ke toan") && cum.equals("DCKT"))
                return true;

            if (nganh.equals("Cong nghe thong tin") && cum.equals("DCCN") && lop.charAt(0) != 'E')
                return true;

            if (nganh.equals("An toan thong tin") && cum.equals("DCAT") && lop.charAt(0) != 'E')
                return true;

            if (nganh.equals("Vien thong") && cum.equals("DCVT"))
                return true;

            if (nganh.equals("Dien tu") && cum.equals("DCDT"))
                return true;

            return false;
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + lop + " " + email;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            String lop = sc.nextLine();
            String email = sc.nextLine();
            
            list.add(new sinhVien(ma, ten, lop, email));
        }
        
        int q = Integer.parseInt(sc.nextLine());
        while (q-- > 0) {
            String nganh = sc.nextLine();
            String x = nganh;
            System.out.println("DANH SACH SINH VIEN NGANH " + x.toUpperCase() + ":");
            
            for (sinhVien sv : list) {
                if (sv.nganhHopLe(nganh))
                    System.out.println(sv);
            }
        }
    }
}

//4
//B16DCCN011
//Nguyen Trong Duc Anh
//D16CNPM1
//sv1@stu.ptit.edu.vn
//B15DCCN215
//To Ngoc Hieu
//D15CNPM3
//sv2@stu.ptit.edu.vn
//B15DCKT150
//Nguyen Ngoc Son
//D15CQKT02-B
//sv3@stu.ptit.edu.vn
//B15DCKT199
//Nguyen Trong Tung
//D15CQKT02-B
//sv4@stu.ptit.edu.vn
//1
//Ke toan