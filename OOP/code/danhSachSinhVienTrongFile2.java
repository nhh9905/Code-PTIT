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
public class danhSachSinhVienTrongFile2 {
    private String maSinhVien, hoTen, lopHoc, ngaySinh;
    private double gpa;
    
    public danhSachSinhVienTrongFile2() {}
    
    public danhSachSinhVienTrongFile2(String ma, String ten, String lop, String ns, double gpa) {
        this.maSinhVien = ma;
        this.hoTen = ten;
        this.lopHoc = lop;
        this.ngaySinh = ns;
        this.gpa = gpa;
    }
    
    public void setMa(int cnt) {
        this.maSinhVien = String.format("B20DCCN%03d", cnt);
    }
    
    public void setNgaySinh() {
        String word[] = ngaySinh.split("/");
        if (word[0].length() < 2)
            word[0] = "0" + word[0];
        if (word[1].length() < 2)
            word[1] = "0" + word[1];
        while (word[2].length() < 4)
            word[2] = "0" + word[2];
        this.ngaySinh = word[0] + "/" + word[1] + "/" + word[2];
    }
    
    public void output() {
        System.out.printf("%s %s %s %s %.2f\n", maSinhVien, hoTen, lopHoc, ngaySinh, gpa);
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("SV.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine().trim());
        
        for (int i = 1; i <= n; i++) {
            danhSachSinhVienTrongFile2 sv = new danhSachSinhVienTrongFile2();
            sv.hoTen = sc.nextLine();
            sv.lopHoc = sc.nextLine();
            sv.ngaySinh = sc.nextLine();
            sv.gpa = Double.parseDouble(sc.nextLine().trim());
            sv.setMa(i);
            sv.setNgaySinh();
            sv.output();
        }
    }
}
