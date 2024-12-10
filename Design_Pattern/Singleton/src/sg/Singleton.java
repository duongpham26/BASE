package sg;

public class Singleton {
	private static Singleton uniqueInstance;
	private int n;

	// other useful instance variables here
	private Singleton(int n) {
		this.n = n;
	}

	public int getN() {
		return n;
	}

	public void setN(int n) {
		this.n = n;
	}

	public static Singleton getInstance(int n) {
		if (uniqueInstance == null) {
			uniqueInstance = new Singleton(n);
		}
		return uniqueInstance;
	}
	// other useful methods here
}
