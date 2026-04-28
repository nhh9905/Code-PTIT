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
public class bangDiemHocSinh {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<hocSinh> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String str = sc.nextLine();
            str = str.replaceAll("\\s+", " ").trim();
            String part[] = str.split(" ");
            double mon[] = new double[10];
            for (int j = 0; j < 10; j++) {
                mon[j] = Double.parseDouble(part[j]);
            }
            
            list.add(new hocSinh(ten, mon[0], mon[1], mon[2], mon[3], mon[4], mon[5], mon[6], mon[7], mon[8], mon[9]));
        }
        
        list.sort((a, b) -> Double.compare(b.tinhTrungBinh(), a.tinhTrungBinh()));
        
        for (hocSinh hs : list)
            System.out.println(hs);
    }
}

class hocSinh {
    private String ma, ten;
    private double toan, tv, nn, ly, hoa, sinh, su, dia, gdcd, cn;
    private static int cnt = 1;

    public hocSinh() {
    }

    public hocSinh(String ten, double toan, double tv, double nn, double ly, double hoa, double sinh, double su, double dia, double gdcd, double cn) {
        this.ma = String.format("HS%02d", cnt++);
        this.ten = ten;
        this.toan = toan;
        this.tv = tv;
        this.nn = nn;
        this.ly = ly;
        this.hoa = hoa;
        this.sinh = sinh;
        this.su = su;
        this.dia = dia;
        this.gdcd = gdcd;
        this.cn = cn;
    }
    
    public double tinhTrungBinh() {
        double diem = ((toan + tv) * 2 + nn + ly + hoa + sinh + su + dia + gdcd + cn) / 12.0;
        return Math.round(diem * 10.0) / 10.0;
    }
    
    public String xepLoai() {
        if (tinhTrungBinh() < 5)
            return "YEU";
        if (tinhTrungBinh() >= 5 && tinhTrungBinh() < 7)
            return "TB";
        if (tinhTrungBinh() >= 7 && tinhTrungBinh() < 8)
            return "KHA";
        if (tinhTrungBinh() >= 8 && tinhTrungBinh() < 9)
            return "GIOI";
        return "XUAT SAC";
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + String.format("%.1f", tinhTrungBinh()) + " " + xepLoai();
    }
}

//3
//Luu Thuy Nhi
//9.3  9.0  7.1  6.5  6.2  6.0  8.2  6.7  4.8  5.5
//Le Van Tam
//8.0  8.0  5.5  9.0  6.8  9.0  7.2  8.3  7.2  6.8
//Nguyen Thai Binh
//9.0  6.4  6.0  7.5  6.7  5.5  5.0  6.0  6.0  6.0