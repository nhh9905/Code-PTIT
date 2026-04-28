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
public class ThiSinh {
    private String hoTen, ngaySinh;
    private double diem1, diem2, diem3;
    
    public ThiSinh() {}
    
    public ThiSinh(String hoTen, String ngaySinh, double diem1, double diem2, double diem3) {
        this.hoTen = hoTen;
        this.ngaySinh = ngaySinh;
        this.diem1 = diem1;
        this.diem2 = diem2;
        this.diem3 = diem3;
    }
    
    public String getHoTen() {
        return hoTen;
    }
    
    public String getNgaySinh() {
        return ngaySinh;
    }
    
    public double getDiem1() {
        return diem1;
    }
    
    public double getDiem2() {
        return diem2;
    }
    
    public double getDiem3() {
        return diem3;
    }
    
    public double tongDiem() {
        return getDiem1() + getDiem2() + getDiem3();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String ten = sc.nextLine(), ns = sc.nextLine();
        double diem1 = sc.nextDouble(), diem2 = sc.nextDouble(), diem3 = sc.nextDouble();
        
        ThiSinh ts = new ThiSinh(ten, ns, diem1, diem2, diem3);
        
        System.out.printf("%s %s %.1f\n", ts.getHoTen(), ts.getNgaySinh(), ts.tongDiem());
    }
}
