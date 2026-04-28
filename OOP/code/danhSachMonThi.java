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
public class danhSachMonThi {
    public static void main(String[] args) throws Exception {
        File f = new File("MONHOC.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<monHoc> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            String hinhThuc = sc.nextLine();
            list.add(new monHoc(ma, ten, hinhThuc));
        }
        
        list.sort((a, b) -> a.getMa().compareTo(b.getMa()));
        for (monHoc mh : list)
            System.out.println(mh);
    }
}

class monHoc {
    private String ma, ten, hinhThuc;

    public monHoc() {}

    public monHoc(String ma, String ten, String hinhThuc) {
        this.ma = ma;
        this.ten = ten;
        this.hinhThuc = hinhThuc;
    }

    public String getMa() {
        return ma;
    }
    
    @Override
    public String toString() {
        return ma + " " + ten + " " + hinhThuc;
    }
}