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
public class dayNgoacDungDaiNhat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; i++) {
            int maxLen = 0;
            String str = sc.nextLine();
            Stack<Integer> st = new Stack<>();
            st.push(-1);
            for (int j = 0; j < str.length(); j++) {
                if (str.charAt(j) == '(')
                    st.push(j);
                else {
                    st.pop();
                    if (st.isEmpty())
                        st.push(j);
                    else
                        maxLen = Math.max(maxLen, j - st.peek());
                }
            }
            System.out.println(maxLen);
        }
    }
}

//3
//((()
//)()())
//()(()))))