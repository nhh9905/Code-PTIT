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
public class lietKeNhanVienTheoChucVu {
    public static class nhanVien {
        private String ma, ten, chucVu;
        private long luong, ngay;
        private static int cnt = 1;

        public nhanVien() {
        }

        public nhanVien(String ten, String chucVu, long luong, long ngay) {
            this.ma = String.format("NV%02d", cnt++);
            this.ten = ten;
            this.chucVu = chucVu;
            this.luong = luong;
            this.ngay = ngay;
        }

        public String getChucVu() {
            return chucVu;
        }
        
        public long tinhPhuCap() {
            if (chucVu.equals("GD"))
                return 500;
            if (chucVu.equals("PGD"))
                return 400;
            if (chucVu.equals("TP"))
                return 300;
            if (chucVu.equals("KT"))
                return 250;
            return 100;
        }
        
        public long tinhLuong() {
            return luong * ngay;
        }
        
        public long tinhTamUng() {
            double tien = (tinhPhuCap() + tinhLuong()) * 2.0/3;
            
            if (tien < 25000) {
                long tmp = Math.round(tien / 1000.0) * 1000;
                return tmp;
            }
            return 25000;
        }
        
        public long tinhConLai() {
            return tinhLuong() - tinhTamUng() + tinhPhuCap();
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + tinhPhuCap() + " " + tinhLuong() + " " + tinhTamUng() + " " + tinhConLai();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<nhanVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String chucVu = sc.nextLine();
            long luong = Long.parseLong(sc.nextLine());
            long ngay = Long.parseLong(sc.nextLine());
            list.add(new nhanVien(ten, chucVu, luong, ngay));
        }
        
        String str = sc.nextLine();
        for (nhanVien nv : list) {
            if (nv.getChucVu().equals(str))
                System.out.println(nv);
        }
    }
}

//4
//Tran Thi Yen
//NV
//1000
//24
//Nguyen Van Thanh
//BV
//1000
//30
//Doan Truong An
//TP
//3000
//25
//Le Thanh
//GD
//5000
//28
//TP