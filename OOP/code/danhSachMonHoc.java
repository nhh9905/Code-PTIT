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
public class danhSachMonHoc implements Comparable<danhSachMonHoc>{
    private String maMonHoc, tenMonHoc;
    private int soTinChi;
    
    public danhSachMonHoc() {}
    
    public danhSachMonHoc(String ma, String ten, int num) {
        this.maMonHoc = ma;
        this.tenMonHoc = ten;
        this.soTinChi = num;
    }
    
    @Override
    public int compareTo(danhSachMonHoc other) {
        return this.tenMonHoc.compareTo(other.tenMonHoc);
    }
    
    public void output() {
        System.out.printf("%s %s %d\n", maMonHoc, tenMonHoc, soTinChi);
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("MONHOC.in");
        Scanner sc = new Scanner(f);
        
        int n = Integer.parseInt(sc.nextLine().trim());
        List<danhSachMonHoc> list = new ArrayList<>();
        while (n-- > 0) {
            danhSachMonHoc mh = new danhSachMonHoc();
            mh.maMonHoc = sc.nextLine();
            mh.tenMonHoc = sc.nextLine();
            mh.soTinChi = Integer.parseInt(sc.nextLine().trim());
            list.add(mh);
        }
        
        Collections.sort(list);
        for (danhSachMonHoc mh : list)
            mh.output();
    }
}
