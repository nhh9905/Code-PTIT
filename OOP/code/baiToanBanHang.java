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
public class baiToanBanHang {
    static String readNonEmptyLine(Scanner sc) {
        while (sc.hasNextLine()) {
            String s = sc.nextLine().trim();
            if (!s.isEmpty())
                return s;
        }
        return null;
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("KH.in");
        Scanner sc = new Scanner(f);
        List<khachHang> dsKH = new ArrayList<>();
        int n = Integer.parseInt(readNonEmptyLine(sc));
        for (int i = 0; i < n; i++) {
            khachHang kh = new khachHang();
            kh.input(sc);
            dsKH.add(kh);
        }
        
        f = new File("MH.in");
        sc = new Scanner(f);
        List<matHang> dsMH = new ArrayList<>();
        n = Integer.parseInt(readNonEmptyLine(sc));
        for (int i = 0; i < n; i++) {
            matHang mh = new matHang();
            mh.input(sc);
            dsMH.add(mh);
        }
        
        f = new File("HD.in");
        sc = new Scanner(f);
        List<hoaDon> dsHD = new ArrayList<>();
        n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; i++) {
            String line = readNonEmptyLine(sc);
            String[] parts = line.split("\\s+");
            String maKH = parts[0], maMH = parts[1];
            int sl = Integer.parseInt(parts[2]);
            khachHang kh = null;
            matHang mh = null;
            
            for (khachHang x : dsKH) {
                if (x.getMa().equals(maKH))
                    kh = x;
            }
            for (matHang x : dsMH) {
                if (x.getMa().equals(maMH))
                    mh = x;
            }
            
            if (kh != null && mh != null)
                dsHD.add(new hoaDon(kh, mh, sl));
        }
        
        for (hoaDon x : dsHD)
            System.out.println(x);
    }
}

abstract class Entity {
    protected String ma;
    protected String ten;
    
    public abstract void input(Scanner sc);

    public String getMa() {
        return ma;
    }

    public String getTen() {
        return ten;
    }
    
    protected static String readNonEmptyLine(Scanner sc) {
        while (sc.hasNextLine()) {
            String s = sc.nextLine().trim();
            if (!s.isEmpty())
                return s;
        }
        return null;
    }
}

abstract class Person extends Entity {
    protected String gioiTinh;
    protected String ngaySinh;
    protected String diaChi;
    
    public Person() {}

    public Person(String ten, String gioiTinh, String ngaySinh, String diaChi) {
        this.ten = ten;
        this.gioiTinh = gioiTinh;
        this.ngaySinh = ngaySinh;
        this.diaChi = diaChi;
    }

    @Override
    public void input(Scanner sc) {
        ten = readNonEmptyLine(sc);
        gioiTinh = readNonEmptyLine(sc);
        ngaySinh = readNonEmptyLine(sc);
        diaChi = readNonEmptyLine(sc);
    }

    public String getDiaChi() {
        return diaChi;
    }
}

class khachHang extends Person {
    private static int cnt = 1;
    
    public khachHang() {}
    
    public khachHang(String ten, String gt, String ns, String dc) {
        super(ten, gt, ns, dc);
    }

    @Override
    public void input(Scanner sc) {
        super.input(sc);
        this.ma = String.format("KH%03d", cnt++);
    }
}

class matHang extends Entity {
    private static int cnt = 1;
    private String donViTinh;
    private int giaMua, giaBan;
    
    public matHang() {}

    public matHang(String ten, String donViTinh, int giaMua, int giaBan) {
        this.ten = ten;
        this.donViTinh = donViTinh;
        this.giaMua = giaMua;
        this.giaBan = giaBan;
    }

    @Override
    public void input(Scanner sc) {
        ten = readNonEmptyLine(sc);
        donViTinh = readNonEmptyLine(sc);
        giaMua = Integer.parseInt(readNonEmptyLine(sc));
        giaBan = Integer.parseInt(readNonEmptyLine(sc));
        this.ma = String.format("MH%03d", cnt++);
    }

    public String getDonViTinh() {
        return donViTinh;
    }

    public int getGiaMua() {
        return giaMua;
    }
    
    public int getGiaBan() {
        return giaBan;
    }
}
class hoaDon {
    private static int cnt = 1;
    private String maHoaDon;
    private khachHang kh;
    private matHang mh;
    private int soLuong;
    
    public hoaDon() {}

    public hoaDon(khachHang kh, matHang mh, int soLuong) {
        this.maHoaDon = String.format("HD%03d", cnt++);
        this.kh = kh;
        this.mh = mh;
        this.soLuong = soLuong;
    }
    
    public long getThanhTien() {
        return (long)mh.getGiaBan() * soLuong;
    }

    @Override
    public String toString() {
        return maHoaDon + " " + kh.getTen() + " " + kh.getDiaChi() + " " + mh.getTen() + " " +
                mh.getDonViTinh() + " " + mh.getGiaMua() + " " + mh.getGiaBan() + " " + 
                soLuong + " " + getThanhTien();
    }
}