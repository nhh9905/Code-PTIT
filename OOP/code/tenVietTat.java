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
public class tenVietTat {
    static class Person {
        String tenDayDu, tenVietTat;

        public Person() {
        }

        public Person(String tenDayDu, String tenVietTat) {
            this.tenDayDu = tenDayDu;
            this.tenVietTat = tenVietTat;
        }
    }
    
    public static String vietTatTen(String ten) {
        String word[] = ten.split(" ");
        for (int i = 0; i < word.length; i++)
            word[i] = word[i].substring(0, 1);
        return String.join(".", word);
    }
    
    public static String tachTenVietTat(String ten) {
        String word[] = ten.split("\\.");
        return String.join("", word);
    }
    
    public static void main(String[] args) throws Exception {
        File f = new File("DANHSACH.in");
        Scanner sc = new Scanner(f);
        int n = Integer.parseInt(sc.nextLine());
        List<Person> persons = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            String ten = sc.nextLine();
            String vt = vietTatTen(ten);
            String vtNoDot = tachTenVietTat(vt);
            persons.add(new Person(ten, vtNoDot));
        }
        
        int q = Integer.parseInt(sc.nextLine());
        while (q-- > 0) {
            String tenVietTat = sc.nextLine();
            String tmp = tachTenVietTat(tenVietTat);
            
            int cntSao = 0;
            for (char c : tmp.toCharArray()) {
                if (c == '*')
                    ++cntSao;
            }
            if (cntSao > 1)
                continue;
            
            List<String> list = new ArrayList<>();
            for (Person ps : persons) {
                String tmp1 = ps.tenVietTat;
                boolean check = true;
                
                if (tmp.length() != tmp1.length())
                    continue;
                
                for (int i = 0; i < tmp.length(); i++) {
                    if (tmp.charAt(i) != tmp1.charAt(i) && tmp.charAt(i) != '*' && tmp1.charAt(i) != '*') {
                        check = false;
                        break;
                    }
                }
                
                if (check == true)
                    list.add(ps.tenDayDu);
            }
            
            list.sort((a, b) -> {
                String wordA[] = a.split(" ");
                String wordB[] = b.split(" ");
                String tenA = wordA[wordA.length - 1];
                String tenB = wordB[wordB.length - 1];
                    
                if (!tenA.equals(tenB))
                    return tenA.compareTo(tenB);
                    
                return a.compareTo(b);
            });
            for (String str : list)
                System.out.println(str);
        }
    }
}
