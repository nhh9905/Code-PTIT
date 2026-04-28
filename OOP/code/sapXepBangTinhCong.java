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
public class sapXepBangTinhCong {
    public static class nhanVien {
        private String ma, ten, chucVu;
        private long luong, soNgay;
        private static int cnt = 1;

        public nhanVien() {
        }

        public nhanVien(String ten, String chucVu, long luong, long soNgay) {
            this.ma = String.format("NV%02d", cnt++);
            this.ten = ten;
            this.chucVu = chucVu;
            this.luong = luong;
            this.soNgay = soNgay;
        }
        
        public long tinhLuong() {
            return luong * soNgay;
        }
        
        public long tinhThuong() {
            if (soNgay >= 25)
                return (long)(0.2 * tinhLuong());
            if (soNgay >= 22 && soNgay < 25)
                return (long)(0.1 * tinhLuong());
            return 0;
        }
        
        public long tinhPhuCap() {
            if (chucVu.equals("GD"))
                return 250000;
            if (chucVu.equals("PGD"))
                return 200000;
            if (chucVu.equals("TP"))
                return 180000;
            return 150000;
        }
        
        public long tinhThuNhap() {
            return tinhLuong() + tinhThuong() + tinhPhuCap();
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + tinhLuong() + " " + tinhThuong() + " " + tinhPhuCap() + " " + tinhThuNhap();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<nhanVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            long luong = Long.parseLong(sc.nextLine());
            long soNgay = Long.parseLong(sc.nextLine());
            String chucVu = sc.nextLine();
            list.add(new nhanVien(str, chucVu, luong, soNgay));
        }
        
        list.sort((a, b) -> Long.compare(b.tinhThuNhap(), a.tinhThuNhap()));
        
        for (nhanVien nv : list)
            System.out.println(nv);
    }
}

//3
//Cao Van Vu
//50000
//26
//GD
//Do Van Truong
//40000
//25
//PGD
//Truong Thi Tu Linh
//45000
//22
//NV