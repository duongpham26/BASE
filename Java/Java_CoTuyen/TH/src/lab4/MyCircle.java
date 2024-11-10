package lab4;

public class MyCircle {

	private MyPoint center;

	private int radius;

	public MyCircle() {
		this.center = new MyPoint();
		this.radius = 1;
	}

	public MyCircle(int x, int y, int radius) {
		this.center = new MyPoint(x, y);
		this.radius = radius;
	}

	public MyCircle(MyPoint center, int radius) {
		this.center = center;
		this.radius = radius;
	}

	public MyPoint getCenter() {
		return center;
	}

	public void setCenter(MyPoint center) {
		this.center = center;
	}

	public int getRadius() {
		return radius;
	}

	public void setRadius(int radius) {
		this.radius = radius;
	}

	public int getCenterX() {
		return center.getX();
	}

	public void setCenterX(int x) {
		center.setX(x);
	}

	public int getCenterY() {
		return center.getY();
	}

	public void setCenterY(int y) {
		center.setY(y);
	}

	public int[] getCenterXY() {
		return this.center.getXY();
	}

	public void setCenterXY(int x, int y) {
		this.center.setXY(x, y);
	}

	@Override
	public String toString() {
		return "MyCircle [radius=" + this.radius + ", center=(" + this.center.getX() + "," + this.center.getY() + ")]";
	}

	public double getArea() {
		return Math.PI * radius * radius;
	}

	public double getCircumference() {
		return 2 * Math.PI * radius;
	}

}
