/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;
import java.io.*;
import java.util.*;
/**
 *
 * @author Asus
 */
public class soThuanNghichTrongFile {
    public static boolean thuanNghich(int x) {
        String tmp = String.valueOf(x);
        int l = 0, r = tmp.length() - 1;
        while (l < r) {
            if (tmp.charAt(l) != tmp.charAt(r))
                return false;
            ++l; --r;
        }
        return true;
    }
    
    public static boolean check(int x) {
        int cnt = 0;
        int k = x;
        while (x > 0) {
            ++cnt;
            int tmp = x % 10;
            if (tmp % 2 == 0)
                return false;
            x /= 10;
        }
        return cnt % 2 == 1 && cnt > 1 && thuanNghich(k);
    }
    
    public static void main(String[] args) throws Exception {
        FileInputStream f = new FileInputStream("DATA1.in");
        BufferedInputStream bis = new BufferedInputStream(f);
        ObjectInputStream ois = new ObjectInputStream(bis);
        Map<Integer, Integer> mapA = new HashMap<>();
        
        try {
            ArrayList<Integer> tmp = (ArrayList<Integer>)ois.readObject();
            
            for (int x : tmp)
                mapA.put(x, mapA.getOrDefault(x, 0) + 1);
        } catch (EOFException e) {
            
        }
        
        f.close();
        ois.close();
        
        f = new FileInputStream("DATA2.in");
        bis = new BufferedInputStream(f);
        ois = new ObjectInputStream(bis);
        Map<Integer, Integer> mapB = new HashMap<>();
        
        try {
            ArrayList<Integer> tmp = (ArrayList<Integer>)ois.readObject();
            
            for (int x : tmp)
                mapB.put(x, mapB.getOrDefault(x, 0) + 1);
        } catch (EOFException e) {
            
        }
        
        f.close();
        ois.close();
        
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(mapA.entrySet());
        list.sort(Map.Entry.comparingByKey());
        int cnt = 0;
        for (Map.Entry<Integer, Integer> x : list) {
            int k = x.getKey();
            if (check(k) == true && mapB.containsKey(k)) {
                int total = mapA.get(k) + mapB.get(k);
                System.out.println(k + " " + total);
                if (++cnt == 10)
                    break;
            }
        }
    }
}
