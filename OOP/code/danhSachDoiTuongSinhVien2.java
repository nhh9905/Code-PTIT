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
public class danhSachDoiTuongSinhVien2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String lop = sc.nextLine();
            String ns = sc.nextLine();
            double gpa = Double.parseDouble(sc.nextLine());
            list.add(new sinhVien(ten, lop, ns, gpa));
        }
        
        for (sinhVien sv : list)
            System.out.println(sv);
    }
}

class sinhVien {
    private String ma, ten, lop, ngaySinh;
    private double gpa;
    private static int cnt = 1;

    public sinhVien() {
    }

    public sinhVien(String ten, String lop, String ngaySinh, double gpa) {
        this.ma = String.format("B20DCCN%03d", cnt++);
        this.ten = ten;
        this.lop = lop;
        this.ngaySinh = ngaySinh;
        this.gpa = gpa;
    }
    
    public String chuanHoaTen() {
        ten = ten.replaceAll("\\s+", " ").trim().toLowerCase();
        String word[] = ten.split(" ");
        
        for (int i = 0; i < word.length; i++)
            word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
        
        return String.join(" ", word);
    }
    
    public String chuanHoaNgaySinh() {
        String part[] = ngaySinh.split("/");
        for (int i = 0; i < part.length; i++) {
            int k = Integer.parseInt(part[i]);
            part[i] = String.format("%02d", k);
        }
        
        return String.join("/", part);
    }

    @Override
    public String toString() {
        return ma + " " + chuanHoaTen() + " " + lop + " " + chuanHoaNgaySinh() + " " + String.format("%.2f", gpa);
    }
}
//1
//nGuyEn  vaN    biNH
//D20CQCN01-B
//2/12/2002
//3.1