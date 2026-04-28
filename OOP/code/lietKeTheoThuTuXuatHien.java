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
public class lietKeTheoThuTuXuatHien {
    public static void main(String[] args) throws Exception {
        FileInputStream f = new FileInputStream("NHIPHAN.in");
        ObjectInputStream ois = new ObjectInputStream(f);
        ArrayList<String> list = (ArrayList<String>)ois.readObject();
        ois.close();
        
        Set<String> set1 = new HashSet<>();
        for (String str : list) {
            String s[] = str.toLowerCase().split("\\W+"); // tach ki tu ko phai chu
            
            for (String x : s) {
                if (!x.isEmpty())
                    set1.add(x);
            }
        }
        
        File f1 = new File("VANBAN.in");
        Scanner sc = new Scanner(f1);
        List<String> list1 = new ArrayList<>();
        Set<String> set2 = new HashSet<>();
        while (sc.hasNextLine()) {
            String str = sc.nextLine().replaceAll("\\W+", " ").trim().toLowerCase();
            String word[] = str.split(" ");
            
            for (String x : word) {
                if (!x.isEmpty() && !set2.contains(x)) {
                    list1.add(x);
                    set2.add(x);
                }
            }
        }
        
        for (String x : list1) {
            if (set1.contains(x))
                System.out.println(x);
        }
    }
}
