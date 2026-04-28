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
public class tuyenDung {
    public static double chuanHoaDiem(String str) {
        if (str.contains("."))
            return Double.parseDouble(str);
        
        long x = Long.parseLong(str);
        if (x == 10)
            return 10.0;
        if (x < 10)
            return x / 1.0;
        return x / 10.0;
    }
    
    public static class thiSinh {
        private String ma, ten;
        private double diemlt, diemth;
        private static int cnt = 1;

        public thiSinh() {
        }

        public thiSinh(String ten, double diemlt, double diemth) {
            this.ma = String.format("TS%02d", cnt++);
            this.ten = ten;
            this.diemlt = diemlt;
            this.diemth = diemth;
        }
        
        public double tinhDiemTB() {
            return (diemlt + diemth) / 2.0;
        }
        
        public String status() {
            double dtb = tinhDiemTB();
            
            if (dtb < 5)
                return "TRUOT";
            if (dtb >= 5 && dtb < 8)
                return "CAN NHAC";
            if (dtb >= 8 && dtb <= 9.5)
                return "DAT";
            return "XUAT SAC";
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + String.format("%.2f", tinhDiemTB()) + " " + status();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<thiSinh> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String lt = sc.nextLine();
            String th = sc.nextLine();
            
            double diemlt = chuanHoaDiem(lt), diemth = chuanHoaDiem(th);
            
            list.add(new thiSinh(ten, diemlt, diemth));
        }
        
        list.sort((a, b) -> Double.compare(b.tinhDiemTB(), a.tinhDiemTB()));
        
        for (thiSinh ts : list)
            System.out.println(ts);
    }
}

//3
//Nguyen Thai Binh
//45
//75
//Le Cong Hoa
//4
//4.5
//Phan Van Duc
//56
//56