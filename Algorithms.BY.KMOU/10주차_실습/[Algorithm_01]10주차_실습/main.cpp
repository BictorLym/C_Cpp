#include<iostream>
#include<vector>
using namespace std;
int n = 8;
vector<int> col(9, 0);

void print1(vector<int> col, int i) {
	for (int i = 1; i <= n; i++) {
		//cout << "i:" << i << "col:" << col[i] << "    ";
		cout << col[i] << " ";
	}
	cout << "\n";
}
bool promising(int i) {
	int k;
	bool switch1;

	k = 1;
	switch1 = true;
	while (k < i && switch1) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k) {
			switch1 = false;
		}
		k++;
	}
	return switch1;
}
void queens(int i) {
	int j;
	if (promising(i)) {
		if (i == n) {
			print1(col, i);
			//cout << col[i];
		}
		else {
			for (j = 1; j <= n; j++) {
				col[i + 1] = j;
				queens(i + 1);
			}
		}
	}
}


int main() {
	queens(0);

	return 0;
}