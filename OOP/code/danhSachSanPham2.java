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
public class danhSachSanPham2 implements Comparable<danhSachSanPham2> {
    private String maSanPham, tenSanPham;
    private int giaBan, thoiHanBaoHanh;
    
    public danhSachSanPham2() {}
    
    public danhSachSanPham2(String ma, String ten, int gia, int tgian) {
        this.maSanPham = ma;
        this.tenSanPham = ten;
        this.giaBan = gia;
        this.thoiHanBaoHanh = tgian;
    }
    
    @Override
    public int compareTo(danhSachSanPham2 other) {
        if (this.giaBan == other.giaBan)
            return this.maSanPham.compareTo(other.maSanPham);
        return other.giaBan - this.giaBan;
    }
    
    public void input(Scanner sc) {
        maSanPham = sc.nextLine();
        tenSanPham = sc.nextLine();
        giaBan = sc.nextInt();
        thoiHanBaoHanh = sc.nextInt();
        if (sc.hasNextLine())
            sc.nextLine();
    }
    
    public void output() {
        System.out.println(maSanPham + " " + tenSanPham + " " + giaBan + " " + thoiHanBaoHanh);
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("SANPHAM.in");
        Scanner sc = new Scanner(f);
        int t = Integer.parseInt(sc.nextLine().trim());
        
        List<danhSachSanPham2> list = new ArrayList<>();
        while (t-- > 0) {
            danhSachSanPham2 sp = new danhSachSanPham2();
            sp.input(sc);
            list.add(sp);
        }
        
        Collections.sort(list);
        for (danhSachSanPham2 sp : list)
            sp.output();
    }
}
