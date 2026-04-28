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
public class bai1_case3 extends JFrame implements ActionListener {
    private JTextField txtSo1, txtSo2, txtKetQua;
    private JRadioButton rdCong, rdTru, rdNhan, rdChia;
    private JButton btnLamMoi, btnTinh;

    public bai1_case3() {
        setTitle("Bai 1 - Trường hợp 3");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(420, 300);
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

        // Nhập số 1
        JLabel lblSo1 = new JLabel("Nhập số thứ 1:");
        lblSo1.setForeground(Color.BLUE);
        lblSo1.setBounds(60, 60, 100, 25);
        add(lblSo1);

        txtSo1 = new JTextField();
        txtSo1.setBounds(180, 60, 120, 25);
        add(txtSo1);

        // Nhập số 2
        JLabel lblSo2 = new JLabel("Nhập số thứ 2:");
        lblSo2.setForeground(Color.BLUE);
        lblSo2.setBounds(60, 95, 100, 25);
        add(lblSo2);

        txtSo2 = new JTextField();
        txtSo2.setBounds(180, 95, 120, 25);
        add(txtSo2);

        // Kết quả
        JLabel lblKetQua = new JLabel("Kết quả:");
        lblKetQua.setForeground(Color.BLUE);
        lblKetQua.setBounds(60, 130, 100, 25);
        add(lblKetQua);

        txtKetQua = new JTextField();
        txtKetQua.setEditable(false);
        txtKetQua.setBounds(180, 130, 120, 25);
        add(txtKetQua);

        // Nhóm radio button
        rdCong = new JRadioButton("Cộng");
        rdTru = new JRadioButton("Trừ");
        rdNhan = new JRadioButton("Nhân");
        rdChia = new JRadioButton("Chia");

        rdCong.setSelected(true);
        rdCong.setBackground(new Color(220, 225, 235));
        rdTru.setBackground(new Color(220, 225, 235));
        rdNhan.setBackground(new Color(220, 225, 235));
        rdChia.setBackground(new Color(220, 225, 235));

        ButtonGroup group = new ButtonGroup();
        group.add(rdCong);
        group.add(rdTru);
        group.add(rdNhan);
        group.add(rdChia);

        JPanel pnlRadio = new JPanel(new FlowLayout(FlowLayout.LEFT, 10, 0));
        pnlRadio.setBounds(150, 165, 250, 30);
        pnlRadio.setBackground(new Color(220, 225, 235));
        pnlRadio.add(rdCong);
        pnlRadio.add(rdTru);
        pnlRadio.add(rdNhan);
        pnlRadio.add(rdChia);
        add(pnlRadio);

        // Nút bấm
        btnLamMoi = new JButton("Làm mới");
        btnLamMoi.setBounds(100, 210, 100, 30);
        btnTinh = new JButton("Tính");
        btnTinh.setBounds(220, 210, 100, 30);
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
                double kq = 0;

                if (rdCong.isSelected()) {
                    kq = so1 + so2;
                } else if (rdTru.isSelected()) {
                    kq = so1 - so2;
                } else if (rdNhan.isSelected()) {
                    kq = so1 * so2;
                } else if (rdChia.isSelected()) {
                    if (so2 == 0) {
                        JOptionPane.showMessageDialog(this, "Không thể chia cho 0!", "Lỗi", JOptionPane.ERROR_MESSAGE);
                        return;
                    }
                    kq = so1 / so2;
                }

                txtKetQua.setText(String.valueOf(kq));
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Vui lòng nhập số hợp lệ!", "Lỗi", JOptionPane.ERROR_MESSAGE);
            }
        } else if (e.getSource() == btnLamMoi) {
            txtSo1.setText("");
            txtSo2.setText("");
            txtKetQua.setText("");
            rdCong.setSelected(true);
            txtSo1.requestFocus();
        }
    }

    public static void main(String[] args) {
        new bai1_case3();
    }
}
