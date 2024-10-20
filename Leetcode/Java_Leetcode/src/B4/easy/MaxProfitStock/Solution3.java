package B4.easy.MaxProfitStock;

public class Solution3 {
	public int maxProfit(int[] prices) {
		int maxProfit = 0;
		int buyPrice = prices[0];
		for (int i = 1; i < prices.length; ++i) {
			if (prices[i] < buyPrice) {
				buyPrice = prices[i];
			} else {
				int profitCur = prices[i] - buyPrice;
				if (profitCur > maxProfit) {
					maxProfit = profitCur;
				}
			}
		}
		return maxProfit;
	}
}
