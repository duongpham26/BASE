package P2_5.CastingAndGenerics;

public class Pair<A, B> {
	A first;
	B second;

	public Pair(A a, B b) { // constructor
		first = a;
		second = b;
	}

	public A getFirst() {
		return first;
	}

	public B getSecond() {
		return second;
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Pair<String, Double> pair1 = new Pair<>("Duong Pham", 20.0);
		System.out.println(pair1.getFirst());
		System.out.println(pair1.getSecond());

		// generics with array
		Pair<String, Double>[] pair2;

//		???
		pair2 = new Pair[25];
		pair2[0] = new Pair<>("ORCL", 32.5);

		System.out.println(pair2[0].getFirst());
	}

}
