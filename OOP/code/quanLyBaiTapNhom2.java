/*
 * Click nbfs:nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs:nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
/**
 *
 * @author Asus
 */
public class quanLyBaiTapNhom2 {
    static String readNonEmptyLine(Scanner sc) {
        while (true) {
            if (!sc.hasNextLine())
                return null;
            String str = sc.nextLine().trim();
            if (!str.isEmpty())
                return str;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = readNonEmptyLine(sc);
        String part[] = line.split("\\s+");
        int n = Integer.parseInt(part[0]), m = Integer.parseInt(part[1]);
        List<sinhVien> dsSV = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            sinhVien sv = new sinhVien();
            sv.input(sc);
            dsSV.add(sv);
        }
        
        List<String> deTai = new ArrayList<>();
        while (m-- > 0) {
            String str = readNonEmptyLine(sc);
            deTai.add(str);
        }
        
        Collections.sort(dsSV);
        for (sinhVien sv : dsSV) {
            System.out.print(sv);
            System.out.println(deTai.get(sv.getNhom() - 1));
        }
    }
}

class sinhVien implements Comparable<sinhVien> {
    private String ma, ten, sdt;
    private int nhom;
    
    public sinhVien() {}

    public sinhVien(String ma, String ten, String sdt, int nhom) {
        this.ma = ma;
        this.ten = ten;
        this.sdt = sdt;
        this.nhom = nhom;
    }
    
    public void input(Scanner sc) {
        ma = quanLyBaiTapNhom2.readNonEmptyLine(sc);
        ten = quanLyBaiTapNhom2.readNonEmptyLine(sc);
        sdt = quanLyBaiTapNhom2.readNonEmptyLine(sc);
        nhom = Integer.parseInt(quanLyBaiTapNhom2.readNonEmptyLine(sc));
    }

    public int getNhom() {
        return nhom;
    }
    
    @Override
    public String toString() {
        return ma + " " + ten + " " + sdt + " " + nhom + " ";
    }

    @Override
    public int compareTo(sinhVien o) {
        return this.ma.compareTo(o.ma);
    }
}