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
public class kiemTraDayNgoacDung {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String str = sc.nextLine();
            Stack<Character> st = new Stack<>();
            boolean check = true;
            for (char c : str.toCharArray()) {
                if (check == false)
                    break;
                
                if (c == '(' || c == '[' || c == '{')
                    st.push(c);
                else {
                    if (st.isEmpty()) {
                        check = false;
                        break;
                    }
                    
                    if (c == ')') {
                        if (st.peek() == '(')
                            st.pop();
                        else {
                            check = false;
                            break;
                        }
                    }
                    
                    if (c == ']') {
                        if (st.peek() == '[')
                            st.pop();
                        else {
                            check = false;
                            break;
                        }
                    }
                    
                    if (c == '}') {
                        if (st.peek() == '{')
                            st.pop();
                        else {
                            check = false;
                            break;
                        }
                    }
                }
            }
            
            if (check == true)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}

//2
//[()]{}{[()()]()}
//[(])