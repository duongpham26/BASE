package B4.easy.MaxProfitStock;

public class Solution2 {
	public int maxProfit(int[] prices) {
		int maxProfit = 0;
		int buyPrice = prices[0];
		for (int i = 1; i < prices.length; ++i) {
			if (prices[i] < buyPrice) {
				buyPrice = prices[i];
			}
			maxProfit = Math.max(maxProfit, prices[i] - buyPrice);
		}
		return maxProfit;
	}

	public static void main(String[] args) {
		int[] a = { 7, 1, 5, 3, 6, 4 };
		Solution1 s1 = new Solution1();
		System.out.println(s1.maxProfit(a));
	}
}
