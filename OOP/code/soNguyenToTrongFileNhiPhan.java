package code;

import java.util.*;
import java.io.*;

public class soNguyenToTrongFileNhiPhan {
    static boolean isPrime[] = new boolean[10005];
    
    public static void sang() {
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= Math.sqrt(10000); i++) {
            if (isPrime[i] == true) {
                for (int j = i * i; j <= 10000; j += i)
                    isPrime[j] = false;
            }
        }
    }
    
    public static void main(String[] args) throws Exception {
        sang();
        FileInputStream f = new FileInputStream("SONGUYEN.in");
        BufferedInputStream bis = new BufferedInputStream(f);
        ObjectInputStream ois = new ObjectInputStream(bis);
        List<Integer> list = (List<Integer>)ois.readObject();
        int cnt[] = new int[10005];
        Arrays.fill(cnt, 0);
        
        for (int x : list) {
            if (isPrime[x] == true)
                ++cnt[x];
        }
        
        for (int i = 2; i <= 10000; i++) {
            if (isPrime[i] == true)
                System.out.println(i + " " + cnt[i]);
        }
    }
}