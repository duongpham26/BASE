package lab6_1;

public class MoveableCircle implements Moveable {

	private MoveablePoint center;
	private int radius;

	public MoveableCircle() {
	}

	public MoveableCircle(int x, int y, int xSpeed, int ySpeed, int radius) {
		this.center = new MoveablePoint(x, y, xSpeed, ySpeed);
		this.radius = radius;
	}

	public MoveablePoint getCenter() {
		return center;
	}

	public void setCenter(MoveablePoint center) {
		this.center = center;
	}

	public int getRadius() {
		return radius;
	}

	public void setRadius(int radius) {
		this.radius = radius;
	}

	@Override
	public String toString() {
		return "MoveableCircle [center=" + center + ", radius=" + radius + "]";
	}

	@Override
	public void moveUp() {
		this.center.moveUp();
	}

	@Override
	public void moveDown() {
		this.center.moveDown();
	}

	@Override
	public void moveLeft() {
		this.center.moveLeft();
	}

	@Override
	public void moveRight() {
		this.center.moveRight();
	}

}
