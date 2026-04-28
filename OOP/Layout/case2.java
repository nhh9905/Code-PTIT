package Layout;

import java.awt.*;
import javax.swing.*;

public class case2 extends JFrame {

    public case2() {
        initComponents();
    }

    private void initComponents() {
        setTitle("Phép tính số học - Trường hợp 2");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(420, 250);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout(15, 15));

        // ==== Tiêu đề ====
        JLabel lblTitle = new JLabel("CHỌN PHÉP TOÁN", JLabel.CENTER);
        lblTitle.setFont(new Font("Segoe UI", Font.BOLD, 18));
        lblTitle.setForeground(new Color(0, 51, 153));
        add(lblTitle, BorderLayout.NORTH);

        // ==== Panel chính chứa RadioButton ====
        JPanel pnlMain = new JPanel(new GridBagLayout());
        pnlMain.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));
        pnlMain.setBackground(Color.WHITE);
        GridBagConstraints gbc = new GridBagConstraints();

        // Tạo 4 radio button
        JRadioButton rdCong = new JRadioButton("Cộng (+)");
        JRadioButton rdTru = new JRadioButton("Trừ (-)");
        JRadioButton rdNhan = new JRadioButton("Nhân (×)");
        JRadioButton rdChia = new JRadioButton("Chia (÷)");

        // Nhóm lại để chỉ chọn 1
        ButtonGroup group = new ButtonGroup();
        group.add(rdCong);
        group.add(rdTru);
        group.add(rdNhan);
        group.add(rdChia);

        // Tùy chỉnh giao diện
        Font font = new Font("Segoe UI", Font.PLAIN, 15);
        for (JRadioButton rd : new JRadioButton[]{rdCong, rdTru, rdNhan, rdChia}) {
            rd.setFont(font);
            rd.setBackground(Color.WHITE);
        }

        // ==== Bố trí radio buttons (GridBagLayout) ====
        gbc.insets = new Insets(8, 15, 8, 15); // khoảng cách
        gbc.gridy = 0;
        gbc.gridx = 0;
        pnlMain.add(rdCong, gbc);
        gbc.gridx = 1;
        pnlMain.add(rdTru, gbc);
        gbc.gridx = 2;
        pnlMain.add(rdNhan, gbc);
        gbc.gridx = 3;
        pnlMain.add(rdChia, gbc);

        add(pnlMain, BorderLayout.CENTER);

        // ==== Panel kết quả (South) ====
        JPanel pnlResult = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 10));
        pnlResult.setBackground(new Color(245, 245, 245));

        JLabel lblResult = new JLabel("Bạn chọn: ");
        JLabel lblChoice = new JLabel("Chưa chọn");
        lblChoice.setFont(new Font("Segoe UI", Font.BOLD, 14));
        lblChoice.setForeground(new Color(0, 102, 204));

        pnlResult.add(lblResult);
        pnlResult.add(lblChoice);
        add(pnlResult, BorderLayout.SOUTH);

        // ==== Sự kiện chọn phép toán ====
        rdCong.addActionListener(e -> lblChoice.setText("Cộng (+)"));
        rdTru.addActionListener(e -> lblChoice.setText("Trừ (-)"));
        rdNhan.addActionListener(e -> lblChoice.setText("Nhân (×)"));
        rdChia.addActionListener(e -> lblChoice.setText("Chia (÷)"));
    }

    public static void main(String[] args) {
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (Exception e) {
            e.printStackTrace();
        }
        SwingUtilities.invokeLater(() -> new case2().setVisible(true));
    }
}
