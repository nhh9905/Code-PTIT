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
public class j02017 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int arr[] = new int[n];
        
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        
        Stack<Integer> st = new Stack<>();
        
        for (int i = 0; i < n; i++) {
            if (st.empty())
                st.push(arr[i]);
            else {
                if ((arr[i] + st.peek()) % 2 == 0)
                    st.pop();
                else
                    st.push(arr[i]);
            }
        }
        
        System.out.println(st.size());
    }
}
