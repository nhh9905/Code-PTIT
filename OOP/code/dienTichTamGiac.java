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
public class dienTichTamGiac {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Point p1 = new Point(), p2 = new Point(), p3 = new Point();
        
        for (int i = 0; i < n; i++) {
            p1.setX(sc.nextDouble());
            p1.setY(sc.nextDouble());
            
            p2.setX(sc.nextDouble());
            p2.setY(sc.nextDouble());
            
            p3.setX(sc.nextDouble());
            p3.setY(sc.nextDouble());
            
            double cross = (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - 
                    (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
            if (Math.abs(cross) < 1e-9) {
                System.out.println("INVALID");
                continue;
            }
            
            double canh1 = p1.distance(p2), canh2 = p1.distance(p3), canh3 = p2.distance(p3);
            
            if (canh1 + canh2 <= canh3 || canh1 + canh3 <= canh2 || canh2 + canh3 <= canh1) {
                System.out.println("INVALID");
                continue;
            }
            
            double nuaChuVi = (canh1 + canh2 + canh3) / 2.00;
            double dienTich = Math.sqrt(nuaChuVi * (nuaChuVi - canh1) * (nuaChuVi - canh2) * (nuaChuVi - canh3));
            
//            double dienTich = Math.sqrt((canh1 + canh2 + canh3) * (canh1 + canh2 - canh3) * 
//                    (canh2 + canh3 - canh1) * (canh3 + canh1 - canh2)) / 4.00;
            System.out.printf("%.2f\n", dienTich);
        }
    }
}

class Point {
    private double x, y;

    public Point() {
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }
    
    public double distance(Point other) {
        return Math.sqrt((this.x - other.x) * (this.x - other.x) + (this.y - other.y) * (this.y - other.y));
    }
}