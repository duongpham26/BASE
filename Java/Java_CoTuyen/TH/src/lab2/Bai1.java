package lab2;

import java.util.ArrayList;

public class Bai1 {

	class Product {
		String productName;
		double price;

		public Product(String productName, double price) {
			this.productName = productName;
			this.price = price;
		}
	}

	class Order {
		String orderId;
		String customerName;
		ArrayList<Product> productList;
		double totalValue;

		public Order(String orderId, String customerName) {
			this.orderId = orderId;
			this.customerName = customerName;
			this.productList = new ArrayList<>();
			this.totalValue = 0;
		}

		public void addProduct(Product product) {
			productList.add(product);
			totalValue += product.price;
		}

		public void displayOrderInfo() {
			System.out.println("Mã đơn hàng: " + orderId);
			System.out.println("Tên khách hàng: " + customerName);
			System.out.println("Danh sách sản phẩm:");
			for (Product product : productList) {
				System.out.println("- " + product.productName + ": " + product.price);
			}
			System.out.println("Tổng giá trị đơn hàng: " + totalValue);
		}
	}
}
