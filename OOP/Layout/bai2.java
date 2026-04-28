/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Layout;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 *
 * @author Asus
 */
public class bai2 extends JFrame implements ActionListener {
    private JLabel lblText;
    private JButton btnDatFont;

    public bai2() {
        setTitle("Bài 2 - Tôi yêu PTIT");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 250);
        setLocationRelativeTo(null);
        setLayout(null);
        getContentPane().setBackground(new Color(220, 225, 235));

        lblText = new JLabel("Tôi yêu PTIT", JLabel.CENTER);
        lblText.setFont(new Font("Times New Roman", Font.BOLD, 24));
        lblText.setForeground(Color.BLUE);
        lblText.setBounds(60, 50, 280, 50);
        add(lblText);

        btnDatFont = new JButton("Đặt Font");
        btnDatFont.setBounds(140, 130, 120, 30);
        btnDatFont.addActionListener(this);
        add(btnDatFont);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // Mở hộp thoại và truyền JLabel sang
        new DialogDatFont(this, lblText);
    }

    public static void main(String[] args) {
        new bai2();
    }
}
