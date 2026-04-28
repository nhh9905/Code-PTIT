/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package code;

import java.util.*;

class NhanVien {
    public String id, ten, role, num, heSoLuong;
    public NhanVien (String id, String ten) {
        this.id = id;
        this.ten = ten;
        role = id.substring(0, 2);
        num = id.substring(4);
        heSoLuong = id.substring(2, 4);
        if (role.equals("GD") && Integer.parseInt(num) > 1) {
            role = "NV";
        }
        if ((role.equals("TP") || role.equals("PP")) && Integer.parseInt(num) > 3) {
            role = "NV";
        }
       
    }
    @Override
    public String toString() {
        return ten + " " + role + " " + num + " " + heSoLuong;
    }
}

public class test {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int n = Integer.parseInt(sc.nextLine());
        List<NhanVien> dsNV = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            String[] data = sc.nextLine().split("\\s+");
            String id = data[0];
            String ten = "";
            for (int j = 1; j < data.length; j++) {
                ten += data[j] + " ";
            }
            dsNV.add(new NhanVien(id, ten.trim()));
        }
        dsNV.sort((a, b) -> {
            if (b.heSoLuong.compareTo(a.heSoLuong) == 0) {
                int anum = Integer.parseInt(a.num);
                int bnum = Integer.parseInt(b.num);
                return anum - bnum;
            }
            int aHSL = Integer.parseInt(a.heSoLuong);
            int bHSL = Integer.parseInt(b.heSoLuong);
            return bHSL - aHSL;
        });
//        Map<String, List<NhanVien>> mp = new HashMap<>();
//        for (NhanVien nv : dsNV) {
//            mp.putIfAbsent(nv.ten, new ArrayList<>());
//            mp.get(nv.ten.toLowerCase()).add(nv);
//        }
        int q = Integer.parseInt(sc.nextLine());
        while (q-- > 0) {
            String s = sc.nextLine();
            s = s.toLowerCase();
            for (NhanVien nv : dsNV) {
                if (nv.ten.toLowerCase().contains(s)) {
                    System.out.println(nv);
                }
            }
            System.out.println();
        }
    }
}


//6
//GD08001 Nguyen Kim Loan
//TP05004 Hoang Thanh Tuan
//TP05001 Tran Binh Nguyen
//PP06002 Phan Trung Tuan
//PP06001 Tran Quoc Huy
//NV04003 Vo Van Lan
//2
//OA
//aN