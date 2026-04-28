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
public class bangDiemThanhPhan1 {
    public static class sinhVien {
        private String ma, ten, lop;
        private double diem1, diem2, diem3;

        public sinhVien() {
        }

        public sinhVien(String ma, String ten, String lop, double diem1, double diem2, double diem3) {
            this.ma = ma;
            this.ten = ten;
            this.lop = lop;
            this.diem1 = diem1;
            this.diem2 = diem2;
            this.diem3 = diem3;
        }

        public String getMa() {
            return ma;
        }
        
        public String dinhDangSo(double x) {
            return String.format("%.1f", x);
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + lop + " " + dinhDangSo(diem1) + " " + dinhDangSo(diem2) + " " + dinhDangSo(diem3);
        }

        
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            String lop = sc.nextLine();
            double diem1 = Double.parseDouble(sc.nextLine());
            double diem2 = Double.parseDouble(sc.nextLine());
            double diem3 = Double.parseDouble(sc.nextLine());
            list.add(new sinhVien(ma, ten, lop, diem1, diem2, diem3));
        }
        
        list.sort((a, b) -> a.getMa().compareTo(b.getMa()));
        
        int cnt = 1;
        for (sinhVien sv : list)
            System.out.println((cnt++) + " " + sv);
    }
}

//3
//B20DCCN999
//Nguyen Van An
//D20CQCN04-B
//10.0
//9.0
//8.0
//B20DCAT001
//Le Van Nam
//D20CQAT02-B
//6.0
//6.0
//4.0
//B20DCCN111
//Tran Hoa Binh
//D20CQCN04-B
//9.0
//5.0
//6.0