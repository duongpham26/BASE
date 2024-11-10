package lab4;

public class TestMyPoint {

	public static void main(String[] args) {
		MyPoint p1 = new MyPoint(3, 4);
		MyPoint p2 = new MyPoint(4, 6);

		p2.setY(5);

		System.out.println(p2);
		System.out.println("Distance : " + p1.distance());
		System.out.println("Distance from (1, 1) : " + p2.distance(1, 1));
	}
}
