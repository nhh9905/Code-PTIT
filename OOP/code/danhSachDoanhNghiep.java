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
public class danhSachDoanhNghiep implements Comparable<danhSachDoanhNghiep>{
    private String maDoanhNghiep, tenDoanhNghiep;
    private int soSinhVien;
    
    public danhSachDoanhNghiep() {}
    
    public danhSachDoanhNghiep(String ma, String ten, int num) {
        this.maDoanhNghiep = ma;
        this.tenDoanhNghiep = ten;
        this.soSinhVien = num;
    }
    
    @Override
    public int compareTo(danhSachDoanhNghiep other) {
        return this.maDoanhNghiep.compareTo(other.maDoanhNghiep);
    }
    
    public void output() {
        System.out.printf("%s %s %d\n", maDoanhNghiep, tenDoanhNghiep, soSinhVien);
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("DN.in");
        Scanner sc = new Scanner(f);
        List<danhSachDoanhNghiep> list = new ArrayList<>();
        
        int n = Integer.parseInt(sc.nextLine().trim());
        while (n-- > 0) {
            danhSachDoanhNghiep dn = new danhSachDoanhNghiep();
            dn.maDoanhNghiep = sc.nextLine();
            dn.tenDoanhNghiep = sc.nextLine();
            dn.soSinhVien = Integer.parseInt(sc.nextLine().trim());
            list.add(dn);
        }
        
        Collections.sort(list);
        for (danhSachDoanhNghiep dn : list)
            dn.output();
    }
}
