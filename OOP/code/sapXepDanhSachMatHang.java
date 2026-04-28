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
public class sapXepDanhSachMatHang {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
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
    private int ma;
    private String ten, nhom;
    private double giaMua, giaBan;
    private static int cnt = 1;

    public matHang() {
    }

    public matHang(String ten, String nhom, double giaMua, double giaBan) {
        this.ma = cnt++;
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
        return ma + " " + ten + " " + nhom + " " + String.format("%.2f", loiNhuan());
    }
}

//3
//May tinh SONY VAIO
//Dien tu
//16400
//17699
//Tu lanh Side by Side
//Dien lanh
//18300
//25999
//Banh Chocopie
//Tieu dung
//27.5
//37