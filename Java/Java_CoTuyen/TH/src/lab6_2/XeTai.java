package lab6_2;

public class XeTai extends PTGT {

	private double trongTai;

	public XeTai(String maXe, String hangSanXuat, int namSanXuat, double giaBan, String mau, double trongTai) {
		super(maXe, hangSanXuat, namSanXuat, giaBan, mau);
		this.trongTai = trongTai;
	}

	@Override
	public void hienThi() {
		System.out.printf("XeTai [Mã: %s, Hãng: %s, Năm: %d, Giá: %.2f, Màu: %s, Trọng tải: %.2f]\n", maXe, hangSanXuat,
				namSanXuat, giaBan, mau, trongTai);
	}
}
