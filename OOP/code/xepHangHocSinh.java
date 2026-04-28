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
public class xepHangHocSinh {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            double gpa = sc.nextDouble();
            sc.nextLine();
            sinhVien sv = new sinhVien(ten, gpa);
            list.add(sv);
        }
        
        List<sinhVien> listNoSort = new ArrayList<>(list);
        list.sort((a, b) -> Double.compare(b.getGpa(), a.getGpa()));
        
        list.get(0).rank = 1;
        for (int i = 1; i < n; i++) {
            if (Math.abs(list.get(i).getGpa() - list.get(i - 1).getGpa()) < 1e-9)
                list.get(i).rank = list.get(i - 1).rank;
            else
                list.get(i).rank = i + 1;
        }
        
        for (sinhVien sv : listNoSort)
            System.out.println(sv);
    }
}

class sinhVien {
    private String ma, ten;
    private double gpa;
    public int rank;
    private static int cnt = 1;

    public sinhVien() {
    }

    public sinhVien(String ten, double gpa) {
        this.ma = String.format("HS%02d", cnt++);
        this.ten = ten;
        this.gpa = gpa;
    }

    public double getGpa() {
        return gpa;
    }

    public int getRank() {
        return rank;
    }
    
    public String xepLoai() {
        if (gpa < 5)
            return "Yeu";
        if (gpa >= 5 && gpa < 7)
            return "Trung Binh";
        if (gpa >= 7 && gpa < 9)
            return "Kha";
        return "Gioi";
    }
    
    @Override
    public String toString() {
        return String.format("%s %s %.1f %s %d", ma, ten, gpa, xepLoai(), rank);
    }
}

//3
//Tran Minh Hieu
//5.9
//Nguyen Bao Trung
//8.6
//Le Hong Ha
//9.2