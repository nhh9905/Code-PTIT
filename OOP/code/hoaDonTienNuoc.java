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
public class hoaDonTienNuoc {
    public static class khachHang {
        private String ma, ten;
        private long cu, moi;
        private static int cnt = 1;

        public khachHang() {
        }

        public khachHang(String ten, long cu, long moi) {
            this.ma = String.format("KH%02d", cnt++);
            this.ten = ten;
            this.cu = cu;
            this.moi = moi;
        }
        
        public long getChiSo() {
            return moi - cu;
        }
        
        public long getDonGia() {
            long tmp = getChiSo();
            
            if (tmp < 50)
                return 100 * tmp;
            if (tmp < 100)
                return 50 * 100 + (tmp - 50) * 150;
            return 50 * 100 + 50 * 150 + (tmp - 100) * 200;
        }
        
        public long getPhuPhi() {
            long tmp = getChiSo();
            
            if (tmp < 50)
                return Math.round(getDonGia() * 0.02);
            if (tmp < 100)
                return Math.round(getDonGia() * 0.03);
            return Math.round(getDonGia() * 0.05);
        }
        
        public long tinhTien() {
            return getDonGia() + getPhuPhi();
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + tinhTien();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<khachHang> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            long cu = Long.parseLong(sc.nextLine());
            long moi = Long.parseLong(sc.nextLine());
            list.add(new khachHang(ten, cu, moi));
        }
        
        list.sort((a, b) -> Long.compare(b.tinhTien(), a.tinhTien()));
        
        for (khachHang kh : list)
            System.out.println(kh);
    }
}

//3
//Le Thi Thanh
//468
//500
//Le Duc Cong
//160
//230
//Ha Hue Anh
//410
//612