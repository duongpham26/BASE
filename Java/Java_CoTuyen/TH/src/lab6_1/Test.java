package lab6_1;

public class Test {

	public static void main(String[] args) {
		Moveable m1 = new MoveablePoint(5, 6, 10, 15); // upcast
		System.out.println("\nHien thi point m1");
		System.out.println(m1);
		m1.moveLeft();
		System.out.println("\nHien thi point m1 sau khi di chuyen sang trai");
		System.out.println(m1);
		Moveable m2 = new MoveableCircle(1, 2, 3, 4, 20); // upcast
		System.out.println("\nHien thi circle m2");
		System.out.println(m2);
		m2.moveRight();
		System.out.println("\nHien thi circle m2 sau khi di chuyen sang phai");
		System.out.println(m2);
	}
}
