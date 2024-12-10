package lab6_2;

public class Oto extends PTGT {

	private int soChoNgoi;
	private String kieuDongCo;

	public Oto(String maXe, String hangSanXuat, int namSanXuat, double giaBan, String mau, int soChoNgoi,
			String kieuDongCo) {
		super(maXe, hangSanXuat, namSanXuat, giaBan, mau);
		this.soChoNgoi = soChoNgoi;
		this.kieuDongCo = kieuDongCo;
	}

	@Override
	public void hienThi() {
		System.out.printf("OTo [Mã: %s, Hãng: %s, Năm: %d, Giá: %.2f, Màu: %s, Chỗ ngồi: %d, Kiểu: %s]\n", maXe,
				hangSanXuat, namSanXuat, giaBan, mau, soChoNgoi, kieuDongCo);
	}

}
