package lab5;

public class Product {

	private int NumberOfProduct;
	private double Price;
	private int Interest;

	public Product(int numberOfProduct, double price, int interest) {
		this.NumberOfProduct = numberOfProduct;
		this.Price = price;
		this.Interest = interest;
	}

	public int getNumberOfProduct() {
		return this.NumberOfProduct;
	}

	public void setNumberOfProduct(int numberOfProduct) {
		this.NumberOfProduct = numberOfProduct;
	}

	public double getPrice() {
		return this.Price;
	}

	public void setPrice(double price) {
		this.Price = price;
	}

	public int getInterest() {
		return this.Interest;
	}

	public void setInterest(int interest) {
		this.Interest = interest;
	}

	public static boolean validNumberOfProduct(int number) {
		if (number >= 0) {
			return true;
		}
		System.out.println("Invalid Number of Product");
		return false;
	}

}
