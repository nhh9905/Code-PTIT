/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Layout;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
/**
 *
 * @author Asus
 */
public class Main extends JFrame {
    private JTextField txtSo1, txtSo2;
    
    public Main() {
        initComponents();
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(()->(new Main()).setVisible(true));
    }
    
    private void initComponents() {
        setTitle("Bai 1");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());
        JPanel p1 = new JPanel();
        add(p1, BorderLayout.NORTH);
        JPanel p2 = new JPanel();
        add(p2, BorderLayout.SOUTH);
        
        ButtonGroup g = new ButtonGroup();
        setLayout(new GridLayout(2, 2));
        JLabel lblSo1 = new JLabel("Nhap so thu nhat: ");
        JLabel lblSo2 = new JLabel("Nhap so thu hai: ");
        txtSo1 = new JTextField();
        txtSo2 = new JTextField();
        add(lblSo1);
        add(lblSo2);
        add(txtSo1);
        add(txtSo2);
        JButton btnAdd = new JButton("Tinh tong");
        add(btnAdd);
        btnAdd.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                
            }
            
        });
//        JRadioButton r1 = new JRadioButton("Nu");
//        JRadioButton r2 = new JRadioButton("Nam");
//        add(r1);
//        add(r2);
    }
}
