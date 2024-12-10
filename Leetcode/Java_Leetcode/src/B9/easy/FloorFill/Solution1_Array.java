package B9.easy.FloorFill;

import java.util.Arrays;

public class Solution1_Array {
	public int[][] floodFill(int[][] image, int sr, int sc, int color) {

		System.out.println(image[0].length);
		for (int i = 0; i < image.length; i++) {
			if ((i < (sr - 1)) || (i > (sr + 1)))
				continue;
			for (int j = 0; j < image[0].length; j++) {
				if ((j < (sc - 1)) || (j > (sc + 1)))
					continue;
				if (image[i][j] != 0) {
					image[i][j] = color;
				}
			}
		}
		return image;
	}

	public static void main(String[] args) {

		Solution1_Array s1 = new Solution1_Array();

		int a[][] = s1.floodFill(new int[][] { { 1, 1, 0 }, { 1, 1, 1 } }, 0, 0, 2);
		System.out.println(Arrays.toString(a[0]));
	}
}
