package Layout;

import java.awt.*;
import javax.swing.*;

public class tinhTong extends JFrame {

    public tinhTong() {
        initComponents();
    }

    private void initComponents() {
        setTitle("Phép tính số học - Trường hợp 1");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(420, 250);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout(15, 15));

        JLabel lblTitle = new JLabel("PHÉP TÍNH SỐ HỌC", JLabel.CENTER);
        lblTitle.setFont(new Font("Segoe UI", Font.BOLD, 18));
        lblTitle.setForeground(new Color(0, 51, 153));
        add(lblTitle, BorderLayout.NORTH);

        JPanel pnlInput = new JPanel(new GridLayout(2, 2, 10, 10));
        pnlInput.setBorder(BorderFactory.createEmptyBorder(10, 40, 10, 40));

        JLabel lblSo1 = new JLabel("Nhập số thứ nhất:");
        JTextField txtSo1 = new JTextField();
        JLabel lblSo2 = new JLabel("Nhập số thứ hai:");
        JTextField txtSo2 = new JTextField();

        lblSo1.setFont(new Font("Segoe UI", Font.PLAIN, 14));
        lblSo2.setFont(new Font("Segoe UI", Font.PLAIN, 14));

        pnlInput.add(lblSo1);
        pnlInput.add(txtSo1);
        pnlInput.add(lblSo2);
        pnlInput.add(txtSo2);

        add(pnlInput, BorderLayout.CENTER);

        JPanel pnlButtons = new JPanel(new GridLayout(1, 2, 20, 0));
        pnlButtons.setBorder(BorderFactory.createEmptyBorder(10, 80, 20, 80));
        pnlButtons.setBackground(new Color(240, 240, 240));

        JButton btnLamMoi = new JButton("Làm mới");
        JButton btnTinhTong = new JButton("Tính tổng");

        btnLamMoi.setFont(new Font("Segoe UI", Font.BOLD, 13));
        btnTinhTong.setFont(new Font("Segoe UI", Font.BOLD, 13));

        btnLamMoi.setBackground(new Color(230, 230, 230));
        btnTinhTong.setBackground(new Color(230, 230, 230));
//        btnTinhTong.setForeground(Color.WHITE);

        pnlButtons.add(btnLamMoi);
        pnlButtons.add(btnTinhTong);

        add(pnlButtons, BorderLayout.SOUTH);

        btnLamMoi.addActionListener(e -> {
            txtSo1.setText("");
            txtSo2.setText("");
            txtSo1.requestFocus();
        });

        btnTinhTong.addActionListener(e -> {
            try {
                double a = Double.parseDouble(txtSo1.getText());
                double b = Double.parseDouble(txtSo2.getText());
                JOptionPane.showMessageDialog(this, "Tổng = " + (a + b),
                        "Kết quả", JOptionPane.INFORMATION_MESSAGE);
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Vui lòng nhập số hợp lệ!",
                        "Lỗi", JOptionPane.ERROR_MESSAGE);
            }
        });
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new tinhTong().setVisible(true));
    }
}
