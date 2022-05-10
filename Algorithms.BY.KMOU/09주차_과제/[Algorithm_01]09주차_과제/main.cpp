#include<iostream>
#include<vector>
using namespace std;
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

class Item {
private:
	int weight;
	int value;
public:
	Item() {};
	Item(int wet, int val) {
		weight = wet;
		value = val;
	}
	int get_weight() const {
		return weight;
	}
	int get_value() const {
		return value;
	}

};
int knapsac(vector<Item>& arr, int W, int n) {
	if (n == 0 || W == 0) {
		return 0;
	}
	if (arr[n - 1].get_weight() > W) {
		return knapsac(arr, W, n);
	}
	else {
		//maximum(P[i-1][w], p_i + P[i-1][w-w_i])
		//P[i-1][w]
		return max( knapsac(arr, W, n - 1), arr[n - 1].get_value() + knapsac(arr, W - arr[n - 1].get_weight(), n - 1) );
	}
}

int main() {
	//아이템 무게와 가격
	vector<Item> arr;
	arr.push_back(Item(5, 10));
	arr.push_back(Item(10, 60));
	arr.push_back(Item(20, 140));
	//backpack무게
	int W = 30;
	int n = 3;
	int n1 = arr.size();	cout << n1 << endl;
	knapsac(arr, W, n);

	int ans = knapsac(arr, W, n);
	cout << ans;
	return 0;
}