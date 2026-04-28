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
public class hopVaGiaoCuaHaiFileVanBan {
    public static class WordSet {
        private TreeSet<String> set;

        public WordSet(String filename) throws IOException {
            set = new TreeSet<>();
            Scanner sc = new Scanner(new File(filename));
            while (sc.hasNext()) {
                String word = sc.next().toLowerCase();
                set.add(word);
            }
            sc.close();
        }

        public String union(WordSet other) {
            TreeSet<String> res = new TreeSet<>(this.set);
            res.addAll(other.set);
            return String.join(" ", res);
        }

        public String intersection(WordSet other) {
            TreeSet<String> res = new TreeSet<>();
            for (String w : this.set) {
                if (other.set.contains(w)) {
                    res.add(w);
                }
            }
            return String.join(" ", res);
        }
    }
    
    public static void main(String[] args) throws IOException {
        WordSet s1 = new WordSet("DATA1.in");
        WordSet s2 = new WordSet("DATA2.in");
        System.out.println(s1.union(s2));
        System.out.println(s1.intersection(s2));
    }
}
