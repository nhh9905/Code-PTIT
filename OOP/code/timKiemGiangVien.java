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
public class timKiemGiangVien {
    public static class giangVien {
        private String ma, mon, ten;
        private static int cnt = 1;

        public giangVien() {
        }

        public giangVien(String mon, String ten) {
            this.ma = String.format("GV%02d", cnt++);
            this.mon = mon;
            this.ten = ten;
        }

        public String getTen() {
            return ten;
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
            list.add(new giangVien(mon, ten));
        }
        
        int q = Integer.parseInt(sc.nextLine());
        while (q-- > 0) {
            String str = sc.nextLine();
            System.out.println("DANH SACH GIANG VIEN THEO TU KHOA " + str + ":");
            
            for (giangVien gv : list) {
                if (gv.getTen().toLowerCase().contains(str.toLowerCase()))
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
//aN