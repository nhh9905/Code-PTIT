/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.util.*;
import java.io.*;
/**
 *
 * @author Asus
 */
public class chuanHoaVaSapXep {
    public static String chuanHoa(String str) {
        str = str.replaceAll("\\s+", " ").trim().toLowerCase();
        String word[] = str.split(" ");
        
        for (int i = 0; i < word.length; i++)
            word[i] = word[i].substring(0, 1).toUpperCase() + word[i].substring(1);
        
        return String.join(" ", word);
    }
    
    public static String getTen(String str) {
        String word[] = str.split(" ");
        return word[word.length - 1];
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("DANHSACH.in");
        Scanner sc = new Scanner(f);
        List<String> list = new ArrayList<>();
        
        while (sc.hasNextLine()) {
            String ten = sc.nextLine();
            list.add(chuanHoa(ten));
        }
        
        list.sort((a, b) -> {
            if (!getTen(a).equals(getTen(b)))
                return getTen(a).compareTo(getTen(b));
            return a.compareTo(b);
        });
        
        for (String x : list)
            System.out.println(x);
    }
}
