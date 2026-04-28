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
public class danhSachTrungTuyen {
    public static void main(String[] args) throws Exception {
        File f = new File("THISINH.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<thiSinh> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            double toan = Double.parseDouble(sc.nextLine());
            double ly = Double.parseDouble(sc.nextLine());
            double hoa = Double.parseDouble(sc.nextLine());
            list.add(new thiSinh(ma, ten, toan, ly, hoa));
        }
        
        int soChiTieu = Integer.parseInt(sc.nextLine());
        list.sort((a, b) -> {
            int cmp = Double.compare(b.diemXetTuyen(), a.diemXetTuyen());
            if (cmp == 0)
                return a.getMa().compareTo(b.getMa());
            return cmp;
        });
        
        double diemChuan = 0;
        for (thiSinh ts : list) {
            if (soChiTieu != 0) {
                diemChuan = ts.diemXetTuyen();
                --soChiTieu;
            }
            else
                break;
        }
        System.out.printf("%.1f\n", diemChuan);
        
        for (thiSinh ts : list) {
            if (ts.diemXetTuyen() >= diemChuan) {
                System.out.print(ts);
                System.out.println("TRUNG TUYEN");
            }
            else {
                System.out.print(ts);
                System.out.println("TRUOT");
            }
        }
    }
}

class thiSinh {
    private String ma, ten;
    private double toan, ly, hoa;

    public thiSinh() {}

    public thiSinh(String ma, String ten, double toan, double ly, double hoa) {
        this.ma = ma;
        this.ten = ten;
        this.toan = toan;
        this.ly = ly;
        this.hoa = hoa;
    }

    public String getMa() {
        return ma;
    }
    
    public String chuanHoaTen() {
        ten = ten.replaceAll("\\s+", " ").trim().toLowerCase();
        String word[] = ten.split(" ");
        for (int i = 0; i < word.length; i++) {
            word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
        }
        
        return String.join(" ", word);
    }
    
    public double diemVung() {
        String tmp = ma.substring(0, 3);
        if (tmp.equals("KV1"))
            return 0.5;
        if (tmp.equals("KV2"))
            return 1.0;
        if (tmp.equals("KV3"))
            return 2.5;
        return 0;
    }
    
    public double diemXetTuyen() {
        return toan * 2 + ly + hoa + diemVung();
    }
    
    public String formatNumber(double x) {
        if (x % 1 == 0)
            return String.format("%.0f", x);
        return String.format("%.1f", x);
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s ", ma, chuanHoaTen(), formatNumber(diemVung()), 
                formatNumber(diemXetTuyen()));
    }
}