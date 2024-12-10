package lab6_2;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class QLPTGT implements QLPTGTInterface {

	private List<PTGT> danhSachPT;

	public QLPTGT() {
		this.danhSachPT = new ArrayList<>();
	}

	@Override
	public void nhapPhuongTien() {
		Scanner sc = new Scanner(System.in);
		String loaiXe;
		while (true) {
			try {
				System.out.print("Nhập loại phương tiện (OTo/XeMay/XeTai): ");
				loaiXe = sc.nextLine();
				if (!PTGT.validTypeOfVehicle(loaiXe)) {
					throw new Exception("Invalid type of vehicle!");
				}
				break;
			} catch (Exception e) {
				System.out.println("Error: " + e.getMessage());
				System.out.println("Nhập lại!");
			}
		}

		System.out.print("Nhập mã xe: ");
		String maXe = sc.nextLine();

		String hangSanXuat;
		while (true) {
			try {
				System.out.print("Nhập hãng sản xuất: ");
				hangSanXuat = sc.nextLine();
				if (!PTGT.validOfBrandName(hangSanXuat)) {
					throw new Exception("Invalid brand name!");
				}
				break;
			} catch (Exception e) {
				System.out.println("Error: " + e.getMessage());
				System.out.println("Nhập lại!");
			}
		}

		int namSanXuat;
		while (true) {
			try {
				System.out.print("Nhập năm sản xuất: ");
				namSanXuat = sc.nextInt();
				if (!PTGT.validYearOfManufaceture(namSanXuat))
					throw new Exception("Invalid year of manufacture!");
				break;
			} catch (Exception e) {
				System.out.println("Error: " + e.getMessage());
				System.out.println("Nhập lại!");
				sc.nextLine(); // Để tránh lỗi khi nhập lại
			}
		}

		System.out.print("Nhập giá bán: ");
		double giaBan = sc.nextDouble();
		sc.nextLine(); // Xóa dòng thừa

		System.out.print("Nhập màu: ");
		String mau = sc.nextLine();

		if (loaiXe.equals("OTo")) {
			System.out.print("Nhập số chỗ ngồi: ");
			int soChoNgoi = sc.nextInt();
			sc.nextLine();
			System.out.print("Nhập kiểu động cơ: ");
			String kieuDongCo = sc.nextLine();
			danhSachPT.add(new Oto(maXe, hangSanXuat, namSanXuat, giaBan, mau, soChoNgoi, kieuDongCo));
		} else if (loaiXe.equals("XeMay")) {
			System.out.print("Nhập công suất: ");
			double congSuat = sc.nextDouble();
			sc.nextLine();
			danhSachPT.add(new XeMay(maXe, hangSanXuat, namSanXuat, giaBan, mau, congSuat));
		} else if (loaiXe.equals("XeTai")) {
			System.out.print("Nhập trọng tải: ");
			double trongTai = sc.nextDouble();
			sc.nextLine();
			danhSachPT.add(new XeTai(maXe, hangSanXuat, namSanXuat, giaBan, mau, trongTai));
		}
	}

	@Override
	public void hienThiPhuongTien() {
		if (danhSachPT.isEmpty()) {
			System.out.println("Danh sách phương tiện trống!");
		} else {
			for (PTGT pt : danhSachPT) {
				pt.hienThi();
			}
		}
	}

	@Override
	public void timPhuongTienTheoMau(String mau) {
		boolean found = false;
		for (PTGT pt : danhSachPT) {
			if (pt.mau.equalsIgnoreCase(mau)) {
				pt.hienThi();
				found = true;
			}
		}
		if (!found)
			System.out.println("Không tìm thấy phương tiện màu " + mau);
	}

	@Override
	public void tinhTongDoanhThu() {
		double tongDoanhThu = 0;
		for (PTGT pt : danhSachPT) {
			tongDoanhThu += pt.giaBan;
		}
		System.out.printf("Tổng doanh thu: %.2f\n", tongDoanhThu);
	}

	@Override
	public void sapXepTheoDoanhThu() {
		danhSachPT.sort(Comparator.comparingDouble(pt -> pt.giaBan));
		System.out.println("Danh sách sau khi sắp xếp theo doanh thu:");
		hienThiPhuongTien();
	}
}
