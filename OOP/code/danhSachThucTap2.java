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
public class danhSachThucTap2 {
    public static class sinhVien {
        private int stt;
        private String ma, ten, lop, email, doanhNghiep;
        private static int cnt = 1;

        public sinhVien() {
        }

        public sinhVien(String ma, String ten, String lop, String email, String doanhNghiep) {
            this.stt = cnt++;
            this.ma = ma;
            this.ten = ten;
            this.lop = lop;
            this.email = email;
            this.doanhNghiep = doanhNghiep;
        }

        public String getMa() {
            return ma;
        }
        
        public String getTen() {
            return ten;
        }
        
        public String getDoanhNghiep() {
            return doanhNghiep;
        }

        @Override
        public String toString() {
            return stt + " " + ma + " " + ten + " " + lop + " " + email + " " + doanhNghiep;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine().trim();
            String ten = sc.nextLine().trim();
            String lop = sc.nextLine().trim();
            String email = sc.nextLine().trim();
            String dn = sc.nextLine().trim();
            list.add(new sinhVien(ma, ten, lop, email, dn));
        }
        
        list.sort((a, b) -> a.getMa().compareTo(b.getMa()));
        
        int q = Integer.parseInt(sc.nextLine());
        while (q-- > 0) {
            String str = sc.nextLine();
            
            for (sinhVien sv : list) {
                if (sv.getDoanhNghiep().equals(str))
                    System.out.println(sv);
            }
        }
    }
}

//6
//B17DCCN016 
//Le Khac Tuan Anh 
//D17HTTT2   
//test1@stu.ptit.edu.vn
//VIETTEL
//B17DCCN107 
//Dao Thanh Dat    
//D17CNPM5   
//test2@stu.ptit.edu.vn
//FPT
//B17DCAT092 
//Cao Danh Huy     
//D17CQAT04-B
//test3@stu.ptit.edu.vn
//FPT
//B17DCCN388 
//Cao Sy Hai Long  
//D17CNPM2   
//test4@stu.ptit.edu.vn
//VNPT
//B17DCCN461 
//Dinh Quang Nghia 
//D17CNPM2   
//test5@stu.ptit.edu.vn
//FPT
//B17DCCN554 
//Bui Xuan Thai    
//D17CNPM1   
//test6@stu.ptit.edu.vn
//GAMELOFT
//1
//FPT