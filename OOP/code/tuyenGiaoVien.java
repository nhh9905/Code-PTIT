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
public class tuyenGiaoVien {
    public static class giaoVien {
        private String ma, ten, maXetTuyen;
        private double tin, chuyenMon;
        private static int cnt = 1;

        public giaoVien() {
        }

        public giaoVien(String ten, String maXetTuyen, double tin, double chuyenMon) {
            this.ma = String.format("GV%02d", cnt++);
            this.ten = ten;
            this.maXetTuyen = maXetTuyen;
            this.tin = tin;
            this.chuyenMon = chuyenMon;
        }
        
        public String monHoc() {
            String tmp = maXetTuyen.substring(0, 1);
            
            if (tmp.equals("A"))
                return "TOAN";
            if (tmp.equals("B"))
                return "LY";
            return "HOA";
        }
        
        public double diemUuTien() {
            String tmp = maXetTuyen.substring(1);
            
            if (tmp.equals("1"))
                return 2.0;
            if (tmp.equals("2"))
                return 1.5;
            if (tmp.equals("3"))
                return 1.0;
            return 0;
        }
        
        public double tongDiem() {
            return tin * 2 + chuyenMon + diemUuTien();
        }
        
        public String status() {
            if (tongDiem() >= 18)
                return "TRUNG TUYEN";
            return "LOAI";
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + monHoc() + " " + String.format("%.1f", tongDiem()) + " " + status();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<giaoVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String ma = sc.nextLine();
            double tin = Double.parseDouble(sc.nextLine());
            double chuyenMon = Double.parseDouble(sc.nextLine());
            list.add(new giaoVien(ten, ma, tin, chuyenMon));
        }
        
        list.sort((a, b) -> Double.compare(b.tongDiem(), a.tongDiem()));
        
        for (giaoVien gv : list)
            System.out.println(gv);
    }
}

//3
//Le Van Binh
//A1
//7.0
//3.0
//Tran Van Toan
//B3
//4.0
//7.0
//Hoang Thi Tam
//C2
//7.0
//6.0