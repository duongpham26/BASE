import numpy as np
import matplotlib.pyplot as plt

# Số đỉnh của ngôi sao và bán kính
num_points = 5
R = 1

# Tạo các góc tương ứng với các đỉnh
angles = np.linspace(0, 2 * np.pi, num_points + 1)

# Xoay ngôi sao một góc để thẳng đứng

# Tọa độ của các đỉnh ngôi sao
x = R * np.cos(angles + np.pi / 10)
y = R * np.sin(angles + np.pi / 10)

# Thứ tự nối các đỉnh để tạo thành ngôi sao
indices = np.array([0, 2, 4, 1, 3, 0])

# Vẽ hình ngôi sao
plt.plot(x[indices], y[indices], 'r-')
plt.fill(x[indices], y[indices], 'r')  # Tô màu đỏ
plt.axis('equal')
plt.axis('off')
plt.show()
