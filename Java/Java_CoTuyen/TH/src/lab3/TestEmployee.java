package lab3;

public class TestEmployee {
	public static void main(String[] args) {
		Employee employee1 = new Employee(1, "Pham", "Duong", 500);
		System.out.println("id : " + employee1.getId());
		System.out.println("firstName : " + employee1.getFirstName());
		System.out.println("lastName : " + employee1.getLastName());
		System.out.println("salary : " + employee1.getSalary());
		System.out.println("annualSalary : " + employee1.getAnnualSalary());
		employee1.setSalary(600);
		System.out.println("toStriSng : " + employee1.toString());
	}
}
