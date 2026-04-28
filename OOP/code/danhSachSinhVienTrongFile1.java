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
public class danhSachSinhVienTrongFile1 implements Comparable<danhSachSinhVienTrongFile1>{
    private String maSinhVien, hoTen, lopHoc, email;
    
    public danhSachSinhVienTrongFile1() {}
    
    public danhSachSinhVienTrongFile1(String ma, String ten, String lop, String email) {
        this.maSinhVien = ma;
        this.hoTen = ten;
        this.lopHoc = lop;
        this.email = email;
    }
    
    public void normalize_name() {
        hoTen = hoTen.replaceAll("\\s+", " ").toLowerCase().trim();
        String word[] = hoTen.split(" ");
        
        for (int i = 0; i < word.length; i++) {
            word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
        }
        
        hoTen = String.join(" ", word);
    }
    
    @Override
    public int compareTo(danhSachSinhVienTrongFile1 other) {
        return this.maSinhVien.compareTo(other.maSinhVien);
    }
    
    public void output() {
        System.out.printf("%s %s %s %s\n", maSinhVien, hoTen, lopHoc, email);
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("SINHVIEN.in");
        Scanner sc = new Scanner(f);
        
        int n = Integer.parseInt(sc.nextLine().trim());
        List<danhSachSinhVienTrongFile1> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            danhSachSinhVienTrongFile1 sv = new danhSachSinhVienTrongFile1();
            sv.maSinhVien = sc.nextLine();
            sv.hoTen = sc.nextLine();
            sv.lopHoc = sc.nextLine();
            sv.email = sc.nextLine();
            sv.normalize_name();
            list.add(sv);
        }
        
        Collections.sort(list);
        for (danhSachSinhVienTrongFile1 sv : list)
            sv.output();
    }
}
