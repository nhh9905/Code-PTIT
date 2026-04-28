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
public class xepHangVanDongVien2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        DateTimeFormatter f = DateTimeFormatter.ofPattern("HH:mm:ss");
        List<VDV> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String ns = sc.nextLine();
            LocalTime t1 = LocalTime.parse(sc.nextLine(), f);
            LocalTime t2 = LocalTime.parse(sc.nextLine(), f);
            list.add(new VDV(ten, ns, t1, t2));
        }
        
        list.sort((a, b) -> Long.compare(a.tinhThoiGian(), b.tinhThoiGian()));
        
        list.get(0).setRank(1);
        for (int i = 1; i < n; i++) {
            if (list.get(i).tinhThoiGian() == list.get(i - 1).tinhThoiGian())
                list.get(i).setRank(list.get(i - 1).getRank());
            else
                list.get(i).setRank(i + 1);
        }
        
        for (VDV vdv : list)
            System.out.println(vdv);
    }
}

class VDV {
    private String ma, ten, ngaySinh;
    private LocalTime xuatPhat, denDich;
    private int rank;
    private static int cnt = 1;

    public VDV() {
    }

    public VDV(String ten, String ngaySinh, LocalTime xuatPhat, LocalTime denDich) {
        this.ma = String.format("VDV%02d", cnt++);
        this.ten = ten;
        this.ngaySinh = ngaySinh;
        this.xuatPhat = xuatPhat;
        this.denDich = denDich;
    }

    public int getRank() {
        return rank;
    }

    public void setRank(int rank) {
        this.rank = rank;
    }
    
    public long getNam() {
        String part[] = ngaySinh.split("/");
        return Long.parseLong(part[2]);
    }
    
    public long tinhTuoi() {
        return 2021 - getNam();
    }
    
    public long tinhSoGiay() {
        return Duration.between(xuatPhat, denDich).getSeconds();
    }
    
    public long tinhUuTien() {
        long tuoi = tinhTuoi();
        if (tuoi < 18)
            return 0;
        if (tuoi >= 18 && tuoi < 25)
            return 1;
        if (tuoi >= 25 && tuoi < 32)
            return 2;
        return 3;
    }
    
    public long tinhThoiGian() {
        return tinhSoGiay() - tinhUuTien();
    }
    
    public String getTime(long time) {
        long gio = time / 3600;
        time %= 3600;
        long phut = time / 60;
        time %= 60;
        long giay = time;
        return String.format("%02d:%02d:%02d", gio, phut, giay);
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + getTime(tinhSoGiay()) + " " + getTime(tinhUuTien()) + " " + 
                getTime(tinhThoiGian()) + " " + rank;
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