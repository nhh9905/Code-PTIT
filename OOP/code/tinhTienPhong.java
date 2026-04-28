/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
/**
 *
 * @author Asus
 */
public class tinhTienPhong implements Comparable<tinhTienPhong> {
    private String maKhachHang, tenKhachHang, soPhong, ngayNhanPhong, ngayTraPhong;
    private int tienDichVu;
    
    public tinhTienPhong() {}
    
    public tinhTienPhong(String ten, String phong, String ngayNhan, String ngayTra, int tien) {
        this.tenKhachHang = ten;
        this.soPhong = phong;
        this.ngayNhanPhong = ngayNhan;
        this.ngayTraPhong = ngayTra;
        this.tienDichVu = tien;
    }
    
    public long tinhSoNgay() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("d/M/yyyy");
        LocalDate date1 = LocalDate.parse(ngayNhanPhong, formatter);
        LocalDate date2 = LocalDate.parse(ngayTraPhong, formatter);
        long days = ChronoUnit.DAYS.between(date1, date2);
        return days + 1;
    }
    
    public void setMaKhachHang(int cnt) {
        this.maKhachHang = String.format("KH%02d", cnt);
    }
    
    public String normalize(String name) {
        name = name.replaceAll("\\s+", " ").trim().toLowerCase();
        
        String word[] = name.split(" ");
        for (int i = 0; i < word.length; i++)
            word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
        
        String tenMoi = String.join(" ", word);
        return tenMoi;
    }
    
    public long tinhTien() {
        int t = Integer.parseInt(soPhong.substring(0, 1));
        if (t == 1)
            return 25 * tinhSoNgay();
        if (t == 2)
            return 34 * tinhSoNgay();
        if (t == 3)
            return 50 * tinhSoNgay();
        
        return 80 * tinhSoNgay();
    }
    
    public long tongTien() {
        return tinhTien() + tienDichVu;
    }
    
    @Override
    public int compareTo(tinhTienPhong other) {
        return Long.compare(other.tongTien(), this.tongTien());
    }
    
    public void input(Scanner sc) {
        tenKhachHang = sc.nextLine().trim();
        soPhong = sc.nextLine().trim();
        ngayNhanPhong = sc.nextLine().trim();
        ngayTraPhong = sc.nextLine().trim();
        tienDichVu = Integer.parseInt(sc.nextLine().trim());
    }
    
    public void output() {
        System.out.println(maKhachHang + " " + normalize(tenKhachHang) + " " + soPhong + " " + tinhSoNgay() + " " + tongTien());
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("KHACHHANG.in");
        Scanner sc = new Scanner(f);
        
        int t = Integer.parseInt(sc.nextLine().trim());
        List<tinhTienPhong> list = new ArrayList<>();
        for (int i = 1; i <= t; i++) {
            tinhTienPhong kh = new tinhTienPhong();
            kh.input(sc);
            kh.setMaKhachHang(i);
            list.add(kh);
        }
        
        Collections.sort(list);
        for (tinhTienPhong kh : list)
            kh.output();
    }
}
