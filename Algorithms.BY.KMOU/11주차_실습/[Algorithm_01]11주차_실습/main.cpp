#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxprofit;
int numbest;
int n;
int W;


class Item {
private:
	string name;
	int value;
	int weight;
	double vPerw;
public:
	Item() {};
	Item(string name, int val, int wet) {
		this->name = name;
		this->value = val;
		this->weight = wet;
		this->vPerw = (double)(val) / (double)wet;
	}
	string get_name() const {
		return name;
	}
	int get_weight() const {
		return weight;
	}
	int get_value() const {
		return value;
	}
	double get_vPerw() const {
		return vPerw;
	}
};
bool cmp(Item n1, Item n2) {
	return n1.get_vPerw() > n2.get_vPerw();
}
void print_items(vector<Item>& items) {
	vector<Item>::iterator it;
	for (it = items.begin(); it != items.end(); ++it) {
		cout << "이름:" << it->get_name() << "  "
			<< "무게:" << it->get_weight() << "  "
			<< "가치:" << it->get_value() << "  "
			<< "단위당가치:" << it->get_vPerw() << endl;
	}
}
void knapsac(int i, int profit1, int weight1);
//bool promising(int i);
bool promising(int i, int weight1, int profit1);
vector<Item> arr;
//int bestset[5];
vector<char> bestset(5);
vector<char> include(5);
int main() {
	//vector<Item> arr;
	arr.push_back(Item("0", 0, 0));
	arr.push_back(Item("1", 40, 2));
	arr.push_back(Item("2", 30, 5));
	arr.push_back(Item("3", 50, 10));
	arr.push_back(Item("4", 10, 5));
	sort(arr.begin(), arr.end(), cmp);
	print_items(arr);
	
	//아이템 갯수
	//int n = arr.size();
	n = 4;
	//가방 무게
	W = 16;
	//cout << "n:" << n << "  " << "W:" << W << "\n";
	maxprofit = 0;
	numbest = 0;
	int profit1 = 0;
	int weight1 = 0;
	knapsac(0, profit1, weight1);
	//cout << numbest;
	cout << maxprofit;
	for (int k = 1; k <= numbest; k++) {
		cout << bestset[k];
	}
}
void knapsac(int i, int profit1, int weight1) {
	if (weight1 <= W && profit1 > maxprofit) {
		maxprofit = profit1;
		//cout << "i:" <<i << endl;
		numbest = i;
		//bestset[i] = include[i];
		bestset = include;
	}
	if (promising(i, weight1, profit1)) {
		include[i + 1] = 'Y';
		//knapsac(i + 1, profit + p[i + 1], weight + w[i + 1]);
		knapsac(i + 1, profit1 + arr[i+1].get_value(), weight1 + arr[i+1].get_weight());
		include[i + 1] = 'N';
		knapsac(i + 1, profit1, weight1);
	}
}
bool promising(int i, int weight1, int profit1) {
	int j, k;
	int totweight;
	float bound;
	
	if (weight1 >= W) {
		return false;
	}
	else {
		j = i + 1;
		bound = profit1;
		totweight = weight1;
		/*while (j <= n && totweight + w[j] <= W)*/
		while (j <= n && totweight + arr[j].get_weight() <= W) {
			/*totweight = totweight + w[j];*/
			totweight = totweight + arr[j].get_weight();
			/*bound = bound + p[j];*/
			bound = bound + arr[j].get_value();
			j++;
		}
		k = j;
		if (k <= n) {
			/*bound = bound + (W - totweight) * p[k] / w[k];*/
			bound = bound + (W - totweight) * (arr[k].get_value() / arr[k].get_weight());
		}
		return bound > maxprofit;
	}
}