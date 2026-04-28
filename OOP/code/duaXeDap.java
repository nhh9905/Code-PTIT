/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
/**
 *
 * @author Asus
 */
public class duaXeDap {
    public static class cuaRo {
        private String ten, donVi;
        private LocalTime gio;

        public cuaRo() {
        }

        public cuaRo(String ten, String donVi, LocalTime gio) {
            this.ten = ten;
            this.donVi = donVi;
            this.gio = gio;
        }
        
        public long thoiGian() {
            LocalTime start = LocalTime.of(6, 0);
            Duration d = Duration.between(start, gio);
            return d.toMinutes();
        }
        
        public long tinhVanToc() {
            double time = thoiGian() / 60.0;
            return Math.round(120 / time);
        }
        
        public String rutGonChuoi(String x) {
            x = x.replaceAll("\\s+", " ").trim();
            String word[] = x.split(" ");
            for (int i = 0; i < word.length; i++)
                word[i] = word[i].substring(0, 1).toUpperCase();
            return String.join("", word);
        }
        
        @Override
        public String toString() {
            return rutGonChuoi(donVi) + rutGonChuoi(ten) + " " + ten + " " + donVi + " " + tinhVanToc() + " Km/h";
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<cuaRo> list = new ArrayList<>();
        DateTimeFormatter f = DateTimeFormatter.ofPattern("H:mm");
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String dv = sc.nextLine();
            LocalTime gio = LocalTime.parse(sc.nextLine(), f);
            
            list.add(new cuaRo(ten, dv, gio));
        }
        
        list.sort((a, b) -> {
            if (a.tinhVanToc() != b.tinhVanToc())
                return Long.compare(b.tinhVanToc(), a.tinhVanToc());
            return Long.compare(a.thoiGian(), b.thoiGian());
        });
        
        for (cuaRo cr : list)
            System.out.println(cr);
    }
}

//3
//Tran Vu Minh
//Ha Noi
//8:30
//Vu Ngoc Hoang
//Hoa Binh
//8:20
//Pham Dinh Tan
//An Giang
//8:45