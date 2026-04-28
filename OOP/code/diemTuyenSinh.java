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
public class diemTuyenSinh {
    public static void main(String[] args) throws Exception {
        File f = new File("THISINH.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<thiSinh> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            double diem = Double.parseDouble(sc.nextLine());
            String danToc = sc.nextLine();
            int khuVuc = Integer.parseInt(sc.nextLine());
            list.add(new thiSinh(ten, danToc, diem, khuVuc));
        }
        
        list.sort((a, b) -> Double.compare(b.tongDiem(), a.tongDiem()));
        for (thiSinh ts : list)
            System.out.println(ts);
    }
}

class thiSinh {
    private String ma, ten, danToc;
    private double diemThi;
    private int khuVuc;
    private static int cnt = 1;

    public thiSinh() {}

    public thiSinh(String ten, String danToc, double diemThi, int khuVuc) {
        this.ma = String.format("TS%02d", cnt++);
        this.ten = ten;
        this.danToc = danToc;
        this.diemThi = diemThi;
        this.khuVuc = khuVuc;
    }
    
    public double diemKhuVuc() {
        if (khuVuc == 1)
            return 1.5;
        if (khuVuc == 2)
            return 1.0;
        return 0;
    }
    
    public double diemDanToc() {
        if (danToc.equals("Kinh"))
            return 0;
        return 1.5;
    }
    
    public double tongDiem() {
        return diemThi + diemKhuVuc() + diemDanToc();
    }
    
    public String chuanHoaTen() {
        ten = ten.replaceAll("\\s+", " ").trim().toLowerCase();
        String word[] = ten.split(" ");
        
        for (int i = 0; i < word.length; i++)
            word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
        
        return String.join(" ", word);
    }
    
    public String status() {
        if (tongDiem() >= 20.5)
            return "Do";
        return "Truot";
    }

    @Override
    public String toString() {
        return String.format("%s %s %.1f %s", ma, chuanHoaTen(), tongDiem(), status());
    }
}