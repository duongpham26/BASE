package lab6_2;

abstract class PTGT {
	protected String maXe, hangSanXuat, mau;
	protected int namSanXuat;
	protected double giaBan;

	public PTGT(String maXe, String hangSanXuat, int namSanXuat, double giaBan, String mau) {
		this.maXe = maXe;
		this.hangSanXuat = hangSanXuat;
		this.namSanXuat = namSanXuat;
		this.giaBan = giaBan;
		this.mau = mau;
	}

	public static boolean validTypeOfVehicle(String loaiXe) {
		return loaiXe.matches("OTo|XeMay|XeTai");
	}

	public static boolean validOfBrandName(String hangSanXuat) {
		return hangSanXuat.matches("[A-Za-z]+");
	}

	public static boolean validYearOfManufaceture(int namSanXuat) {
		if (namSanXuat < 2020)
			return false;
		return true;
	}

	public abstract void hienThi();
}