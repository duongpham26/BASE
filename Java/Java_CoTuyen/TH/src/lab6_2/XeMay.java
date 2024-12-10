package lab6_2;

public class XeMay extends PTGT {

	private double congSuat;

	public XeMay(String maXe, String hangSanXuat, int namSanXuat, double giaBan, String mau, double congSuat) {
		super(maXe, hangSanXuat, namSanXuat, giaBan, mau);
		this.congSuat = congSuat;
	}

	public void hienThi() {
		System.out.printf("XeMay [Mã: %s, Hãng: %s, Năm: %d, Giá: %.2f, Màu: %s, Công suất: %.2f]\n", maXe, hangSanXuat,
				namSanXuat, giaBan, mau, congSuat);
	}
}
