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
public class tinhToanGiaBan {
    public static class donHang {
        private String ma;
        private long donGia, soLuong;

        public donHang() {
        }

        public donHang(String ma, long donGia, long soLuong) {
            this.ma = ma;
            this.donGia = donGia;
            this.soLuong = soLuong;
        }
        
        public char getChuCaiDau() {
            return ma.charAt(0);
        }
        
        public double getThue() {
            char c = getChuCaiDau();
            
            if (c == 'T')
                return 0.29;
            if (c == 'C')
                return 0.1;
            if (c == 'D')
                return 0.08;
            return 0.02;
        }
        
        public double getPhiVanChuyen() {
            char c = getChuCaiDau();
            
            if (c == 'T')
                return 0.04;
            if (c == 'C')
                return 0.03;
            if (c == 'D')
                return 0.025;
            return 0.005;
        }
        
        public char getChuCaiCuoi() {
            return ma.charAt(ma.length() - 1);
        }
        
        public double getThue2() {
            char c = getChuCaiCuoi();
            
            if (c == 'C')
                return getThue() - 0.05 * getThue();
            return getThue();
        }
        
        public double thanhTien() {
            long k = donGia;
            double gia = k + k * getThue2() + k * getPhiVanChuyen();
            return gia + gia * 0.2;
        }

        @Override
        public String toString() {
            return ma + " " + String.format("%.2f", thanhTien());
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<donHang> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            String word[] = str.split(" ");
            String ma = word[0];
            long gia = Long.parseLong(word[1]);
            long num = Long.parseLong(word[2]);
            list.add(new donHang(ma, gia, num));
        }
        
        for (donHang dh : list)
            System.out.println(dh);
        
        sc.close();
    }
}

//2
//TTVC 400 300
//CCAK 200 200