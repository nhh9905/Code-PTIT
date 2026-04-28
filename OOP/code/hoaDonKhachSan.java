/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
/**
 *
 * @author Asus
 */
public class hoaDonKhachSan {
    public static class khachHang {
        private String ma, ten, soPhong;
        private long tienDichVu;
        private LocalDate nhan, tra;
        private static int cnt = 1;

        public khachHang() {
        }

        public khachHang(String ten, String soPhong, long tienDichVu, LocalDate nhan, LocalDate tra) {
            this.ma = String.format("KH%02d", cnt++);
            this.ten = ten;
            this.soPhong = soPhong;
            this.tienDichVu = tienDichVu;
            this.nhan = nhan;
            this.tra = tra;
        }
        
        public long getTang() {
            return Long.parseLong(soPhong.substring(0, 1));
        }
        
        public long getGia() {
            if (getTang() == 1)
                return 25;
            if (getTang() == 2)
                return 34;
            if (getTang() == 3)
                return 50;
            return 80;
        }
        
        public long tinhSoNgay() {
            return ChronoUnit.DAYS.between(nhan, tra) + 1;
        }
        
        public long tinhTien() {
            return getGia() * tinhSoNgay() + tienDichVu;
        }

        @Override
        public String toString() {
            return ma + " " + ten + " " + soPhong.trim() + " " + tinhSoNgay() + " " + tinhTien();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<khachHang> list = new ArrayList<>();
        DateTimeFormatter f = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine().trim();
            String room = sc.nextLine().trim();
            LocalDate d1 = LocalDate.parse(sc.nextLine().trim(), f);
            LocalDate d2 = LocalDate.parse(sc.nextLine().trim(), f);
            long tien = Long.parseLong(sc.nextLine().trim());
            
            list.add(new khachHang(ten, room, tien, d1, d2));
        }
        
        list.sort((a, b) -> Long.compare(b.tinhTien(), a.tinhTien()));
        
        for (khachHang kh : list)
            System.out.println(kh);
    }
}

//3
//Huynh Van Thanh   
//103 
//05/06/2010   
//05/06/2010   
//15
//Le Duc Cong  
//106 
//08/03/2010   
//01/05/2010   
//220
//Tran Thi Bich Tuyen   
//207 
//10/04/2010   
//21/04/2010   
//96