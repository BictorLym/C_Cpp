#include"knapsac.h"
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int knapsac_dp(vector<Item>& arr, int W, int n) {
	if (n == 0 || W == 0) {
		return 0;
	}
	if (arr[n - 1].get_weight() > W) {
		return knapsac_dp(arr, W, n - 1); cout << "debugging" << endl;
	}
	else {
		//maximum(P[n-1][w], p_n + P[n-1][w-w_n])
		//P[n-1][w]
		return max(knapsac_dp(arr, W, n - 1), 
			arr[n - 1].get_value() + knapsac_dp(arr, W - arr[n - 1].get_weight(), n - 1));
	}
}
bool cmpVperW(Item n1, Item n2) {
	return n1.get_VperW() > n2.get_VperW();
}
int knapsac_greedy(vector<Item> items, int W) {
	sort(items.begin(), items.end(), cmpVperW);
	//print_items(items);
	int i = 0;
	int stealedValue = 0;
	while (W > items[i].get_weight()) {
		stealedValue += items[i].get_value();
		W -= items[i].get_weight();
		i++;
	}

	return stealedValue;
}