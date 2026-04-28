/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.time.*;
/**
 *
 * @author Asus
 */
public class luongMuaTrungBinh {
    public static class Station {
        private String ma, ten;
        long luongMua = 0, thoiGian = 0;

        public Station() {
        }

        public Station(String ma, String ten) {
            this.ma = ma;
            this.ten = ten;
        }
        
        public void add(LocalTime start, LocalTime end, long mua) {
            luongMua += mua;
            thoiGian += Duration.between(start, end).toMinutes();
        }
        
        public double tinhTrungBinh() {
            return luongMua * 60.0 / thoiGian;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        LinkedHashMap<String, Station> map = new LinkedHashMap<>();
        int id = 1;
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            LocalTime start = LocalTime.parse(sc.nextLine());
            LocalTime end = LocalTime.parse(sc.nextLine());
            long mua = Long.parseLong(sc.nextLine());
            
            if (!map.containsKey(ten))
                map.put(ten, new Station(String.format("T%02d", id++), ten));
            
            map.get(ten).add(start, end, mua);
        }
        
        for (Station st : map.values())
            System.out.printf("%s %s %.2f\n", st.ma, st.ten, st.tinhTrungBinh());
    }
}

//10
//Dong Anh
//07:30
//08:00
//60
//Cau Giay
//07:45
//08:12
//50
//Soc Son
//08:00
//09:15
//78
//Dong Anh
//18:50
//20:00
//88
//Cau Giay
//19:01
//20:00
//77
//Soc Son
//19:06
//20:21
//66
//Dong Anh
//21:00
//21:40
//49
//Cau Giay
//21:50
//22:20
//68
//Dong Anh
//22:15
//23:45
//30
//Cau Giay
//22:50
//23:45
//35