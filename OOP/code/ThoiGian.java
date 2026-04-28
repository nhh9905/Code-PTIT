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
public class ThoiGian implements Comparable<ThoiGian> {
    private int gio, phut, giay;
    
    public ThoiGian() {}
    
    public ThoiGian(int gio, int phut, int giay) {
        this.gio = gio;
        this.phut = phut;
        this.giay = giay;
    }
    
    public void input(Scanner sc) {
        gio = sc.nextInt();
        phut = sc.nextInt();
        giay = sc.nextInt();
    }
    
    public void output() {
        System.out.printf("%d %d %d\n", gio, phut, giay);
    }
    
    @Override
    public int compareTo(ThoiGian other) {
        if (this.gio != other.gio)
            return this.gio - other.gio;
        if (this.phut != other.phut)
            return this.phut - other.phut;
        return this.giay - other.giay;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        List<ThoiGian> list = new ArrayList<>();
        for (int i = 1; i <= t; i++) {
            ThoiGian tg = new ThoiGian();
            tg.input(sc);
            list.add(tg);
        }
        
        Collections.sort(list);
        
        for (ThoiGian tg:list)
            tg.output();
    }
}
