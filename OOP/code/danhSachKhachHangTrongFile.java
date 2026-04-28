/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
/**
 *
 * @author Asus
 */
public class danhSachKhachHangTrongFile {
    public static class khachHang {
        private String ma, ten, gioiTinh, diaChi;
        private LocalDate ngaySinh;
        private static int cnt = 1;

        public khachHang() {
        }

        public khachHang(String ten, String gioiTinh, String ngaySinh, String diaChi) {
            this.ma = String.format("KH%03d", cnt++);
            this.ten = ten;
            this.gioiTinh = gioiTinh;
            this.ngaySinh = LocalDate.parse(ngaySinh, DateTimeFormatter.ofPattern("dd/MM/yyyy"));
            this.diaChi = diaChi;
        }
        
        public String chuanHoaTen() {
            ten = ten.replaceAll("\\s+", " ").trim().toLowerCase();
            String word[] = ten.split(" ");
            
            for (int i = 0; i < word.length; i++)
                word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
            
            return String.join(" ", word);
        }
        
        @Override
        public String toString() {
            return ma + " " + chuanHoaTen() + " " + gioiTinh + " " + diaChi + " " + 
                    ngaySinh.format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        }
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("KHACHHANG.in");
        Scanner sc = new Scanner(f);
        
        int n = Integer.parseInt(sc.nextLine());
        List<khachHang> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String gt = sc.nextLine();
            String ns = sc.nextLine();
            
            String part[] = ns.split("/");
            for (int j = 0; j <= 1; j++) {
                if (part[j].length() < 2)
                    part[j] = "0" + part[j];
            }
            ns = String.join("/", part);
            
            String dc = sc.nextLine();
            list.add(new khachHang(ten, gt, ns, dc));
        }
        
        list.sort((a, b) -> a.ngaySinh.compareTo(b.ngaySinh));
        
        for (khachHang kh : list)
            System.out.println(kh);
    }
}
