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
public class lietKeNhanVienTheoNhom {
    public static class nhanVien {
        private String ma, ten, chucVu;

        public nhanVien() {
        }

        public nhanVien(String ma, String ten) {
            this.ma = ma;
            this.ten = ten;
        }
        
        public void setChucVu(String x) {
            this.chucVu = x;
        }
        
        public String getChucVu() {
            return chucVu;
        }
        
        public long getHeSoLuong() {
            return Long.parseLong(ma.substring(2, 4));
        }
        
        public long getSoHieu() {
            return Long.parseLong(ma.substring(4, 7));
        }

        @Override
        public String toString() {
            return ten + " " + getChucVu() + " " + String.format("%03d", getSoHieu()) + " " + 
                    String.format("%02d", getHeSoLuong());
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<nhanVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            String word[] = str.split(" ");
            String ma = word[0], ten = "";
            
            for (int j = 1; j < word.length; j++)
                ten = ten.concat(word[j] + " ");
            ten = ten.trim();
            
            nhanVien nv = new nhanVien(ma, ten);
            nv.setChucVu(ma.substring(0, 2));
            list.add(nv);
        }
        
        int cntGiamDoc = 0, cntTruongPhong = 0, cntPhoPhong = 0;
        for (nhanVien nv : list) {
            if (nv.getChucVu().equals("GD")) {
                if (cntGiamDoc < 1)
                    ++cntGiamDoc;
                else
                    nv.setChucVu("NV");
            }
            
            if (nv.getChucVu().equals("TP")) {
                if (cntTruongPhong < 3)
                    ++cntTruongPhong;
                else
                    nv.setChucVu("NV");
            }
            
            if (nv.getChucVu().equals("PP")) {
                if (cntPhoPhong < 3)
                    ++cntPhoPhong;
                else
                    nv.setChucVu("NV");
            }
        }
        
        list.sort((a, b) -> {
            if (a.getHeSoLuong() != b.getHeSoLuong())
                return Long.compare(b.getHeSoLuong(), a.getHeSoLuong());
            return Long.compare(a.getSoHieu(), b.getSoHieu());
        });
        
        int q = Integer.parseInt(sc.nextLine());
        while (q-- > 0) {
            String chucVu = sc.nextLine();
            for (nhanVien nv : list) {
                if (nv.getChucVu().equals(chucVu))
                    System.out.println(nv);
            }
            System.out.println();
        }
    }
}

//6
//GD08001 Nguyen Kim Loan
//TP05002 Hoang Thanh Tuan
//TP05001 Tran Binh Nguyen
//PP06002 Phan Trung Tuan
//PP06001 Tran Quoc Huy
//NV04003 Vo Van Lan
//2
//TP
//PP