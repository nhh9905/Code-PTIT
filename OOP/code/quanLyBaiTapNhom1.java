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
public class quanLyBaiTapNhom1 {
    static String readNonEmptyLine(Scanner sc) {
        while (true) {
            String str = sc.nextLine().trim();
            if (!str.isEmpty())
                return str;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        List<sinhVien> list = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            sinhVien sv = new sinhVien();
            sv.input(sc);
            list.add(sv);
        }
        
        List<String> deTai = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            String str = readNonEmptyLine(sc);
            deTai.add(str);
        }
        
        int q = sc.nextInt();
        while (q-- > 0) {
            int num = sc.nextInt();
            
            System.out.printf("DANH SACH NHOM %d:\n", num);
            for (sinhVien x : list) {
                if (x.getNhom() == num)
                    System.out.println(x);
            }
            System.out.println("Bai tap dang ky: " + deTai.get(num - 1));
        }
    }
}

class sinhVien {
    private String ma, ten, SDT;
    private int nhom;
    
    static String readNonEmptyLine(Scanner sc) {
        while (true) {
            String str = sc.nextLine().trim();
            if (!str.isEmpty())
                return str;
        }
    }
    
    public sinhVien() {}
    
    public sinhVien(String ma, String ten, String sdt, int gr) {
        this.ma = ma;
        this.ten = ten;
        this.SDT = sdt;
        this.nhom = gr;
    }
    
    public void input(Scanner sc) {
        ma = readNonEmptyLine(sc);
        ten = readNonEmptyLine(sc);
        SDT = readNonEmptyLine(sc);
        nhom = sc.nextInt();
        sc.nextLine();
    }

    public int getNhom() {
        return nhom;
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + SDT;
    }
}