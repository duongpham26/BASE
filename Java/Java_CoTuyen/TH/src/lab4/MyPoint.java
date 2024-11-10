package lab4;

public class MyPoint {

	private int x;
	private int y;

	public MyPoint() {
		this.x = 0;
		this.y = 0;
	}

	public MyPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int[] getXY() {
		return new int[] { x, y };
	}

	public void setXY(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public String toString() {
		return "MyPoint (x, y) = (" + x + ", " + y + ")";
	}

	public double distance(int x, int y) {
		return Math.sqrt(Math.pow(this.x - x, 2.0) + Math.pow(this.y - y, 2.0));
	}

	public double distance() {
		return Math.sqrt(Math.pow(this.x, 2.0) + Math.pow(this.y, 2.0));
	}

}
