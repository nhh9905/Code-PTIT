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
public class bai1_case1 extends JFrame implements ActionListener {
    private JTextField txtSo1, txtSo2, txtTong;
    private JButton btnTinhTong, btnLamMoi;

    public bai1_case1() {
        // Tiêu đề cửa sổ
        setTitle("Bai 1");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 220);
        setLocationRelativeTo(null);
        setLayout(new GridLayout(5, 2, 5, 5));

        // Tiêu đề chính
        JLabel lblTieuDe = new JLabel("PHÉP TÍNH SỐ HỌC", JLabel.CENTER);
        lblTieuDe.setFont(new Font("Times New Roman", Font.BOLD, 22));
        lblTieuDe.setForeground(Color.BLUE);

        // Các label và textfield
        JLabel lblSo1 = new JLabel("Nhập số thứ nhất:");
        JLabel lblSo2 = new JLabel("Nhập số thứ hai:");
        JLabel lblTong = new JLabel("Tổng:");

        txtSo1 = new JTextField();
        txtSo2 = new JTextField();
        txtTong = new JTextField();
        txtTong.setEditable(false);

        btnLamMoi = new JButton("Làm mới");
        btnTinhTong = new JButton("Tính tổng");

        // Thêm sự kiện
        btnLamMoi.addActionListener(this);
        btnTinhTong.addActionListener(this);

        // Bố cục lưới
        setLayout(new GridLayout(5, 2, 5, 5));

        add(new JLabel());          // hàng trống
        add(lblTieuDe);
        add(lblSo1);
        add(txtSo1);
        add(lblSo2);
        add(txtSo2);
        add(lblTong);
        add(txtTong);
        add(btnLamMoi);
        add(btnTinhTong);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnTinhTong) {
            try {
                double so1 = Double.parseDouble(txtSo1.getText());
                double so2 = Double.parseDouble(txtSo2.getText());
                double tong = so1 + so2;
                txtTong.setText(String.valueOf(tong));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Chỉ nhập số", "Lỗi", JOptionPane.ERROR_MESSAGE);
            }
        } else if (e.getSource() == btnLamMoi) {
            txtSo1.setText("");
            txtSo2.setText("");
            txtTong.setText("");
            txtSo1.requestFocus();
        }
    }

    public static void main(String[] args) {
        new bai1_case1();
    }
}
