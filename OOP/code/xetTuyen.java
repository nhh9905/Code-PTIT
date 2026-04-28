/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
/**
 *
 * @author Asus
 */
public class xetTuyen {
    public static void main(String[] args) throws Exception {
        File f = new File("XETTUYEN.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<thiSinh> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String ns = sc.nextLine();
            double diemlt = Double.parseDouble(sc.nextLine());
            double diemth = Double.parseDouble(sc.nextLine());
            list.add(new thiSinh(ten, ns, diemlt, diemth));
        }
        
        for (thiSinh ts : list)
            System.out.println(ts);
    }
}

class thiSinh {
    private String ma, ten, ngaySinh;
    private double diemLyThuyet, diemThucHanh;
    private static int cnt = 1;

    public thiSinh() {}

    public thiSinh(String ten, String ngaySinh, double diemLyThuyet, double diemThucHanh) {
        this.ma = String.format("PH%02d", cnt++);
        this.ten = ten;
        this.ngaySinh = ngaySinh;
        this.diemLyThuyet = diemLyThuyet;
        this.diemThucHanh = diemThucHanh;
    }
    
    public String chuanHoaTen() {
        ten = ten.replaceAll("\\s+", " ").trim().toLowerCase();
        String word[] = ten.split(" ");
        for (int i = 0; i < word.length; i++)
            word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
        return String.join(" ", word);
    }
    
    public double diemThuong() {
        if (diemLyThuyet >= 8 && diemThucHanh >= 8)
            return 1;
        if (diemLyThuyet >= 7.5 && diemThucHanh >= 7.5)
            return 0.5;
        return 0;
    }
    
    public int diemXepLoai() {
        double avg = (diemLyThuyet + diemThucHanh)/2.0 + diemThuong();
        long round = Math.round(avg);
        if (round > 10)
            round = 10;
        return (int)round;
    }
    
    public String xepLoai() {
        if (diemXepLoai() < 5)
            return "Truot";
        if (diemXepLoai() == 5 || diemXepLoai() == 6)
            return "Trung binh";
        if (diemXepLoai() == 7)
            return "Kha";
        if (diemXepLoai() == 8)
            return "Gioi";
        return "Xuat sac";
    }
    
    public int tinhTuoi() {
        String part[] = ngaySinh.split("/");
        int namSinh = Integer.parseInt(part[2]);
//        int namHienTai = java.time.LocalDate.now().getYear();
        return 2021 - namSinh;
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %s", ma, chuanHoaTen(), tinhTuoi(), diemXepLoai(), xepLoai());
    }
}