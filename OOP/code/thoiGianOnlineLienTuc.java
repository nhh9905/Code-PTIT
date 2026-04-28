/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.time.*;
import java.util.*;
import java.io.*;
import java.time.format.DateTimeFormatter;
/**
 *
 * @author Asus
 */
public class thoiGianOnlineLienTuc {
    public static void main(String[] args) throws Exception {
        File f = new File("ONLINE.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<thoiGian> list = new ArrayList<>();
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String t1 = sc.nextLine();
            String t2 = sc.nextLine();
            LocalDateTime d1 = LocalDateTime.parse(t1, dtf);
            LocalDateTime d2 = LocalDateTime.parse(t2, dtf);
            list.add(new thoiGian(ten, d1, d2));
        }
        
        list.sort((a, b) -> {
            if (a.getPhut() != b.getPhut())
                return Long.compare(b.getPhut(), a.getPhut());
            return a.getTen().compareTo(b.getTen());
        });
        
        for (thoiGian tg : list)
            System.out.println(tg);
    }
}

class thoiGian {
    private String ten;
    private LocalDateTime tgBatDau, tgKetThuc;

    public thoiGian() {
    }

    public thoiGian(String ten, LocalDateTime tgBatDau, LocalDateTime tgKetThuc) {
        this.ten = ten;
        this.tgBatDau = tgBatDau;
        this.tgKetThuc = tgKetThuc;
    }

    public String getTen() {
        return ten;
    }
    
    public long getPhut() {
        long minutes = Duration.between(tgBatDau, tgKetThuc).toMinutes();
        return minutes;
    }

    @Override
    public String toString() {
        return ten + " " + getPhut();
    }
}