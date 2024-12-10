package lab6_2;

import java.util.Scanner;

public class Test {
	public static void main(String[] args) {
		QLPTGT qlpt = new QLPTGT();
		Scanner sc = new Scanner(System.in);

		qlpt.nhapPhuongTien();

		qlpt.nhapPhuongTien();

		qlpt.nhapPhuongTien();

		qlpt.tinhTongDoanhThu();
		qlpt.hienThiPhuongTien();
		qlpt.sapXepTheoDoanhThu();
		qlpt.hienThiPhuongTien();
		qlpt.timPhuongTienTheoMau("red");
		sc.close();
	}
}
