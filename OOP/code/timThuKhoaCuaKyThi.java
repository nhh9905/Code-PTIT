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
public class timThuKhoaCuaKyThi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<thiSinh> list = new ArrayList<>();
        double maxx = 0;
        
        for (int i = 0; i < n; i++) {
            thiSinh ts = new thiSinh();
            ts.input(sc);
            list.add(ts);
            maxx = Math.max(maxx, ts.tinhDiem());
        }
        
        list.sort((a, b) -> Double.compare(b.tinhDiem(), a.tinhDiem()));
        
        for (thiSinh ts : list) {
            if (ts.tinhDiem() == maxx)
                System.out.println(ts);
        }
    }
}

class thiSinh {
    private static int cnt = 1;
    private int ma;
    private String ten, ngaySinh;
    private double d1, d2, d3;

    public thiSinh() {
    }

    public thiSinh(String ten, String ngaySinh, double d1, double d2, double d3) {
        this.ten = ten;
        this.ngaySinh = ngaySinh;
        this.d1 = d1;
        this.d2 = d2;
        this.d3 = d3;
    }
    
    public void input(Scanner sc) {
        ma = cnt++;
        ten = sc.nextLine();
        ngaySinh = sc.nextLine();
        d1 = Double.parseDouble(sc.nextLine());
        d2 = Double.parseDouble(sc.nextLine());
        d3 = Double.parseDouble(sc.nextLine());
    }
    
    public double tinhDiem() {
        return d1 + d2 + d3;
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + ngaySinh + " " + String.format("%.1f", tinhDiem());
    }
}

//3
//Nguyen Van A
//12/12/1994
//3.5
//7.0
//5.5
//Nguyen Van B
//1/9/1994
//7.5
//9.5
//9.5
//Nguyen Van C
//6/7/1994
//8.5
//9.5
//8.5