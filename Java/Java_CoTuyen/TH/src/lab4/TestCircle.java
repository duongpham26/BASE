package lab4;

public class TestCircle {
	public static void main(String[] args) {

		MyPoint p1 = new MyPoint(3, 4);
		MyCircle c1 = new MyCircle();

		c1.setCenter(p1);
		c1.setRadius(3);

		System.out.println("mycircle c1 : " + c1);
		System.out.println("Chu vi : " + c1.getCircumference());
		System.out.println("Dien tich : " + c1.getArea());

	}

}
