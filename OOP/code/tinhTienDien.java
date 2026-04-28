/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
/**
 *
 * @author Asus
 */
public class tinhTienDien {
    public static void main(String[] args) throws Exception {
        File f = new File("KHACHHANG.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<khachHang> list = new ArrayList<>();
        
        for (long i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String line = sc.nextLine();
            String part[] = line.split("\\s+");
            
            String loai = part[0];
            long dau = Long.parseLong(part[1]), cuoi = Long.parseLong(part[2]);
            list.add(new khachHang(ten, loai, dau, cuoi));
        }
        
        list.sort((a, b) -> Long.compare(b.tongTien(), a.tongTien()));
        for (khachHang kh : list)
            System.out.println(kh);
    }
}

class khachHang {
    private String ma, ten, loaiHo;
    private long chiSoDau, chiSoCuoi;
    private static long cnt = 1;
    
    public khachHang() {}

    public khachHang(String ten, String loaiHo, long chiSoDau, long chiSoCuoi) {
        this.ma = String.format("KH%02d", cnt++);
        this.ten = ten;
        this.loaiHo = loaiHo;
        this.chiSoDau = chiSoDau;
        this.chiSoCuoi = chiSoCuoi;
    }
    
    public String chuanHoaTen() {
        ten = ten.replaceAll("\\s+", " ").trim().toLowerCase();
        String part[] = ten.split("\\s+");
        
        for (int i = 0; i < part.length; i++) 
            part[i] = part[i].substring(0, 1).toUpperCase() + part[i].substring(1);
        
        return String.join(" ", part);
    }
    
    public long soDien() {
        return chiSoCuoi - chiSoDau;
    }
    
    public long dinhMuc() {
        if (loaiHo.equals("A"))
            return 100;
        if (loaiHo.equals("B"))
            return 500;
        return 200;
    }
    
    public long tienTrongDinhMuc() {
        if (soDien() <= dinhMuc())
            return soDien() * 450;
        return dinhMuc() * 450;
    }
    
    public long tienVuotDinhMuc() {
        if (soDien() > dinhMuc())
            return (soDien() - dinhMuc()) * 1000;
        return 0;
    }
    
    public long thueVAT() {
        return 5 * tienVuotDinhMuc() / 100;
    }
    
    public long tongTien() {
        return tienTrongDinhMuc() + tienVuotDinhMuc() + thueVAT();
    }

    @Override
    public String toString() {
        return ma + " " + chuanHoaTen() + " " + tienTrongDinhMuc() + " " + tienVuotDinhMuc() + " " + 
                thueVAT() + " " + tongTien();
    }
}