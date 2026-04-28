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
public class SinhVien {
    private String maSinhVien, tenSinhVien, ngaySinh, lopHoc;
    private float gpa;
    
    public SinhVien() {}
    
    public SinhVien(String ma, String ten, String ns, String lop, float gpa) {
        this.maSinhVien = ma;
        this.tenSinhVien = ten;
        this.ngaySinh = ns;
        this.lopHoc = lop;
        this.gpa = gpa;
    }
    
    public void setMa(int cnt) {
        this.maSinhVien = String.format("B20DCCN%03d", cnt);
    }
    
    public void setNgaySinh() {
        
    }
    
    public void input() {
        
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            
        }
    }
}

//1
//Nguyen Van An
//D20CQCN01-B
//2/12/2002
//3.19