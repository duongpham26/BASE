package lab2;

import java.util.ArrayList;
import java.util.Scanner;

import lab2.Bai1.Order;
import lab2.Bai1.Product;

public class Test_Bai1 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Bai1 bai1 = new Bai1();
		ArrayList<Order> orderList = new ArrayList<>();

		// Nhập thông tin các đơn hàng
		System.out.print("Nhập số lượng đơn hàng: ");
		int orderCount = scanner.nextInt();
		scanner.nextLine(); // Đọc bỏ dòng trống

		for (int i = 0; i < orderCount; i++) {
			System.out.println("Nhập thông tin cho đơn hàng thứ " + (i + 1) + ":");
			System.out.print("\tMã đơn hàng: ");
			String orderId = scanner.nextLine();
			System.out.print("\tTên khách hàng: ");
			String customerName = scanner.nextLine();

			Order order = bai1.new Order(orderId, customerName); // Truy cập lớp lồng nhau

			System.out.print("\tNhập số lượng sản phẩm trong đơn hàng: ");
			int productCount = scanner.nextInt();
			scanner.nextLine(); // Đọc bỏ dòng trống

			for (int j = 0; j < productCount; j++) {
				System.out.println("\tNhập thông tin sản phẩm thứ " + (j + 1) + ":");
				System.out.print("\t\tTên sản phẩm: ");
				String productName = scanner.nextLine();
				System.out.print("\t\tGiá sản phẩm: ");
				double price = scanner.nextDouble();
				scanner.nextLine(); // Đọc bỏ dòng trống

				Product product = bai1.new Product(productName, price); // Truy cập lớp lồng nhau
				order.addProduct(product);
			}
			orderList.add(order);
		}

		// Hiển thị thông tin các đơn hàng
		double totalRevenue = 0;
		Order highestOrder = null;
		System.out.println("\nThông tin các đơn hàng:");
		for (Order order : orderList) {
			order.displayOrderInfo();
			totalRevenue += order.totalValue;

			if (highestOrder == null || order.totalValue > highestOrder.totalValue) {
				highestOrder = order;
			}
		}

		// Tính tổng doanh thu
		System.out.println("\n-------------------------------");
		System.out.println("Tổng doanh thu từ các đơn hàng: " + totalRevenue);
		System.out.println("-------------------------------");

		// Tìm đơn hàng có giá trị cao nhất
		if (highestOrder != null) {
			System.out.println("\n-------------------------------");
			System.out.println("Đơn hàng có giá trị cao nhất:");
			highestOrder.displayOrderInfo();
			System.out.println("-------------------------------");
		}
		scanner.close();
	}
}
