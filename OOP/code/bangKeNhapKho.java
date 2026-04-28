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
public class bangKeNhapKho {
    public static class matHang {
        private String ma, ten;
        private long soLuong, donGia;
        private static Map<String, Integer> m = new HashMap<>();

        public matHang() {
        }

        public matHang(String ten, long soLuong, long donGia) {
            this.ten = ten;
            this.soLuong = soLuong;
            this.donGia = donGia;
        }
        
        public double phanTram() {
            if (soLuong > 10)
                return 0.05;
            if (soLuong >= 8 && soLuong <= 10)
                return 0.02;
            if (soLuong >= 5 && soLuong < 8)
                return 0.01;
            return 0;
        }
        
        public long tienChietKhau() {
            return (long)(donGia * soLuong * phanTram());
        }
        
        public long thanhTien() {
            return donGia * soLuong - tienChietKhau();
        }

        public String getMa() {
            String word[] = ten.split(" ");
            for (int i = 0; i < 2; i++)
                word[i] = word[i].substring(0, 1).toUpperCase();
            String ma = word[0].concat(word[1]);
            
            int cnt = m.getOrDefault(ma, 0) + 1;
            m.put(ma, cnt);
            
            return ma + String.format("%02d", cnt);
        }

        @Override
        public String toString() {
            return getMa() + " " + ten + " " + tienChietKhau() + " " + thanhTien();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<matHang> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            long sl = Long.parseLong(sc.nextLine());
            long gia = Long.parseLong(sc.nextLine());
            list.add(new matHang(ten, sl, gia));
        }
        
        for (matHang mh : list)
            System.out.println(mh);
    }
}

//3
//May lanh SANYO
//12
//4000000
//Dien thoai Samsung
//30
//3230000
//Dien thoai Nokia
//18
//1240000