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
public class sapXepHoaDonBanQuanAo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<sanPham> dsSP = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sanPham sp = new sanPham();
            sp.input(sc);
            dsSP.add(sp);
        }
        
        int m = Integer.parseInt(sc.nextLine());
        List<hoaDon> dsHD = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            hoaDon hd = new hoaDon();
            hd.input(sc);
            String maSP = hd.getMa().substring(0, 2);
            
            // Tim san pham
            sanPham sp = null;
            for (sanPham x : dsSP) {
                if (x.getMa().equals(maSP)) {
                    sp = x;
                    break;
                }
            }
            hd.setSp(sp);
            dsHD.add(hd);
            
            int type = Integer.parseInt(hd.getMa().substring(2, 3));
            long thanhTien = 0;
            
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
            
            hd.setGiamGia(giamGia);
            long thanhToan = thanhTien - giamGia;
            hd.setThanhToan(thanhToan);
        }
        
        dsHD.sort((a, b) -> Long.compare(b.getThanhToan(), a.getThanhToan()));
        
        for (hoaDon hd : dsHD)
            System.out.println(hd);
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
        giaLoai1 = Integer.parseInt(sc.nextLine());
        giaLoai2 = Integer.parseInt(sc.nextLine());
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
    private sanPham sp;
    private long giamGia, thanhToan;
    private static int cnt = 1;

    public hoaDon() {}

    public hoaDon(String ma, int soLuong) {
        this.ma = ma;
        this.soLuong = soLuong;
    }

    public long getThanhToan() {
        return thanhToan;
    }

    public void setGiamGia(long giamGia) {
        this.giamGia = giamGia;
    }
    

    public void setThanhToan(long thanhToan) {
        this.thanhToan = thanhToan;
    }

    public void setSp(sanPham sp) {
        this.sp = sp;
    }
    
    public void input(Scanner sc) {
        String line = sc.nextLine();
        String part[] = line.split("\\s+");
        ma = part[0] + "-" + String.format("%03d", cnt++);
        soLuong = Integer.parseInt(part[1]);
    }

    public String getMa() {
        return ma;
    }
    
    public int getSoLuong() {
        return soLuong;
    }

    @Override
    public String toString() {
        return ma + " " + sp.getTen() + " " + giamGia + " " + thanhToan;
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