/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
/**
 *
 * @author Asus
 */
public class danhSachLuuTru implements Comparable<danhSachLuuTru> {
    private String maKhachHang, hoTen, maPhong, ngayDen, ngayDi;
    
    public danhSachLuuTru() {}
    
    public danhSachLuuTru(String maKhach, String ten, String maPhong, String den, String di) {
        this.maKhachHang = maKhach;
        this.hoTen = ten;
        this.maPhong = maPhong;
        this.ngayDen = den;
        this.ngayDi = di;
    }
    
    public void setMaKhachHang(int num) {
        this.maKhachHang = String.format("KH%02d", num);
    }
    
    public long tinhSoNgay(String s1, String s2) throws ParseException {
        SimpleDateFormat f = new SimpleDateFormat("dd/MM/yyyy");
        long d1 = f.parse(s1).getTime(), d2 = f.parse(s2).getTime();
        return (d2 - d1) / (1000 * 60 * 60 * 24);
    }
    
    public long tinhSoNgay() {
        try {
            return tinhSoNgay(ngayDen, ngayDi);
        } catch (ParseException e) {
            return 0;
        }
    }
    
    @Override
    public int compareTo(danhSachLuuTru other) {
        return Long.compare(other.tinhSoNgay(), this.tinhSoNgay());
    }
    
    public void output() {
        System.out.printf("%s %s %s %d\n", maKhachHang, hoTen, maPhong, tinhSoNgay());
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("KHACH.in");
        Scanner sc = new Scanner(f);
        
        int n = Integer.parseInt(sc.nextLine().trim());
        List<danhSachLuuTru> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            danhSachLuuTru lt = new danhSachLuuTru();
            lt.hoTen = sc.nextLine();
            lt.maPhong = sc.nextLine();
            lt.ngayDen = sc.nextLine();
            lt.ngayDi = sc.nextLine();
            lt.setMaKhachHang(i);
            list.add(lt);
        }
        
        Collections.sort(list);
        for (danhSachLuuTru lt : list)
            lt.output();
    }
}
