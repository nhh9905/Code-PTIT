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
public class sapXepMatHang {
    public static void main(String[] args) throws Exception {
        File f = new File("MATHANG.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<matHang> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String nhom = sc.nextLine();
            double mua = Double.parseDouble(sc.nextLine());
            double ban = Double.parseDouble(sc.nextLine());
            list.add(new matHang(ten, nhom, mua, ban));
        }
        
        list.sort((a, b) -> Double.compare(b.loiNhuan(), a.loiNhuan()));
        for (matHang mh : list)
            System.out.println(mh);
    }
}

class matHang {
    private String ma, ten, nhom;
    private double giaMua, giaBan;
    private static int cnt = 1;

    public matHang() {}

    public matHang(String ten, String nhom, double giaMua, double giaBan) {
        this.ma = String.format("MH%02d", cnt++);
        this.ten = ten;
        this.nhom = nhom;
        this.giaMua = giaMua;
        this.giaBan = giaBan;
    }
    
    public double loiNhuan() {
        return giaBan - giaMua;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %.2f", ma, ten, nhom, loiNhuan());
    }
}