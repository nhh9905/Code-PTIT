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
public class bangXepHang {
    public static class sinhVien {
        private String ten;
        private long soBai, soSubmit;

        public sinhVien() {
        }

        public sinhVien(String ten, long soBai, long soSubmit) {
            this.ten = ten;
            this.soBai = soBai;
            this.soSubmit = soSubmit;
        }

        public String getTen() {
            return ten;
        }

        public long getSoBai() {
            return soBai;
        }

        public long getSoSubmit() {
            return soSubmit;
        }

        @Override
        public String toString() {
            return ten + " " + soBai + " " + soSubmit;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String str = sc.nextLine();
            String word[] = str.split(" ");
            long bai = Long.parseLong(word[0]);
            long submit = Long.parseLong(word[1]);
            list.add(new sinhVien(ten, bai, submit));
        }
        
        list.sort((a, b) -> {
            if (a.getSoBai() != b.getSoBai())
                return Long.compare(b.getSoBai(), a.getSoBai());
            if (a.getSoSubmit() != b.getSoSubmit())
                return Long.compare(a.getSoSubmit(), b.getSoSubmit());
            
            return a.getTen().compareTo(b.getTen());
        });
        
        for (sinhVien sv : list)
            System.out.println(sv);
    }
}

//2
//Nguyen Van Nam
//168 600
//Tran Thi Ngoc
//168 600