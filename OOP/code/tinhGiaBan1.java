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
public class tinhGiaBan1 {
    public static class matHang {
        private String ma, ten, donVi;
        private long donGia, soLuong;
        private static int cnt = 1;

        public matHang() {
        }

        public matHang(String ten, String donVi, long donGia, long soLuong) {
            this.ma = String.format("MH%02d", cnt++);
            this.ten = ten;
            this.donVi = donVi;
            this.donGia = donGia;
            this.soLuong = soLuong;
        }
        
        public long phiVanChuyen() {
            return Math.round((donGia * soLuong) * 5 / 100.0);
        }
        
        public long thanhTien() {
            return donGia * soLuong + phiVanChuyen();
        }
        
        public long giaBan() {
            return thanhTien() + Math.round(thanhTien() * 2 / 100.0);
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + donVi + " " + phiVanChuyen() + " " + thanhTien() + " " + giaBan();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<matHang> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String dv = sc.nextLine();
            long donGia = Long.parseLong(sc.nextLine());
            long soLuong = Long.parseLong(sc.nextLine());
            list.add(new matHang(ten, dv, donGia, soLuong));
        }
        
        for (matHang mh : list)
            System.out.println(mh);
    }
}

//4
//DUONG
//KG
//7500
//150
//TRUNG
//CHUC
//10000
//225
//GAO
//KG
//14000
//118
//SUA
//HOP
//48000
//430