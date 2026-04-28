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
public class treNhatGiaNhat {
    public static class nguoi {
        private String ten;
        private LocalDate ns;

        public nguoi() {
        }

        public nguoi(String ten, LocalDate ns) {
            this.ten = ten;
            this.ns = ns;
        }

        public String getTen() {
            return ten;
        }
        
        public long tinhSoNgay() {
            LocalDate currentDate = LocalDate.now();
            return Duration.between(ns.atStartOfDay(), currentDate.atStartOfDay()).toDays();
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        DateTimeFormatter f = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        List<nguoi> list = new ArrayList<>();
        
        while (n-- > 0) {
            String str = sc.nextLine();
            String word[] = str.split(" ");
            String ten = word[0];
            LocalDate ns = LocalDate.parse(word[1], f);
            
            list.add(new nguoi(ten, ns));
        }   
        
        list.sort((a, b) -> Long.compare(a.tinhSoNgay(), b.tinhSoNgay()));
        
        System.out.println(list.get(0).getTen());
        System.out.println(list.get(list.size() - 1).getTen());
    }
}

//5
//Nam 01/10/1991
//An 30/12/1990
//Binh 15/08/1993
//Tam 18/09/1990
//Truong 20/09/1990