/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Layout;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
/**
 *
 * @author Asus
 */
public class bai3 extends JFrame implements ActionListener {
    private JTextField txtFile;
    private JTextArea txtNoiDung;
    private JButton btnBrowse, btnHienThi;
    private JMenuItem miFont, miColor, miExit;

    public bai3() {
        setTitle("Bài 3 - Tạo Menu");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 400);
        setLocationRelativeTo(null);
        setLayout(null);
        getContentPane().setBackground(new Color(220, 225, 235));

        // ====== MENU BAR ======
        JMenuBar menuBar = new JMenuBar();

        JMenu menuFormat = new JMenu("Format");
        JMenu menuExit = new JMenu("Exit");

        miFont = new JMenuItem("Font");
        miColor = new JMenuItem("Color");
        miExit = new JMenuItem("Exit");

        menuFormat.add(miFont);
        menuFormat.add(miColor);
        menuExit.add(miExit);

        menuBar.add(menuFormat);
        menuBar.add(menuExit);

        setJMenuBar(menuBar);

        // ====== COMPONENTS ======
        JLabel lblFile = new JLabel("File:");
        lblFile.setBounds(40, 40, 50, 25);
        add(lblFile);

        txtFile = new JTextField();
        txtFile.setBounds(90, 40, 250, 25);
        add(txtFile);

        btnBrowse = new JButton("Browse");
        btnBrowse.setBounds(360, 40, 90, 25);
        add(btnBrowse);

        JLabel lblNoiDung = new JLabel("Nội dung:");
        lblNoiDung.setBounds(40, 80, 80, 25);
        add(lblNoiDung);

        txtNoiDung = new JTextArea();
        txtNoiDung.setFont(new Font("Times New Roman", Font.PLAIN, 14));
        JScrollPane scroll = new JScrollPane(txtNoiDung);
        scroll.setBounds(90, 110, 340, 180);
        add(scroll);

        btnHienThi = new JButton("Hiển thị nội dung");
        btnHienThi.setBounds(160, 310, 160, 30);
        add(btnHienThi);

        // ====== ACTIONS ======
        btnBrowse.addActionListener(this);
        btnHienThi.addActionListener(this);
        miFont.addActionListener(this);
        miColor.addActionListener(this);
        miExit.addActionListener(this);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Object src = e.getSource();

        // Nút Browse → chọn file text
        if (src == btnBrowse) {
            JFileChooser chooser = new JFileChooser();
            int result = chooser.showOpenDialog(this);
            if (result == JFileChooser.APPROVE_OPTION) {
                File file = chooser.getSelectedFile();
                txtFile.setText(file.getAbsolutePath());
            }
        }

        // Nút Hiển thị nội dung → đọc file
        else if (src == btnHienThi) {
            String filePath = txtFile.getText().trim();
            if (filePath.isEmpty()) {
                JOptionPane.showMessageDialog(this, "Vui lòng chọn file!");
                return;
            }

            try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
                txtNoiDung.setText("");
                String line;
                while ((line = br.readLine()) != null) {
                    txtNoiDung.append(line + "\n");
                }
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(this, "Lỗi đọc file!");
            }
        }

        // Menu → đổi font
        else if (src == miFont) {
            new FontDialog(this, txtNoiDung);
        }

        // Menu → đổi màu chữ
        else if (src == miColor) {
            Color c = JColorChooser.showDialog(this, "Chọn màu chữ", txtNoiDung.getForeground());
            if (c != null) txtNoiDung.setForeground(c);
        }

        // Menu Exit → thoát
        else if (src == miExit) {
            System.exit(0);
        }
    }

    // ====== CLASS NỘI BỘ: JDialog CHỌN FONT ======
    class FontDialog extends JDialog implements ActionListener {
        private JComboBox<String> cbFontName, cbFontSize;
        private JCheckBox chkBold, chkItalic;
        private JButton btnOK;
        private JTextArea txtTarget;

        public FontDialog(JFrame parent, JTextArea target) {
            super(parent, "Chọn font", true);
            this.txtTarget = target;

            setSize(300, 220);
            setLocationRelativeTo(parent);
            setLayout(null);
            getContentPane().setBackground(new Color(220, 225, 235));

            JLabel lblFont = new JLabel("Font name:");
            lblFont.setBounds(30, 20, 100, 25);
            add(lblFont);

            GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
            String[] fonts = ge.getAvailableFontFamilyNames();
            cbFontName = new JComboBox<>(fonts);
            cbFontName.setSelectedItem("Times New Roman");
            cbFontName.setBounds(130, 20, 130, 25);
            add(cbFontName);

            JLabel lblSize = new JLabel("Font size:");
            lblSize.setBounds(30, 60, 100, 25);
            add(lblSize);

            String[] sizes = {"10", "12", "14", "16", "18", "20", "24", "28", "32"};
            cbFontSize = new JComboBox<>(sizes);
            cbFontSize.setSelectedItem("14");
            cbFontSize.setBounds(130, 60, 80, 25);
            add(cbFontSize);

            chkBold = new JCheckBox("Bold");
            chkItalic = new JCheckBox("Italic");
            chkBold.setBackground(new Color(220, 225, 235));
            chkItalic.setBackground(new Color(220, 225, 235));
            chkBold.setBounds(60, 90, 80, 25);
            chkItalic.setBounds(150, 90, 80, 25);
            add(chkBold);
            add(chkItalic);

            btnOK = new JButton("Đặt Font");
            btnOK.setBounds(90, 130, 100, 30);
            btnOK.addActionListener(this);
            add(btnOK);

            setVisible(true);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String name = (String) cbFontName.getSelectedItem();
            int size = Integer.parseInt((String) cbFontSize.getSelectedItem());
            int style = Font.PLAIN;
            if (chkBold.isSelected()) style |= Font.BOLD;
            if (chkItalic.isSelected()) style |= Font.ITALIC;

            Font newFont = new Font(name, style, size);
            txtTarget.setFont(newFont);
            dispose();
        }
    }

    public static void main(String[] args) {
        new bai3();
    }
}
