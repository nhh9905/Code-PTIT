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
public class bangKeTienLuong {
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
        
        public long luongThang() {
            return luong * ngay;
        }
        
        public long thuong() {
            if (ngay >= 25)
                return (long)(0.2 * luongThang());
            if (ngay >= 22)
                return (long)(0.1 * luongThang());
            return 0;
        }
        
        public long phuCap() {
            if (chucVu.equals("GD"))
                return 250000;
            if (chucVu.equals("PGD"))
                return 200000;
            if (chucVu.equals("TP"))
                return 180000;
            return 150000;
        }
        
        public long thanhTien() {
            return luongThang() + thuong() + phuCap();
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + luongThang() + " " + thuong() + " " + phuCap() + " " + thanhTien();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<nhanVien> list = new ArrayList<>();
        long tong = 0;
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            long luong = Long.parseLong(sc.nextLine());
            long ngay = Long.parseLong(sc.nextLine());
            String chucVu = sc.nextLine();
            list.add(new nhanVien(ten, chucVu, luong, ngay));
        }
        
        for (nhanVien nv : list)
            tong += nv.thanhTien();
        
        for (nhanVien nv : list)
            System.out.println(nv);
        System.out.println("Tong chi phi tien luong: " + tong);
    }
}

//5
//Cao Van Vu
//50000
//26
//GD
//Bui Thi Trang
//45000
//23
//PGD
//Do Van Truong
//40000
//25
//PGD
//Nguyen Van Cam
//37000
//26
//TP
//Truong Thi Tu Linh
//45000
//22
//NV