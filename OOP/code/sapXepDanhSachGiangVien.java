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
public class sapXepDanhSachGiangVien {
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

        public String getMa() {
            return ma;
        }
        
        public String lastName() {
            ten = ten.replaceAll("\\s+", " ").trim();
            String word[] = ten.split(" ");
            
            return word[word.length - 1];
        }
        
        public String maMon() {
            mon = mon.replaceAll("\\s+", " ").trim();
            String word[] = mon.split(" ");
            
            for (int i = 0; i < word.length; i++)
                word[i] = word[i].substring(0, 1).toUpperCase();
            
            return String.join("", word);
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + maMon();
        }
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
        
        list.sort((a, b) -> {
            if (!a.lastName().equals(b.lastName()))
                return a.lastName().compareTo(b.lastName());
            return a.getMa().compareTo(b.getMa());
        });
        
        for (giangVien gv : list)
            System.out.println(gv);
    }
}

//3
//Nguyen Manh Son
//Cong nghe phan mem
//Vu Hoai Nam
//Khoa hoc may tinh
//Dang Minh Tuan
//An toan thong tin