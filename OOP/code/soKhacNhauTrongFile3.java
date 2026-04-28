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
public class soKhacNhauTrongFile3 {
    public static void main(String[] args) throws Exception {
        FileInputStream f = new FileInputStream("DATA.in");
        ObjectInputStream ois = new ObjectInputStream(f);
        int cnt[] = new int[1000];
        
        try {
            ArrayList<Integer> tmp = (ArrayList<Integer>)ois.readObject();
            for (int x : tmp) {
                ++cnt[x];
            }
        } catch (EOFException e) {
            
        }

        for (int i = 0; i < 1000; i++) {
            if (cnt[i] != 0)
                System.out.printf("%d %d\n", i, cnt[i]);
        }
    }
}
