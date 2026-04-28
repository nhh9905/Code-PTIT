/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
/**
 *
 * @author Asus
 */
public class xepHangVanDongVien1 {
    public static class VDV {
        private String ma, ten, ngaySinh;
        private LocalTime start, end;
        private int rank;
        private static int cnt = 1;

        public VDV() {
        }

        public VDV(String ten, String ngaySinh, String start, String end) {
            DateTimeFormatter dtf = DateTimeFormatter.ofPattern("HH:mm:ss");
            this.ma = String.format("VDV%02d", cnt++);
            this.ten = ten;
            this.ngaySinh = ngaySinh;
            this.start = LocalTime.parse(start, dtf);
            this.end = LocalTime.parse(end, dtf);
        }

        public int getRank() {
            return rank;
        }

        public void setRank(int rank) {
            this.rank = rank;
        }
        
        public long tinhTuoi() {
            String part[] = ngaySinh.split("/");
            long namSinh = Long.parseLong(part[2]);
            return 2021 - namSinh;
        }
        
        public long tinhTgUuTien() {
            long tuoi = tinhTuoi();
            if (tuoi > 32)
                return 3;
            if (tuoi >= 25)
                return 2;
            if (tuoi >= 18)
                return 1;
            return 0;
        }
        
        public long tinhSoGiayVeDich() {
            return ChronoUnit.SECONDS.between(start, end);
        }
        
        public String dinhDangTg(long x) {
            long gio = x / 3600;
            long phut = (x - gio * 3600) / 60;
            long giay = x - gio * 3600 - phut * 60;
            return String.format("%02d:%02d:%02d", gio, phut, giay);
        }
        
        public long tinhSoGiayCuoi() {
            return tinhSoGiayVeDich() - tinhTgUuTien();
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + dinhDangTg(tinhSoGiayVeDich()) + " " + dinhDangTg(tinhTgUuTien()) + " " + 
                    dinhDangTg(tinhSoGiayCuoi()) + " " + rank;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<VDV> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String ngaySinh = sc.nextLine();
            String start = sc.nextLine();
            String end = sc.nextLine();
            list.add(new VDV(ten, ngaySinh, start, end));
        }
        
        List<VDV> list1 = new ArrayList<>(list);
        list.sort((a, b) -> Long.compare(a.tinhSoGiayCuoi(), b.tinhSoGiayCuoi()));
        
        list.get(0).setRank(1);
        for (int i = 1; i < n; i++) {
            if (list.get(i).tinhSoGiayCuoi() == list.get(i - 1).tinhSoGiayCuoi())
                list.get(i).setRank(list.get(i - 1).getRank());
            else
                list.get(i).setRank(i + 1);
        }
        
        for (VDV x : list1)
            System.out.println(x);
    }
}

//3
//Nguyen Van Thanh
//20/03/1990
//07:00:00
//07:10:01
//Nguyen Hoa Binh
//01/10/1993
//07:02:00
//07:11:20
//Le Thanh Van
//15/03/1998
//07:05:00
//07:15:30