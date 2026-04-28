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
public class sapXepTheoMaSinhVien {
    public static class sinhVien {
        private String ma, ten, lop, email;

        public sinhVien() {
        }

        public sinhVien(String ma, String ten, String lop, String email) {
            this.ma = ma;
            this.ten = ten;
            this.lop = lop;
            this.email = email;
        }

        public String getMa() {
            return ma;
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + lop + " " + email;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<sinhVien> list = new ArrayList<>();
        
        while (sc.hasNextLine()) {
            String ma = sc.nextLine();
            if (ma.equals(""))
                break;
            String ten = sc.nextLine();
            String lop = sc.nextLine();
            String email = sc.nextLine();
            list.add(new sinhVien(ma, ten, lop, email));
            
//            list.add(new sinhVien(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        
        list.sort((a, b) -> a.getMa().compareTo(b.getMa()));
        
        for (sinhVien sv : list)
            System.out.println(sv);
    }
}

//B16DCCN011
//Nguyen Trong Duc Anh
//D16CNPM1
//sv1@stu.ptit.edu.vn
//B15DCCN215
//To Ngoc Hieu
//D15CNPM3
//sv2@stu.ptit.edu.vn
//B15DCKT150
//Nguyen Ngoc Son
//D15CQKT02-B
//sv3@stu.ptit.edu.vn
//B15DCKT199
//Nguyen Trong Tung
//D15CQKT03-B
//sv4@stu.ptit.edu.vn