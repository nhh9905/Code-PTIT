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
public class LoaiPhong implements Comparable<LoaiPhong>{
    private String loaiPhong, tenLoaiPhong;
    private int donGia;
    private double phiPhucVu;
    
    public LoaiPhong() {}
    
    public LoaiPhong(String loai, String ten, int gia, double phi) {
        this.loaiPhong = loai;
        this.tenLoaiPhong = ten;
        this.donGia = gia;
        this.phiPhucVu = phi;
    }
    
    public LoaiPhong(String line) {
        StringTokenizer st = new StringTokenizer(line);
        this.loaiPhong = st.nextToken();
        this.tenLoaiPhong = st.nextToken();
        this.donGia = Integer.parseInt(st.nextToken());
        this.phiPhucVu = Double.parseDouble(st.nextToken());
    }
    
    @Override
    public int compareTo(LoaiPhong other) {
        return this.tenLoaiPhong.compareTo(other.tenLoaiPhong);
    }
    
    @Override
    public String toString() {
        return loaiPhong + " " + tenLoaiPhong + " " + donGia + " " + phiPhucVu;
    }
    
    public static void main(String[] args) throws IOException {
        ArrayList<LoaiPhong> ds = new ArrayList<>();
        Scanner in = new Scanner(new File("PHONG.in"));
        int n = Integer.parseInt(in.nextLine());
        while(n-->0){
            ds.add(new LoaiPhong(in.nextLine()));
        }
        Collections.sort(ds);
        for(LoaiPhong tmp : ds){
            System.out.println(tmp);
        }
    }
}
