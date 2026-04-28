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
public class danhSachGiangVienTheoBoMon {
    public static class giangVien {
        private String ma, ten, mon;
        private static int cnt = 1;

        public giangVien() {
        }

        public giangVien(String ten, String mon) {
            this.ma = String.format("GV%02d", cnt++);
            this.ten = ten;
            this.mon = mon;
        }

        public String getMon() {
            return mon;
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + vietTat(mon);
        }
    }
    
    public static String vietTat(String ten) {
        String word[] = ten.split(" ");
        for (int i = 0; i < word.length; i++)
            word[i] = word[i].substring(0, 1).toUpperCase();
        return String.join("", word);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<giangVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String mon = sc.nextLine();
            list.add(new giangVien(ten, mon));
        }
        
        int q = Integer.parseInt(sc.nextLine());
        while (q-- > 0) {
            String str = sc.nextLine();
            System.out.println("DANH SACH GIANG VIEN BO MON " + vietTat(str) + ":");
            
            for (giangVien gv : list) {
                if (gv.getMon().equals(str))
                    System.out.println(gv);
            }
        }
    }
}
//3
//Nguyen Manh Son
//Cong nghe phan mem
//Vu Hoai Nam
//Khoa hoc may tinh
//Dang Minh Tuan
//An toan thong tin
//1
//Cong nghe phan mem