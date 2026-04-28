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
public class GiaoVien {
    private String maGiaoVien, hoTen;
    private int luongCoBan;
    
    public GiaoVien() {}
    
    public GiaoVien(String maGiaoVien, String hoTen, int luongCoBan) {
        this.maGiaoVien = maGiaoVien;
        this.hoTen = hoTen;
        this.luongCoBan = luongCoBan;
    }
    
    public int tinhLuong() {
        return luongCoBan * getHeSo();
    }
    
    public int getPhuCap() {
        String ma = maGiaoVien.substring(0, 2);
        
        if (ma.equals("HT"))
            return 2000000;
        if (ma.equals("HP"))
            return 900000;
        return 500000;
    }
    
    public int getHeSo() {
        String num = maGiaoVien.substring(2);
        int heSo = Integer.parseInt(num);
        return heSo;
    }
    
    public void input(Scanner sc) {
        maGiaoVien = sc.nextLine();
        hoTen = sc.nextLine();
        luongCoBan = sc.nextInt();
    }
    
    public void output() {
        System.out.printf("%s %s %d %d %d\n", maGiaoVien, hoTen, getHeSo(), getPhuCap(), luongCoBan * getHeSo() + getPhuCap());
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        GiaoVien gv = new GiaoVien();
        gv.input(sc);
        gv.output();
    }
}
