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
public class sapXepDanhSachDoiTuongNhanVien {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<nhanVien> list = new ArrayList<>();
        
        for (int i = 1; i <= n; i++) {
            nhanVien nv = new nhanVien();
            nv.input(sc);
            list.add(nv);
        }
        
        list.sort((a, b) -> Integer.compare(a.getNam(), b.getNam()));
        
        for (nhanVien nv : list)
            System.out.println(nv);
    }
}

class nhanVien {
    private String ma, ten, gioiTinh, ngaySinh, diaChi, maSoThue, ngayKyHD;
    private static int cnt = 1;

    public nhanVien() {
    }

    public nhanVien(String ten, String gioiTinh, String ngaySinh, String diaChi, String maSoThue, String ngayKyHD) {
        this.ten = ten;
        this.gioiTinh = gioiTinh;
        this.ngaySinh = ngaySinh;
        this.diaChi = diaChi;
        this.maSoThue = maSoThue;
        this.ngayKyHD = ngayKyHD;
    }
    
    public void input(Scanner sc) {
        ma = String.format("%05d", cnt++);
        ten = sc.nextLine();
        gioiTinh = sc.nextLine();
        ngaySinh = sc.nextLine();
        diaChi = sc.nextLine();
        maSoThue = sc.nextLine();
        ngayKyHD = sc.nextLine();
    }
    
    public int getNam() {
        String part[] = ngaySinh.split("/");
        return Integer.parseInt(part[2]);
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + gioiTinh + " " + ngaySinh + " " + diaChi + " " + maSoThue + " " + ngayKyHD;
    }
}

//3
//Nguyen Van A
//Nam
//22/10/1982
//Mo Lao-Ha Dong-Ha Noi
//8333012345
//31/12/2013
//Ly Thi B
//Nu
//15/10/1988
//Mo Lao-Ha Dong-Ha Noi
//8333012346
//22/08/2011
//Hoang Thi C
//Nu
//04/02/1981
//Mo Lao-Ha Dong-Ha Noi
//8333012347
//22/08/2011
