package lab3;

public class Account {
	private String id;
	private String name;
	private int balance = 0;

	public Account(String id, String name) {
		this.name = name;
		this.id = id;
	}

	public Account(String id, String name, int balance) {
		this.id = id;
		this.name = name;
		this.balance = balance;
	}

	public String getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public int getBalance() {
		return balance;
	}

	public int credit(int amount) {
		this.balance += amount;
		return this.balance;
	}

	public int debit(int amount) {
		if (amount <= this.balance) {
			this.balance -= amount;
		} else {
			System.out.println("Amount exceeded balance");
		}
		return this.balance;
	}

	public int transferTo(Account another, int amount) {
		if (amount <= this.balance) {
			debit(amount);
			another.credit(amount);
		} else {
			System.out.println("Amount exceeded balance");
		}
		return this.balance;
	}

	public String toString() {
		return "Account[id=" + this.id + ",name=" + this.name + ",balance=" + this.balance + "]";
	}
}