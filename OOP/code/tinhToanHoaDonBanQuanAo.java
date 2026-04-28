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
public class tinhToanHoaDonBanQuanAo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        List<sanPham> dsSP = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sanPham sp = new sanPham();
            sp.input(sc);
            dsSP.add(sp);
        }
        
        n = sc.nextInt();
        sc.nextLine();
        List<hoaDon> dsHD = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            hoaDon hd = new hoaDon();
            hd.input(sc);
            dsHD.add(hd);
        }
        
        int cnt = 0;
        for (hoaDon hd : dsHD) {
            int type = Integer.parseInt(hd.getMa().substring(2, 3));
            String maSP = hd.getMa().substring(0, 2);
            
            long thanhTien;
            sanPham sp = null;
            for (sanPham x : dsSP) {
                if (x.getMa().equals(maSP)) {
                    sp = x;
                    break;
                }
            }
            
            if (sp == null)
                continue;
            
            if (type == 1)
                thanhTien = (long)sp.getGiaLoai1() * hd.getSoLuong();
            else
                thanhTien = (long)sp.getGiaLoai2() * hd.getSoLuong();
            
            long giamGia = 0;
            if (hd.getSoLuong() >= 50 && hd.getSoLuong() < 100)
                giamGia = thanhTien * 15 / 100;
            if (hd.getSoLuong() >= 100 && hd.getSoLuong() < 150)
                giamGia = thanhTien * 30 / 100;
            if (hd.getSoLuong() >= 150)
                giamGia = thanhTien * 50 / 100;
                
            long thanhToan = thanhTien - giamGia;
            System.out.println(hd.getMa() + "-" + String.format("%03d", ++cnt) + " " + 
                    sp.getTen() + " " + giamGia + " " + thanhToan
                    );
        }
    }
}

class sanPham {
    private String ma, ten;
    private int giaLoai1, giaLoai2;
    
    public sanPham() {}

    public sanPham(String ma, String ten, int giaLoai1, int giaLoai2) {
        this.ma = ma;
        this.ten = ten;
        this.giaLoai1 = giaLoai1;
        this.giaLoai2 = giaLoai2;
    }
    
    public void input(Scanner sc) {
        ma = sc.nextLine();
        ten = sc.nextLine();
        giaLoai1 = sc.nextInt();
        giaLoai2 = sc.nextInt();
        sc.nextLine();
    }

    public String getMa() {
        return ma;
    }

    public String getTen() {
        return ten;
    }
    
    public int getGiaLoai1() {
        return giaLoai1;
    }

    public int getGiaLoai2() {
        return giaLoai2;
    }
}

class hoaDon {
    private String ma;
    private int soLuong;

    public hoaDon() {}

    public hoaDon(String ma, int soLuong) {
        this.ma = ma;
        this.soLuong = soLuong;
    }
    
    public void input(Scanner sc) {
        String line = sc.nextLine();
        String part[] = line.split("\\s+");
        ma = part[0];
        soLuong = Integer.parseInt(part[1]);
    }

    public String getMa() {
        return ma;
    }
    
    public int getSoLuong() {
        return soLuong;
    }
}

//2
//AT
//Ao thun
//80000
//45000
//QJ
//Quan Jean
//220000
//125000
//2
//AT1 95
//QJ2 105