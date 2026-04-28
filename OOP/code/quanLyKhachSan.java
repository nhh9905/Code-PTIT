/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
/**
 *
 * @author Asus
 */
public class quanLyKhachSan {
    public static class Phong {
        private String kyHieu, loai;
        private double donGia, phiDV;

        public Phong() {
        }

        public Phong(String kyHieu, String loai, double donGia, double phiDV) {
            this.kyHieu = kyHieu;
            this.loai = loai;
            this.donGia = donGia;
            this.phiDV = phiDV;
        }

        public String getKyHieu() {
            return kyHieu;
        }

        public double getDonGia() {
            return donGia;
        }

        public double getPhiDV() {
            return phiDV;
        }
        
        
    }
    
    public static class khachHang {
        private String maKH, ten, maPhong;
        private Phong phong;
        private LocalDate ngayDen, ngayDi;
        private static int cnt = 1;

        public khachHang() {
        }

        public khachHang(String ten, String maPhong, Phong phong, LocalDate ngayDen, LocalDate ngayDi) {
            this.maKH = String.format("KH%02d", cnt++);
            this.ten = ten;
            this.maPhong = maPhong;
            this.phong = phong;
            this.ngayDen = ngayDen;
            this.ngayDi = ngayDi;
        }
        
        public long tinhSoNgay() {
            long kq = ChronoUnit.DAYS.between(ngayDen, ngayDi);
            if (kq == 0)
                return 1;
            return kq;
        }
        
        public double tinhTien() {
            return phong.getDonGia() * tinhSoNgay();
        }
        
        public double tinhGiamGia() {
            long ngay = tinhSoNgay();
            if (ngay > 30)
                return tinhTien() * 0.06;
            if (ngay >= 20)
                return tinhTien() * 0.04;
            if (ngay >= 10)
                return tinhTien() * 0.02;
            return 0;
        }
        
        public double thanhTien() {
            double tien = tinhTien() - tinhGiamGia();
            return tien + tien * phong.getPhiDV();
        }

        @Override
        public String toString() {
            return maKH + " " + ten + " " + maPhong + " " + tinhSoNgay() + " " + 
                    String.format("%.2f", thanhTien());
        }
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("DATA.in");
        Scanner sc = new Scanner(f);
        
        int n = Integer.parseInt(sc.nextLine());
        List<Phong> dsPhong = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            String kyHieu = part[0], loai = part[1];
            double donGia = Double.parseDouble(part[2]), phiDV = Double.parseDouble(part[3]);
            dsPhong.add(new Phong(kyHieu, loai, donGia, phiDV));
        }
        
        int m = Integer.parseInt(sc.nextLine());
        List<khachHang> dsKH = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String ten = sc.nextLine();
            String maPhong = sc.nextLine();
            
            Phong phong = null;
            for (Phong tmp : dsPhong) {
                if (tmp.getKyHieu().equals(maPhong.substring(2, 3))) {
                    phong = tmp;
                    break;
                }
            }
            
            DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            String den = sc.nextLine();
            LocalDate ngayDen = LocalDate.parse(den, dtf);
            String di = sc.nextLine();
            LocalDate ngayDi = LocalDate.parse(di, dtf);
            dsKH.add(new khachHang(ten, maPhong, phong, ngayDen, ngayDi));
        }
        
        dsKH.sort((a, b) -> Long.compare(b.tinhSoNgay(), a.tinhSoNgay()));
        
        for (khachHang kh : dsKH)
            System.out.println(kh);
    }
}
