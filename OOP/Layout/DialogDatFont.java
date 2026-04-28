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
public class DialogDatFont extends JDialog implements ActionListener {
    private JComboBox<String> cbFontName, cbFontSize;
    private JCheckBox chkBold, chkItalic, chkUnderline;
    private JButton btnDatFont;
    private JLabel lblPreview;
    private JLabel lblTarget;

    public DialogDatFont(JFrame parent, JLabel lblTarget) {
        super(parent, "Chọn font", true);
        this.lblTarget = lblTarget;

        setSize(350, 280);
        setLocationRelativeTo(parent);
        setLayout(null);
        getContentPane().setBackground(new Color(220, 225, 235));

        // Font name
        JLabel lblFontName = new JLabel("Font name:");
        lblFontName.setBounds(30, 20, 100, 25);
        add(lblFontName);

        GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
        String[] fonts = ge.getAvailableFontFamilyNames();
        cbFontName = new JComboBox<>(fonts);
        cbFontName.setSelectedItem("Times New Roman");
        cbFontName.setBounds(130, 20, 170, 25);
        add(cbFontName);

        // Font style
        JLabel lblStyle = new JLabel("Font style:");
        lblStyle.setBounds(30, 60, 100, 25);
        add(lblStyle);

        chkBold = new JCheckBox("Bold");
        chkItalic = new JCheckBox("Italic");
        chkUnderline = new JCheckBox("Underline");
        chkBold.setBackground(new Color(220, 225, 235));
        chkItalic.setBackground(new Color(220, 225, 235));
        chkUnderline.setBackground(new Color(220, 225, 235));

        chkBold.setBounds(130, 60, 70, 25);
        chkItalic.setBounds(200, 60, 70, 25);
        chkUnderline.setBounds(270, 60, 90, 25);
        add(chkBold);
        add(chkItalic);
        add(chkUnderline);

        // Font size
        JLabel lblSize = new JLabel("Font size:");
        lblSize.setBounds(30, 100, 100, 25);
        add(lblSize);

        String[] sizes = {"10", "12", "14", "16", "18", "20", "24", "28", "32"};
        cbFontSize = new JComboBox<>(sizes);
        cbFontSize.setSelectedItem("12");
        cbFontSize.setBounds(130, 100, 80, 25);
        add(cbFontSize);

        // Preview label
        lblPreview = new JLabel("Tôi yêu PTIT", JLabel.CENTER);
        lblPreview.setBounds(30, 140, 280, 40);
        lblPreview.setFont(new Font("Times New Roman", Font.PLAIN, 16));
        add(lblPreview);

        // Nút đặt font
        btnDatFont = new JButton("Đặt font");
        btnDatFont.setBounds(100, 200, 130, 30);
        btnDatFont.addActionListener(this);
        add(btnDatFont);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String fontName = (String) cbFontName.getSelectedItem();
        int fontSize = Integer.parseInt((String) cbFontSize.getSelectedItem());
        int style = Font.PLAIN;

        if (chkBold.isSelected()) style |= Font.BOLD;
        if (chkItalic.isSelected()) style |= Font.ITALIC;

        Font selectedFont = new Font(fontName, style, fontSize);

        // Gửi dữ liệu về JFrame
        lblTarget.setFont(selectedFont);

        // Nếu chọn underline thì dùng HTML (vì Font không có underline trực tiếp)
        if (chkUnderline.isSelected()) {
            lblTarget.setText("<html><u>Tôi yêu PTIT</u></html>");
        } else {
            lblTarget.setText("Tôi yêu PTIT");
        }

        dispose(); // Đóng JDialog
    }
}
