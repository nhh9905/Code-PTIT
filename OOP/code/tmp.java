package code;

import java.io.*;
import java.util.*;

public class tmp {
    public static void main(String[] args) throws Exception {
        ArrayList<String> list = new ArrayList<>();

        list.add("Lap trinh Java co ban");
        list.add("File nhi phan luu tru doi tuong");
        list.add("Xu ly van ban voi ArrayList String");

        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("NHIPHAN.in"));
        oos.writeObject(list);
        oos.close();

        System.out.println("Đã tạo file NHIPHAN.in thành công!");
    }
}
