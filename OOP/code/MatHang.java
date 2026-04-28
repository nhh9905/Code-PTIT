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
public class MatHang implements Comparable<MatHang> {
    private String maMatHang, tenMatHang, donVi;
    private int giaMua, giaBan;
    
    public MatHang() {}
    
    public MatHang(String ma, String ten, String donvi, int mua, int ban) {
        this.maMatHang = ma;
        this.tenMatHang = ten;
        this.donVi = donvi;
        this.giaMua = mua;
        this.giaBan = ban;
    }
    
    public void setMa(int cnt) {
        this.maMatHang = String.format("MH%03d", cnt);
    }
    
    public int getLoiNhuan() {
        return giaBan - giaMua;
    }
    
    @Override
    public int compareTo(MatHang other) {
        if (this.getLoiNhuan() != other.getLoiNhuan())
            return other.getLoiNhuan() - this.getLoiNhuan();
        return this.maMatHang.compareTo(other.maMatHang);
    }
    
    public void input(Scanner sc) {
        tenMatHang = sc.nextLine();
        donVi = sc.nextLine();
        giaMua = sc.nextInt();
        giaBan = sc.nextInt();
        sc.nextLine();
    }
    
    public void output() {
        System.out.printf("%s %s %s %d %d %d\n", maMatHang, tenMatHang, donVi, giaMua, giaBan, getLoiNhuan());
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<MatHang> list = new ArrayList<>();
        
        int t = sc.nextInt();
        sc.nextLine();
        for (int i = 1; i <= t; i++) {
            MatHang mh = new MatHang();
            mh.input(sc);
            mh.setMa(i);
            list.add(mh);
        }
        
        Collections.sort(list);
        for (MatHang mh:list)
            mh.output();
    }
}
