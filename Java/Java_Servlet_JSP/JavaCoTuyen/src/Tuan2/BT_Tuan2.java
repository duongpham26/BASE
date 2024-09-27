package Tuan2;

import java.io.Console;

public class BT_Tuan2 {
	public static void main(String[] args) {
		String userName = "duongpham26";
		String password = "123456";
		Console console = System.console();
		if (console == null) {
			System.out.println("No console available.");
			System.exit(1);
		}
		String name;
		char[] ps;
		String ps1;

		do {
			System.out.println("\n------DANG NHAP--------");
			name = console.readLine("Nhap username : ");
			ps = console.readPassword("Nhap password : ");
			ps1 = new String(ps);
			if (password == null) {
				System.out.println("Mat khau da bi xoa. Chuong trinh ket thuc");
				break;
			}
			if (!name.equals(userName) || !ps1.equals(password)) {
				password = null;
				System.out.println("Sai username hoac password. Vui long nhap lai!");
				continue;
			} else {
				System.out.println("Dang nhap thanh cong.");
				System.out.println("\nTai khoan : " + userName);
			}
		} while (!name.equals(userName) || !ps1.equals(password));
	}
}
