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
public class Rectangle {
    public int width, height;
    public String color;
    
    public Rectangle() {
        this.height = 1;
        this.width = 1;
        this.color = "";
    }
    
    public Rectangle(int width, int height, String color) {
        this.width = width;
        this.height = height;
        this.color = color;
    }
    
    public int getWidth() {
        return width;
    }
    
    public void setWidth(int width) {
        this.width = width;
    }
    
    public int getHeight() {
        return height;
    }
    
    public void setHeight(int height) {
        this.height = height;
    }
    
    public String getColor() {
        return color;
    }
    
    public void setColor(String color) {
        this.color = color;
    }
    
    public int findArea() {
        return width*height;
    }
    
    public int findPerimeter() {
        return (width + height)*2;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int w = sc.nextInt(), h = sc.nextInt();
        String color = sc.next();
        
        if (w <= 0 || h <= 0) {
            System.out.println("INVALID");
        }
        else {
            Rectangle r = new Rectangle(w, h, color);
            int perimeter = r.findPerimeter();
            int area = r.findArea();
            
            System.out.println(perimeter + " " + area + " " + normalize(r.getColor()));
        }
        
        sc.close();
    }
    
    public static String normalize(String s) {
        if (s == null || s.isEmpty())
            return s;
        return s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase();
    }
}
