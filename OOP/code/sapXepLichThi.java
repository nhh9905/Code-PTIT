/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
/**
 *
 * @author Asus
 */
public class sapXepLichThi {
    public static class monHoc {
        private String ma, ten, hinhThucThi;

        public monHoc() {
        }

        public monHoc(String ma, String ten, String hinhThucThi) {
            this.ma = ma;
            this.ten = ten;
            this.hinhThucThi = hinhThucThi;
        }

        public String getMa() {
            return ma;
        }

        public String getTen() {
            return ten;
        }
    }
    
    public static class caThi {
        private String ngay, gio, id;

        public caThi() {
        }

        public caThi(String ngay, String gio, String id) {
            this.ngay = ngay;
            this.gio = gio;
            this.id = id;
        }

        public String getNgay() {
            return ngay;
        }
        
        public LocalDate chuanHoaNgay() {
            DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            return LocalDate.parse(ngay, dtf);
        }

        public String getGio() {
            return gio;
        }

        public String getId() {
            return id;
        }
    }
    
    public static class lichThi {
        private String ma;
        private caThi ct;
        private monHoc mh;
        private String maNhom;
        private long soSV;

        public lichThi() {
        }

        public lichThi(String ma, caThi ct, monHoc mh, String maNhom, long soSV) {
            this.ma = ma;
            this.ct = ct;
            this.mh = mh;
            this.maNhom = maNhom;
            this.soSV = soSV;
        }

        public String getMa() {
            return ma;
        }
        
        public caThi getCt() {
            return ct;
        }

        public monHoc getMh() {
            return mh;
        }
        
        @Override
        public String toString() {
            return ct.getNgay() + " " + ct.getGio() + " " + ct.getId() + " " + mh.getTen() + " " + maNhom + " " + 
                    soSV;
        }
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("MONTHI.in");
        Scanner sc = new Scanner(f);
        
        // Nhap mon thi
        int n = Integer.parseInt(sc.nextLine());
        List<monHoc> dsMH = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            String hinhThuc = sc.nextLine();
            dsMH.add(new monHoc(ma, ten, hinhThuc));
        }
        sc.close();
        
        f = new File("CATHI.in");
        sc = new Scanner(f);
        // Nhap ca thi
        int m = Integer.parseInt(sc.nextLine());
        List<caThi> dsCT = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String ngay = sc.nextLine();
            String gio = sc.nextLine();
            String id = sc.nextLine();
            dsCT.add(new caThi(ngay, gio, id));
        }
        sc.close();
        
        f = new File("LICHTHI.in");
        sc = new Scanner(f);
        // Nhap lich thi
        int k = Integer.parseInt(sc.nextLine());
        List<lichThi> dsLT = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            String maCa = part[0], maMon = part[1], maNhom = part[2];
            long soSV = Long.parseLong(part[3]);
            
            // Tim mon thi
            monHoc mh = null;
            for (monHoc tmp : dsMH) {
                if (tmp.getMa().equals(maMon)) {
                    mh = tmp;
                    break;
                }
            }
            
            // Tim ca thi
            caThi ct = null;
            int stt = Integer.parseInt(maCa.substring(1));
            ct = dsCT.get(stt - 1);
            dsLT.add(new lichThi(maCa, ct, mh, maNhom, soSV));
        }
        sc.close();
        
        dsLT.sort((a, b) -> {
            if (!a.getCt().chuanHoaNgay().equals(b.getCt().chuanHoaNgay()))
                return a.getCt().chuanHoaNgay().compareTo(b.getCt().chuanHoaNgay());
            if (!a.getCt().getGio().equals(b.getCt().getGio()))
                return a.getCt().getGio().compareTo(b.getCt().getGio());
            return a.getMa().compareTo(b.getMa());
        });
        
        for (lichThi lt : dsLT)
            System.out.println(lt);
    }
}
