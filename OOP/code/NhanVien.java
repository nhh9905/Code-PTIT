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
public class NhanVien {
    private String maNhanVien, hoTen, gioiTinh, ngaySinh, diaChi, maSoThue, ngayKiHopDong;
    
    public NhanVien() {}
    
    public NhanVien(String maNhanVien, String hoTen, String gioiTinh, String ngaySinh, String diaChi, String maSoThue, String ngayKiHopDong) {
        this.maNhanVien = maNhanVien;
        this.hoTen = hoTen;
        this.gioiTinh = gioiTinh;
        this.ngaySinh = ngaySinh;
        this.diaChi = diaChi;
        this.maSoThue = maSoThue;
        this.ngayKiHopDong = ngayKiHopDong;
    }
    
    public void setMaNhanVien() {
        this.maNhanVien = "00001";
    }
    
    public void input() {
        Scanner sc = new Scanner(System.in);
        
        hoTen = sc.nextLine();
        gioiTinh = sc.nextLine();
        ngaySinh = sc.nextLine();
        diaChi = sc.nextLine();
        maSoThue = sc.nextLine();
        ngayKiHopDong = sc.nextLine();
    }
    
    public void output() {
        System.out.printf("%s %s %s %s %s %s %s\n", maNhanVien, hoTen, gioiTinh, ngaySinh, diaChi, maSoThue, ngayKiHopDong);
    }
    
    public static void main(String[] args) {
        NhanVien nv = new NhanVien();
        nv.input();
        nv.setMaNhanVien();
        nv.output();
    }
}
