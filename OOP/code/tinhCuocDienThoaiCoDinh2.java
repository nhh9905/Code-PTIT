/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
/**
 *
 * @author Asus
 */
public class tinhCuocDienThoaiCoDinh2 {
    public static class thanhPho {
        private String ma, ten;
        private long gia;

        public thanhPho() {
        }

        public thanhPho(String ma, String ten, long gia) {
            this.ma = ma;
            this.ten = ten;
            this.gia = gia;
        }

        public String getMa() {
            return "0" + ma;
        }

        public String getTen() {
            return ten;
        }
        
        public long getGia() {
            return gia;
        }
    }
    
    public static class cuocGoi {
        private String thueBao, ten;
        private long soPhut, tien;

        public cuocGoi() {
        }

        public cuocGoi(String thueBao, String ten, long soPhut, long tien) {
            this.thueBao = thueBao;
            this.ten = ten;
            this.soPhut = soPhut;
            this.tien = tien;
        }

        public long getTien() {
            return tien;
        }
        
        @Override
        public String toString() {
            return thueBao + " " + ten + " " + soPhut + " " + tien;
        }
    }
    
    public static long tinhSoPhut(LocalTime start, LocalTime end) {
        return Duration.between(start, end).toMinutes();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<thanhPho> listCities = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            long gia = Long.parseLong(sc.nextLine());
            listCities.add(new thanhPho(ma, ten, gia));
        }
        
        int m = Integer.parseInt(sc.nextLine());
        DateTimeFormatter f = DateTimeFormatter.ofPattern("HH:mm");
        List<cuocGoi> listCuocGoi = new ArrayList<>();
        
        while (m-- > 0) {
            String str = sc.nextLine();
            String part[] = str.split(" ");
            String thuebao = part[0];
            LocalTime start = LocalTime.parse(part[1], f);
            LocalTime end = LocalTime.parse(part[2], f);
            
            for (thanhPho tp : listCities) {
                if (tp.getMa().equals(thuebao.substring(0, 3)) && thuebao.startsWith("0")) {
                    long time = tinhSoPhut(start, end);
                    long tien = tp.getGia() * time;
                    listCuocGoi.add(new cuocGoi(thuebao, tp.getTen(), time, tien));
                    break;
                }
                
                else if (!thuebao.startsWith("0")) {
                    long time = Math.round(tinhSoPhut(start, end) / 3.0);
                    long tien = 800 * time;
                    listCuocGoi.add(new cuocGoi(thuebao, "Noi mang", time, tien));
                    break;
                }
            }
        }
        
        listCuocGoi.sort((a, b) -> Long.compare(b.getTien(), a.getTien()));
        
        for (cuocGoi cg : listCuocGoi)
            System.out.println(cg);
    }
}

//2
//53
//Da Nang
//3000
//64
//Vung Tau
//1000
//3
//064-824531 11:20 11:22
//8293567 09:07 09:15
//053-823532 12:00 12:05