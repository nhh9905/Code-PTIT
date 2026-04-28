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
public class tinhTien {
    public static class hoaDon {
        private String ma, ten;
        private long soLuong, donGia, tienChietKhau;

        public hoaDon() {
        }

        public hoaDon(String ma, String ten, long soLuong, long donGia, long tienChietKhau) {
            this.ma = ma;
            this.ten = ten;
            this.soLuong = soLuong;
            this.donGia = donGia;
            this.tienChietKhau = tienChietKhau;
        }
        
        public long tienThanhToan() {
            return donGia * soLuong - tienChietKhau;
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + soLuong + " " + donGia + " " + tienChietKhau + " " + tienThanhToan();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<hoaDon> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            long num = Long.parseLong(sc.nextLine());
            long gia = Long.parseLong(sc.nextLine());
            long tienCK = Long.parseLong(sc.nextLine());
            
            list.add(new hoaDon(ma, ten, num, gia, tienCK));
        }
        
        list.sort((a, b) -> Long.compare(b.tienThanhToan(), a.tienThanhToan()));
        
        for (hoaDon hd : list)
            System.out.println(hd);
    }
}

//3
//ML01
//May lanh SANYO
//12
//4000000
//2400000
//ML02
//May lanh HITACHI
//4
//2550000000
//0
//ML03
//May lanh NATIONAL
//5
//3000000
//150000