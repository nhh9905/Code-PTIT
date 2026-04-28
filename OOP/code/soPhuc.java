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
public class soPhuc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<Pair<tmp, tmp>> list = new ArrayList<>();
       
        for (int i = 0; i < n; i++) {
            tmp A = new tmp(), B = new tmp();
            A.input(sc);
            B.input(sc);
            list.add(new Pair<>(A, B));
        }
        
        for (Pair<tmp, tmp> x : list)
            System.out.println(x);
    }
}

class tmp {
    private int a, b;

    public tmp() {
    }

    public tmp(int a, int b) {
        this.a = a;
        this.b = b;
    }
    
    public void input(Scanner sc) {
        a = sc.nextInt();
        b = sc.nextInt();
    }
    
    public String tinhC(tmp o) {
        // (4 + 6i) * (1 + 2i) = 4 + 8i + 6i - 12
        int thucA = this.a + o.a, aoA = this.b + o.b;
        int thucTong = thucA * this.a - aoA * this.b, aoTong = thucA * this.b + aoA * this.a;
        return String.format("%d + %di", thucTong, aoTong);
    }
    
    public String tinhD(tmp o) {
        // (a + bi)^2 = a^2 + 2*a*bi - b^2
        int thuc = this.a + o.a, ao = this.b + o.b;
        int thucTong = thuc * thuc - ao * ao, aoTong = 2 * thuc * ao;
        return String.format("%d + %di", thucTong, aoTong);
    }
}

class Pair<A extends tmp, B extends tmp> {
    A first;
    B second;

    public Pair(A first, B second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public String toString() {
        return String.format("%s, %s", first.tinhC(second), first.tinhD(second));
    }
}

//3
//1 2 3 4
//2 3 4 5
//1 -2 5 -6