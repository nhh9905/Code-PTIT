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
public class baiToanTuyenSinh {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        thiSinh ts = new thiSinh();
        ts.input(sc);
        System.out.println(ts);
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
    
    public String getKhuVuc() {
        return ma.substring(0, 3);
    }
    
    public void input(Scanner sc) {
        ma = sc.nextLine();
        ten = sc.nextLine();
        toan = sc.nextDouble();
        ly = sc.nextDouble();
        hoa = sc.nextDouble();
    }
    
    public double diemUuTien() {
        if (getKhuVuc().equals("KV1"))
            return 0.5;
        if (getKhuVuc().equals("KV2"))
            return 1;
        return 2.5;
    }
    
    public double tongDiem() {
        return toan * 2 + ly + hoa;
    }
    
    public String status() {
        if (tongDiem() + diemUuTien() >= 24)
            return "TRUNG TUYEN";
        return "TRUOT";
    }
    
    public String formatNumber(double x) {
        if (x % 1 == 0)
            return String.format("%.0f", x);
        return String.format("%.1f", x);
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + formatNumber(diemUuTien()) + " " + formatNumber(tongDiem()) + " " + status();
    }
}