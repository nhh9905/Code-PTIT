/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
import java.util.*;

public class phanTuDauTienBenPhaiLonHon {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());

        while (t-- > 0) {
            int n = Integer.parseInt(sc.nextLine());
            int[] a = new int[n];
            int[] res = new int[n];
            Stack<Integer> st = new Stack<>();

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                res[i] = -1;
            }
            sc.nextLine();

            for (int i = 0; i < n; i++) {
                while (!st.isEmpty() && a[i] > a[st.peek()]) {
                    res[st.pop()] = a[i];
                }
                st.push(i);
            }

            for (int i = 0; i < n; i++) {
                System.out.print(res[i] + " ");
            }
            System.out.println();
        }
    }
}

//3
//4
//4 5 2 25
//3
//2 2 2
//4
//4 4 5 5