package lab3;

public class TestBall {
	public static void main(String[] args) {
		double width = 100; // Chiều rộng của hộp
		double height = 100; // Chiều cao của hộp

		// Tạo quả bóng với bán kính 5, vị trí ban đầu (50, 50), tốc độ di chuyển (3, 4)
		Ball ball = new Ball(50, 50, 5, 3, 4);

		// Chạy vòng lặp để mô phỏng chuyển động của quả bóng
		for (int i = 0; i < 50; i++) { // Số lần di chuyển bóng (có thể tăng để kiểm thử lâu hơn)
			ball.move();

			// Kiểm tra xem bóng có chạm vào tường trái hoặc phải không
			if (ball.getX() - ball.getRadius() <= 0 || ball.getX() + ball.getRadius() >= width) {
				ball.reflectHorizontal(); // Đảo ngược deltaX nếu chạm vào tường trái hoặc phải
			}

			// Kiểm tra xem bóng có chạm vào tường trên hoặc dưới không
			if (ball.getY() - ball.getRadius() <= 0 || ball.getY() + ball.getRadius() >= height) {
				ball.reflecVertical(); // Đảo ngược deltaY nếu chạm vào tường trên hoặc dưới
			}

			// In ra vị trí của bóng sau mỗi lần di chuyển
			System.out.println("Position after move " + (i + 1) + ": " + ball);
		}
	}
}