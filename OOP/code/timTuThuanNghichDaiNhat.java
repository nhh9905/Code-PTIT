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
public class timTuThuanNghichDaiNhat {
    public static boolean check(String line) {
        int l = 0, r = line.length() - 1;
        while (l < r) {
            if (line.charAt(l) != line.charAt(r))
                return false;
            ++l;
            --r;
        }
        return true;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int maxLen = 0;
        Map<String, Integer> m = new LinkedHashMap<>();
        
        while (sc.hasNext()) {
            String line = sc.next();
            
            if (check(line)) {
                int len = line.length();
                
                if (len > maxLen) {
                    m.clear();
                    maxLen = len;
                }
                
                if (len == maxLen)
                    m.put(line, m.getOrDefault(line, 0) + 1);
            }
        }
        
        for (Map.Entry<String, Integer> entry : m.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
}

//AAA BAABA HDHDH ACBSD SRGTDH DDDDS
//DUAHD AAA AD DA HDHDH AAA AAA AAA AAA
//DDDAS HDHDH HDH AAA AAA AAA AAA AAA
//AAA AAA AAA
//DHKFKH DHDHDD HDHDHD DDDHHH HHHDDD
//TDTD