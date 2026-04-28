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
public class quanLyBanHang1 {
    public static class khachHang {
        private String ma, ten, gioiTinh, ngaySinh, diaChi;
        private static int cnt = 1;

        public khachHang() {
        }

        public khachHang(String ten, String gioiTinh, String ngaySinh, String diaChi) {
            this.ma = String.format("KH%03d", cnt++);
            this.ten = ten;
            this.gioiTinh = gioiTinh;
            this.ngaySinh = ngaySinh;
            this.diaChi = diaChi;
        }

        public String getTen() {
            return ten;
        }

        public String getDiaChi() {
            return diaChi;
        }

        public String getMa() {
            return ma;
        }
        
        
    }
    
    public static class matHang {
        private String ma, ten, donVi;
        private long giaMua, giaBan;
        private static int cnt = 1;

        public matHang() {
        }

        public matHang(String ten, String donVi, long giaMua, long giaBan) {
            this.ma = String.format("MH%03d", cnt++);
            this.ten = ten;
            this.donVi = donVi;
            this.giaMua = giaMua;
            this.giaBan = giaBan;
        }

        public long getGiaBan() {
            return giaBan;
        }

        public String getTen() {
            return ten;
        }

        public String getDonVi() {
            return donVi;
        }

        public long getGiaMua() {
            return giaMua;
        }

        public String getMa() {
            return ma;
        }
        
        
    }
    
    public static class hoaDon {
        private String maHD;
        private khachHang kh;
        private matHang mh;
        private long soLuong;
        private static int cnt = 1;

        public hoaDon() {
        }

        public hoaDon(khachHang kh, matHang mh, long soLuong) {
            this.maHD = String.format("HD%03d", cnt++);
            this.kh = kh;
            this.mh = mh;
            this.soLuong = soLuong;
        }
        
        public long thanhTien() {
            return mh.getGiaBan() * soLuong;
        }
        
        public long tinhLoiNhuan() {
            return thanhTien() - mh.getGiaMua() * soLuong;
        }

        @Override
        public String toString() {
            return maHD + " " + kh.getTen() + " " + kh.getDiaChi() + " " + mh.getTen() + " " + 
                    soLuong + " " + thanhTien() + " " + tinhLoiNhuan();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<khachHang> dsKH = new ArrayList<>();
        
        // Nhap khach hang
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String gt = sc.nextLine();
            String ns = sc.nextLine();
            String dc = sc.nextLine();
            khachHang kh = new khachHang(ten, gt, ns, dc);
            dsKH.add(kh);
        }
        
        List<matHang> dsMH = new ArrayList<>();
        // Nhap mat hang
        int m = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < m; i++) {
            String ten = sc.nextLine();
            String dv = sc.nextLine();
            long mua = Long.parseLong(sc.nextLine());
            long ban = Long.parseLong(sc.nextLine());
            matHang mh = new matHang(ten, dv, mua, ban);
            dsMH.add(mh);
        }
        
        List<hoaDon> dsHD = new ArrayList<>();
        // Nhap hoa don
        int k = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < k; i++) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            String maKH = part[0], maMH = part[1];
            long cnt = Long.parseLong(part[2]);
            khachHang kh = null;
            matHang mh = null;
            
            for (khachHang tmp : dsKH) {
                if (tmp.getMa().equals(maKH)) {
                    kh = tmp;
                    break;
                }
            }
            
            for (matHang tmp : dsMH) {
                if (tmp.getMa().equals(maMH)) {
                    mh = tmp;
                    break;
                }
            }
            
            hoaDon hd = new hoaDon(kh, mh, cnt);
            dsHD.add(hd);
        }
        
        dsHD.sort((a, b) -> Long.compare(b.tinhLoiNhuan(), a.tinhLoiNhuan()));
        for (hoaDon hd : dsHD)
            System.out.println(hd);
    }
}

//2
//Nguyen Van Nam
//Nam
//12/12/1997
//Mo Lao-Ha Dong-Ha Noi
//Tran Van Binh
//Nam
//11/14/1995
//Phung Khoang-Nam Tu Liem-Ha Noi
//2
//Ao phong tre em
//Cai
//25000
//41000
//Ao khoac nam
//Cai
//240000
//515000
//3
//KH001 MH001 2
//KH001 MH002 3
//KH002 MH002 4