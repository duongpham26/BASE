package lab5;

public class Sales extends Employee {

	private Product Product;

	public Sales() {
		super();
	}

	public Sales(String name, String staffID, int age, Product Product) {
		super(name, staffID, age);
		this.Product = Product;
	}

	public Product getProduct() {
		return this.Product;
	}

	public void setProduct(Product product) {
		this.Product = product;
	}

}
