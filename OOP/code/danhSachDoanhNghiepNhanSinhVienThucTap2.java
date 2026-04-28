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
public class danhSachDoanhNghiepNhanSinhVienThucTap2 {
    public static class doanhNghiep {
        private String ma, ten;
        private long soSV;

        public doanhNghiep() {
        }

        public doanhNghiep(String ma, String ten, long soSV) {
            this.ma = ma;
            this.ten = ten;
            this.soSV = soSV;
        }

        public String getMa() {
            return ma;
        }
        
        public long getSoSV() {
            return soSV;
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + soSV;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<doanhNghiep> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            long num = Long.parseLong(sc.nextLine());
            list.add(new doanhNghiep(ma, ten, num));
        }
        
        list.sort((a, b) -> {
            if (a.getSoSV() != b.getSoSV())
                return Long.compare(b.getSoSV(), a.getSoSV());
            return a.getMa().compareTo(b.getMa());
        });
        
        int q = Integer.parseInt(sc.nextLine());
        while (q-- > 0) {
            String str = sc.nextLine();
            String word[] = str.split(" ");
            int a = Integer.parseInt(word[0]), b = Integer.parseInt(word[1]);
            
            System.out.println("DANH SACH DOANH NGHIEP NHAN TU " + a + " DEN " + b + " SINH VIEN:");
            for (doanhNghiep dn : list) {
                if (dn.getSoSV() >= a && dn.getSoSV() <= b)
                    System.out.println(dn);
            }
        }
    }
}

//4
//VIETTEL
//TAP DOAN VIEN THONG QUAN DOI VIETTEL
//40
//FSOFT
//CONG TY TNHH PHAN MEM FPT - FPT SOFTWARE
//300
//VNPT
//TAP DOAN BUU CHINH VIEN THONG VIET NAM
//200
//SUN
//SUN*
//50
//1
//30 50