/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.*;
/**
 *
 * @author Asus
 */
public class tinhGio {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<gameThu> list = new ArrayList<>();
        DateTimeFormatter f = DateTimeFormatter.ofPattern("HH:mm");
        
        for (int i = 0; i < n; i++) {
            String ma = sc.nextLine();
            String ten = sc.nextLine();
            LocalTime vao = LocalTime.parse(sc.nextLine(), f);
            LocalTime ra = LocalTime.parse(sc.nextLine(), f);
            list.add(new gameThu(ma, ten, vao, ra));
        }
        
        list.sort((a, b) -> Long.compare(b.tinhThoiGian(), a.tinhThoiGian()));
        
        for (gameThu g : list)
            System.out.println(g);
    }
}

class gameThu {
    private String ma, ten;
    private LocalTime vao, ra;

    public gameThu() {
    }

    public gameThu(String ma, String ten, LocalTime vao, LocalTime ra) {
        this.ma = ma;
        this.ten = ten;
        this.vao = vao;
        this.ra = ra;
    }
    
    public long tinhThoiGian() {
        return Duration.between(vao, ra).toMinutes();
    }
    
    public long tinhGio() {
        return tinhThoiGian() / 60;
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + tinhGio() + " gio " + (tinhThoiGian() - tinhGio() * 60) + " phut";
    }
}

//3
//01T
//Nguyen Van An
//09:00
//10:30
//06T
//Hoang Van Nam
//15:30
//18:00
//02I
//Tran Hoa Binh
//09:05
//10:00