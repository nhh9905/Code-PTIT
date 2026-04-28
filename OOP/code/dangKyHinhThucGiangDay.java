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
public class dangKyHinhThucGiangDay {
    public static void main(String[] args) throws Exception {
        File f = new File("MONHOC.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<monHoc> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            int num = Integer.parseInt(sc.nextLine());
            String lt = sc.nextLine();
            String th = sc.nextLine();
            list.add(new monHoc(ma, ten, lt, th, num));
        }
        
        List<monHoc> ans = new ArrayList<>();
        for (monHoc mh : list) {
            if (mh.getThucHanh().equals("Truc tuyen") || mh.getThucHanh().endsWith(".ptit.edu.vn"))
                ans.add(mh);
        }
        
        ans.sort((a, b) -> a.getMa().compareTo(b.getMa()));
        for (monHoc mh : ans)
            System.out.println(mh);
    }
}

class monHoc {
    private String ma, ten, lyThuyet, thucHanh;
    private int soTinChi;

    public monHoc() {}

    public monHoc(String ma, String ten, String lyThuyet, String thucHanh, int soTinChi) {
        this.ma = ma;
        this.ten = ten;
        this.lyThuyet = lyThuyet;
        this.thucHanh = thucHanh;
        this.soTinChi = soTinChi;
    }

    public String getMa() {
        return ma;
    }
    
    public String getThucHanh() {
        return thucHanh;
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + soTinChi + " " + lyThuyet + " " + thucHanh;
    }
}