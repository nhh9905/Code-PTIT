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
public class PhanSo {
    private long tu, mau;
    
    public PhanSo() {
        this.tu = 1;
        this.mau = 1;
    }
    
    public PhanSo(long tu, long mau) {
        this.tu = tu;
        this.mau = mau;
    }
    
    public long getTu() {
        return tu;
    }
    
    public long getMau() {
        return mau;
    }
    
    public static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    public void rutGon() {
        long g = gcd(tu, mau);
        tu /= g;
        mau /= g;
    }
    
    public PhanSo cong(PhanSo other) {
        long tuMoi = this.tu * other.mau + this.mau * other.tu;
        long mauMoi = this.mau * other.mau;
        PhanSo kq = new PhanSo(tuMoi, mauMoi);
        kq.rutGon();
        
        return kq;
    }
    
    public void input(Scanner sc) {
        tu = sc.nextLong();
        mau = sc.nextLong();
        rutGon();
    }
    
    public void output() {
        System.out.printf("%d/%d\n", tu, mau);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PhanSo ps1 = new PhanSo(), ps2 = new PhanSo();
        ps1.input(sc);
        ps2.input(sc);
        PhanSo tong = ps1.cong(ps2);
        tong.output();
    }
}
