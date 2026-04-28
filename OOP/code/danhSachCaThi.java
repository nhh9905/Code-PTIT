/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
/**
 *
 * @author Asus
 */
public class danhSachCaThi {
    public static void main(String[] args) throws Exception {
        File f = new File("CATHI.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<caThi> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ngay = sc.nextLine();
            String gio = sc.nextLine();
            String maPhong = sc.nextLine();
            list.add(new caThi(ngay, gio, maPhong));
        }
        
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        DateTimeFormatter dtf1 = DateTimeFormatter.ofPattern("HH:mm");
        list.sort((a, b) -> {
            LocalDate d1 = LocalDate.parse(a.getNgayThi(), dtf);
            LocalDate d2 = LocalDate.parse(b.getNgayThi(), dtf);
            
            int cmpDate = d1.compareTo(d2);
            if (cmpDate != 0)
                return cmpDate;
            
            LocalTime t1 = LocalTime.parse(a.getGioThi(), dtf1);
            LocalTime t2 = LocalTime.parse(b.getGioThi(), dtf1);
            
            int cmpTime = t1.compareTo(t2);
            if (cmpTime != 0)
                return cmpTime;
            
            return a.getMa().compareTo(b.getMa());
        });
        
        for (caThi ct : list)
            System.out.println(ct);
    }
}

class caThi {
    private String ma, ngayThi, gioThi, phongThi;
    private static int cnt = 1;

    public caThi() {}

    public caThi(String ngayThi, String gioThi, String phongThi) {
        this.ma = String.format("C%03d", cnt++);
        this.ngayThi = ngayThi;
        this.gioThi = gioThi;
        this.phongThi = phongThi;
    }

    public String getMa() {
        return ma;
    }

    public String getNgayThi() {
        return ngayThi;
    }

    public String getGioThi() {
        return gioThi;
    }
    
    @Override
    public String toString() {
        return ma + " " + ngayThi + " " + gioThi + " " + phongThi;
    }
}