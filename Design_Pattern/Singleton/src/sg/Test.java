package sg;

public class Test {
	public static void main(String[] args) {
		 Singleton uniqueInstance1 = Singleton.getInstance(9);
		 Singleton uniqueInstance2 = Singleton.getInstance(5);
		 System.out.println(uniqueInstance1.getN());
		 System.out.println(uniqueInstance2.getN());
	}
}
