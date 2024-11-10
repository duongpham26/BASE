package lab3;

public class TestAccount {
	public static void main(String[] args) {
		Account account1 = new Account("001", "PhamDuong1", 500);
		Account account2 = new Account("002", "PhamDuong2", 200);

		System.out.println("accout1");
		System.out.println("id : " + account1.getId());
		System.out.println("name : " + account1.getName());
		System.out.println("balance : " + account1.getBalance());

		System.out.println("");
		System.out.println("account2 : " + account2.toString());

		System.out.println("");
		System.out.println("Transfer 600 from account1 to account2.");
		System.out.println("Balance account1 : " + account1.transferTo(account2, 600));
		System.out.println("Balance account2 : " + account2.getBalance());

		System.out.println("");
		System.out.println("Transfer 200 from account1 to account2.");
		System.out.println("Balance account1 : " + account1.transferTo(account2, 200));
		System.out.println("Balance account2 : " + account2.getBalance());
	}
}
