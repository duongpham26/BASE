package lab1;

public class Bai3 {
	public static void main(String[] args) {
		int N = 10;
		int[] a = {17, 22, 19, 17, 13, 20, 14, 27, 29, 12};
		int[] b = {3, 5, 5, 5, 4, 2, 2, 1 ,2, 3};
		int tong = 0;
		for(int ngay = 0; ngay <= 5; ngay++) {
			for(int i = 0; i < N; i++) {
				int conlai = a[i] - b[i] * ngay;
				if(conlai < 0) {
					conlai = 0;
				}
				tong = tong + conlai;
			}			
			System.out.println("Ngay thu " + ngay +" : "  + tong);
			tong = 0;
		}
	}
}
