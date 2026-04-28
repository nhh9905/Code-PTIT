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
public class xacDinhDanhSachTrungTuyen {
    public static class thiSinh {
        private String ma, ten, status;
        private double toan, ly, hoa;

        public thiSinh() {
        }

        public thiSinh(String ma, String ten, double toan, double ly, double hoa) {
            this.ma = ma;
            this.ten = ten;
            this.toan = toan;
            this.ly = ly;
            this.hoa = hoa;
        }

        public void setStatus(String status) {
            this.status = status;
        }
        
        public String getKhuVuc() {
            return ma.substring(0, 3);
        }
        
        public double diemKhuVuc() {
            if (getKhuVuc().equals("KV1"))
                return 0.5;
            if (getKhuVuc().equals("KV2"))
                return 1;
            if (getKhuVuc().equals("KV3"))
                return 2.5;
            return 0;
        }
        
        public double tinhTongDiem() {
            return toan * 2 + ly + hoa + diemKhuVuc();
        }

        public String getMa() {
            return ma;
        }

        public String getTen() {
            return ten;
        }

        public String getStatus() {
            return status;
        }
    }
    
    public static String formatNumber(double x) {
        if (x % 1 == 0)
            return String.format("%.0f", x);
        return String.format("%.1f", x);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<thiSinh> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            double toan = Double.parseDouble(sc.nextLine());
            double ly = Double.parseDouble(sc.nextLine());
            double hoa = Double.parseDouble(sc.nextLine());
            list.add(new thiSinh(ma, ten, toan, ly, hoa));
        }
        
        list.sort((a, b) -> {
            if (a.tinhTongDiem() != b.tinhTongDiem())
                return Double.compare(b.tinhTongDiem(), a.tinhTongDiem());
            return a.getMa().compareTo(b.getMa());
        });
        
        int m = Integer.parseInt(sc.nextLine());
        double diemChuan = 0;
        for (thiSinh ts : list) {
            if (m != 0 || ts.tinhTongDiem() == diemChuan) {
                ts.setStatus("TRUNG TUYEN");
                diemChuan = ts.tinhTongDiem();
                if (m != 0)
                    --m;
            }
            else
                ts.setStatus("TRUOT");
        }
        
        System.out.printf("%.1f\n", diemChuan);
        for (thiSinh ts : list)
            System.out.printf("%s %s %s %s %s\n", ts.getMa(), ts.getTen(), formatNumber(ts.diemKhuVuc()),
                    formatNumber(ts.tinhTongDiem()), ts.getStatus());
    }
}

//2
//KV2A002
//Hoang Thanh Tuan
//5
//6
//5
//KV3B123
//Ly Thi Thu Ha
//8
//6.5
//7
//1