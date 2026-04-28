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
public class hocBongSinhVien {
    public static class sinhVien {
        private String ten, status;
        private double gpa;
        private long drl;

        public sinhVien() {
        }

        public sinhVien(String ten, double gpa, long drl) {
            this.ten = ten;
            this.gpa = gpa;
            this.drl = drl;
        }

        public boolean duDK() {
            return gpa >= 2.5 && drl >= 70;
        }
        
        public String loaiHB() {
            if (gpa >= 3.6 && drl >= 90)
                return "XUATSAC";
            if (gpa >= 3.2 && drl >= 80)
                return "GIOI";
            if (gpa >= 2.5 && drl >= 70)
                return "KHA";
            return "KHONG";
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String part[] = str.split(" ");
        int n = Integer.parseInt(part[0]), m = Integer.parseInt(part[1]);
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            str = sc.nextLine();
            String part1[] = str.split(" ");
            double gpa = Double.parseDouble(part1[0]);
            long drl = Long.parseLong(part1[1]);
            sinhVien sv = new sinhVien(ten, gpa, drl);
            list.add(sv);
        }
        
        List<sinhVien> du = new ArrayList<>();
        for (sinhVien sv : list) {
            if (sv.duDK() == true)
                du.add(sv);
        }
        
        du.sort((a, b) -> {
            if (a.gpa != b.gpa)
                return Double.compare(b.gpa, a.gpa);
            return Long.compare(b.drl, a.drl);
        });
        
        double diemChuan = -1;
        if (!du.isEmpty()) {
            if (du.size() <= m) {
                diemChuan = du.get(du.size() - 1).gpa;
            } else {
                diemChuan = du.get(m - 1).gpa;
            }
        }
        
//        System.out.println(diemChuan);
        
        for (sinhVien sv : list) {
            if (sv.duDK() && sv.gpa >= diemChuan)
                sv.status = sv.loaiHB();
            else
                sv.status = "KHONG";
        }
        
        for (sinhVien sv : list)
            System.out.println(sv.ten + ": " + sv.status);
    }
}

//3 2
//Nguyen Van Nam
//3.59 75
//Tran Hong Ngoc
//3.61 90
//Do Van An
//3.22 90