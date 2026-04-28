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
public class tinhDiemTrungBinh {
    public static class sinhVien {
        private String ma, ten;
        private int rank;
        private double diem1, diem2, diem3;
        private static int cnt = 1;

        public sinhVien() {
        }

        public sinhVien(String ten, double diem1, double diem2, double diem3) {
            this.ma = String.format("SV%02d", cnt++);
            this.ten = ten;
            this.diem1 = diem1;
            this.diem2 = diem2;
            this.diem3 = diem3;
        }
        
        public double tinhDiemTB() {
            return (diem1 * 3 + diem2 * 3 + diem3 * 2)/8.0;
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + String.format("%.2f", tinhDiemTB()) + " " + rank;
        }
    }
    
    public static String chuanHoaTen(String str) {
        str = str.replaceAll("\\s+", " ").toLowerCase().trim();
        String word[] = str.split(" ");
        
        for (int i = 0; i < word.length; i++)
            word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
        
        return String.join(" ", word);
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("BANGDIEM.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            double diem1 = Double.parseDouble(sc.nextLine());
            double diem2 = Double.parseDouble(sc.nextLine());
            double diem3 = Double.parseDouble(sc.nextLine());
            
            ten = chuanHoaTen(ten);
            list.add(new sinhVien(ten, diem1, diem2, diem3));
        }
        
        list.sort((a, b) -> Double.compare(b.tinhDiemTB(), a.tinhDiemTB()));
        
        list.get(0).rank = 1;
        for (int i = 1; i < n; i++) {
            if (list.get(i).tinhDiemTB() == list.get(i - 1).tinhDiemTB())
                list.get(i).rank = list.get(i - 1).rank;
            else
                list.get(i).rank = i + 1;
        }
        
        for (sinhVien sv : list)
            System.out.println(sv);
    }
}
