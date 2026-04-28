/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package danhsachsinhvien1;
import java.util.*;
import java.io.*;
import java.text.SimpleDateFormat;
import java.time.format.DateTimeFormatter;
import java.time.*;
/**
 *
 * @author Asus
 */
public class danhSachSinhVienTrongFileNhiPhan {
    public static class sinhVien implements Serializable {
        private String ma, ten, lop;
        private LocalDate ngaySinh;
        private double gpa;
        private static int cnt = 1;

        public sinhVien() {
        }

        public sinhVien(String ten, String lop, String ngaySinh, double gpa) {
            this.ma = String.format("B20DCCN%03d", cnt++);
            this.ten = ten;
            this.lop = lop;
            DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            this.ngaySinh = LocalDate.parse(ngaySinh, dtf);
            this.gpa = gpa;
        }
        
        @Override
        public String toString() {
            DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            return ma + " " + ten + " " + lop + " " + dtf.format(ngaySinh) + " " + 
                    String.format("%.2f", gpa);
        }
    }
    
    public static void main(String[] args) throws Exception {
        FileInputStream f = new FileInputStream("SV.in");
        ObjectInputStream ois = new ObjectInputStream(f);
        try {
            ArrayList<sinhVien> tmp = (ArrayList<sinhVien>)ois.readObject();
            for (sinhVien sv : tmp) {
                System.out.println(sv);
            }
        } catch (EOFException e) {
            
        }
    }
}
