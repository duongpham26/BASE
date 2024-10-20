package B4.easy.MaxProfitStock;

public class Solution1 {
	public int maxProfit(int[] prices) {
		int maxProfit = 0;
		for (int i = 0; i < prices.length - 1; i++) {
			for (int j = i + 1; j < prices.length; j++) {
				int curProfit = prices[j] - prices[i];
				if (curProfit > maxProfit) {
					maxProfit = curProfit;
				}
			}
		}
		return maxProfit;
	}

	public static void main(String[] args) {
		int[] a = { 6, 3, 9, 1, 2 };
		Solution1 s1 = new Solution1();
		System.out.println(s1.maxProfit(a));
	}
}
