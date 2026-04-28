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
public class bangTinhGioChuan {
    public static class monHoc {
        private String ma, ten;

        public monHoc() {
        }

        public monHoc(String ma, String ten) {
            this.ma = ma;
            this.ten = ten;
        }

        public String getMa() {
            return ma;
        }

        public String getTen() {
            return ten;
        }
        
        
    }
    
    public static class giangVien {
        private String ma, ten;

        public giangVien() {
        }

        public giangVien(String ma, String ten) {
            this.ma = ma;
            this.ten = ten;
        }

        public String getMa() {
            return ma;
        }

        public String getTen() {
            return ten;
        }
    }
    
    public static class lopHoc {
        private giangVien gv;
        private monHoc mh;
        private double gio;

        public lopHoc() {
        }

        public lopHoc(giangVien gv, monHoc mh, double gio) {
            this.gv = gv;
            this.mh = mh;
            this.gio = gio;
        }

        public giangVien getGv() {
            return gv;
        }

        public monHoc getMh() {
            return mh;
        }
        
        public double getGio() {
            return gio;
        }

        public void setGio(double gio) {
            this.gio = gio;
        }
        
        @Override
        public String toString() {
            return gv.getTen() + String.format("%.2f", gio);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Nhap mon hoc
        int n = Integer.parseInt(sc.nextLine());
        List<monHoc> dsMH = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            String ma = part[0], ten = "";
            
            for (int j = 1; j < part.length; j++)
                ten += part[j] + " ";
            dsMH.add(new monHoc(ma, ten));
        }
        
        // Nhap giang vien
        int m = Integer.parseInt(sc.nextLine());
        List<giangVien> dsGV = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            String ma = part[0], ten = "";
            
            for (int j = 1; j < part.length; j++)
                ten += part[j] + " ";
            dsGV.add(new giangVien(ma, ten));
        }
        
        // Nhap lop hoc
        int k = Integer.parseInt(sc.nextLine());
        List<lopHoc> dsLH = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            String maGV = part[0], maMH = part[1];
            double gio = Double.parseDouble(part[2]);
            giangVien gv = null;
            
            for (giangVien tmp : dsGV) {
                if (tmp.getMa().equals(maGV)) {
                    gv = tmp;
                    break;
                }
            }
            
            monHoc mh = null;
            for (monHoc tmp : dsMH) {
                if (tmp.getMa().equals(maMH)) {
                    mh = tmp;
                    break;
                }
            }
            
            dsLH.add(new lopHoc(gv, mh, gio));
        }
        
        String maGV = sc.nextLine();
        for (lopHoc lh : dsLH) {
            if (lh.getGv().getMa().equals(maGV)) {
                System.out.println("Giang vien: " + lh.getGv().getTen());
                double tong = 0;
                for (lopHoc lh1 : dsLH) {
                    if (lh1.getGv().getMa().equals(maGV)) {
                        System.out.println(lh1.getMh().getTen() + lh1.getGio());
                        tong += lh1.getGio();
                    }
                }
                System.out.println("Tong: " + String.format("%.2f", tong));
                break;
            }
        }
    }
}

//2
//INT1155 Tin hoc co so 2
//INT1306 Cau truc du lieu va giai thuat
//2
//GV01 Nguyen Van An
//GV02 Hoang Binh Minh
//2
//GV01 INT1155 113.2
//GV02 INT1306 126.72
//GV01