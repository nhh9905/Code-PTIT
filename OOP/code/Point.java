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
public class Point {
    private double x, y;
    
    public Point() {}
    
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
    
    public Point(Point p) {
        this.x = p.x;
        this.y = p.y;
    }
    
    public double getX() {
        return this.x;
    }
    
    public double getY() {
        return this.y;
    }
    
    public double distance(Point secondPoint) {
        double dx = this.x - secondPoint.x;
        double dy = this.y - secondPoint.y;
        return Math.sqrt(dx*dx + dy*dy);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        
        while (t-- > 0) {
            double x1 = sc.nextDouble(), y1 = sc.nextDouble();
            double x2 = sc.nextDouble(), y2 = sc.nextDouble();
            
            Point X = new Point(x1, y1), Y = new Point(x2, y2);
            
            System.out.printf("%.4f\n", X.distance(Y));
        }
    }
}