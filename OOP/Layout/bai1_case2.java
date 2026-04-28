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
public class bai1_case2 extends JFrame implements ActionListener {
    private JTextField txtSo1, txtSo2, txtKetQua;
    private JComboBox<String> cbPhepTinh;
    private JButton btnLamMoi, btnTinh;

    public bai1_case2() {
        setTitle("Bai 1 - Trường hợp 2");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(420, 260);
        setLocationRelativeTo(null);
        setLayout(null);

        // Màu nền
        getContentPane().setBackground(new Color(220, 225, 235));

        // Tiêu đề
        JLabel lblTieuDe = new JLabel("PHÉP TÍNH SỐ HỌC", JLabel.CENTER);
        lblTieuDe.setFont(new Font("Times New Roman", Font.BOLD, 22));
        lblTieuDe.setForeground(Color.BLUE);
        lblTieuDe.setBounds(60, 10, 300, 30);
        add(lblTieuDe);

        // Các label và textfield
        JLabel lblSo1 = new JLabel("Nhập số thứ 1:");
        lblSo1.setForeground(Color.BLUE);
        lblSo1.setBounds(60, 60, 100, 25);
        add(lblSo1);

        txtSo1 = new JTextField();
        txtSo1.setBounds(180, 60, 120, 25);
        add(txtSo1);

        JLabel lblSo2 = new JLabel("Nhập số thứ 2:");
        lblSo2.setForeground(Color.BLUE);
        lblSo2.setBounds(60, 95, 100, 25);
        add(lblSo2);

        txtSo2 = new JTextField();
        txtSo2.setBounds(180, 95, 120, 25);
        add(txtSo2);

        JLabel lblKetQua = new JLabel("Kết quả:");
        lblKetQua.setForeground(Color.BLUE);
        lblKetQua.setBounds(60, 130, 100, 25);
        add(lblKetQua);

        txtKetQua = new JTextField();
        txtKetQua.setEditable(false);
        txtKetQua.setBounds(180, 130, 120, 25);
        add(txtKetQua);

        // ComboBox chọn phép tính
        String[] phepTinh = {"-Chọn-", "Cộng", "Trừ", "Nhân", "Chia"};
        cbPhepTinh = new JComboBox<>(phepTinh);
        cbPhepTinh.setBounds(310, 130, 80, 25);
        add(cbPhepTinh);

        // Nút
        btnLamMoi = new JButton("Làm mới");
        btnLamMoi.setBounds(100, 180, 100, 30);
        btnTinh = new JButton("Tính");
        btnTinh.setBounds(220, 180, 100, 30);

        add(btnLamMoi);
        add(btnTinh);

        btnLamMoi.addActionListener(this);
        btnTinh.addActionListener(this);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnTinh) {
            try {
                double so1 = Double.parseDouble(txtSo1.getText());
                double so2 = Double.parseDouble(txtSo2.getText());
                String phep = (String) cbPhepTinh.getSelectedItem();

                double kq = 0;
                switch (phep) {
                    case "Cộng": kq = so1 + so2; break;
                    case "Trừ": kq = so1 - so2; break;
                    case "Nhân": kq = so1 * so2; break;
                    case "Chia":
                        if (so2 == 0) {
                            JOptionPane.showMessageDialog(this, "Không thể chia cho 0!", "Lỗi", JOptionPane.ERROR_MESSAGE);
                            return;
                        }
                        kq = so1 / so2; break;
                    default:
                        JOptionPane.showMessageDialog(this, "Vui lòng chọn phép tính!", "Cảnh báo", JOptionPane.WARNING_MESSAGE);
                        return;
                }

                txtKetQua.setText(String.valueOf(kq));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Vui lòng nhập số hợp lệ!", "Lỗi", JOptionPane.ERROR_MESSAGE);
            }
        } else if (e.getSource() == btnLamMoi) {
            txtSo1.setText("");
            txtSo2.setText("");
            txtKetQua.setText("");
            cbPhepTinh.setSelectedIndex(0);
            txtSo1.requestFocus();
        }
    }

    public static void main(String[] args) {
        new bai1_case2();
    }
}
