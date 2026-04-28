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
public class capSoNguyenToTrongFile2 {
    static boolean check[] = new boolean[1000005];
    public static void sang() {
        check[0] = check[1] = true;
        for (int i = 2; i <= 1000; i++) {
            if (!check[i]) {
                for (int j = i * i; j <= 1000000; j += i) {
                    check[j] = true;
                }
            }
        }
    }
    
    public static void main(String[] args) throws Exception {
        FileInputStream f = new FileInputStream("DATA1.in");
        ObjectInputStream ois = new ObjectInputStream(f);
        HashSet<Integer> setA = new HashSet<>();
        try {
            ArrayList<Integer> tmp = (ArrayList<Integer>)ois.readObject();
            for (int x : tmp)
                setA.add(x);
        } catch (EOFException e) {
            
        }
        f.close();
        ois.close();
        
        f = new FileInputStream("DATA2.in");
        ois = new ObjectInputStream(f);
        HashSet<Integer> setB = new HashSet<>();
        try {
            ArrayList<Integer> tmp = (ArrayList<Integer>)ois.readObject();
            for (int x : tmp)
                setB.add(x);
        } catch (EOFException e) {
            
        }
        
        sang();
        List<Integer> list = new ArrayList<>(setA);
        Collections.sort(list);
        for (int x : list) {
            int y = 1000000 - x;
            if (!check[x] && !check[y] && x < y && setA.contains(y) && !setB.contains(x) && !setB.contains(y))
                System.out.println(x + " " + y);
        }
    }
}
