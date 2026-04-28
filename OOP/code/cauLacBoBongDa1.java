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
public class cauLacBoBongDa1 {
    public static class club {
        private String ma, ten;
        private long gia;

        public club() {
        }

        public club(String ma, String ten, long gia) {
            this.ma = ma;
            this.ten = ten;
            this.gia = gia;
        }

        public String getMa() {
            return ma;
        }

        public String getTen() {
            return ten;
        }

        public long getGia() {
            return gia;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<club> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            long gia = Long.parseLong(sc.nextLine());
            list.add(new club(ma, ten, gia));
        }
        
        int q = Integer.parseInt(sc.nextLine());
        while (q-- > 0) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            String ma = part[0];
            long num = Long.parseLong(part[1]);
            String clbId = ma.substring(1, 3);
            
            for (club clb : list) {
                if (clb.getMa().equals(clbId))
                    System.out.println(ma + " " + clb.getTen() + " " + clb.getGia() * num);
            }
        }
    }
}

//2
//AC
//AC Milan
//12
//MU
//Manchester United
//10
//2
//IAC1 80000
//EMU2 60000