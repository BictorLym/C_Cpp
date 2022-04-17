#include<iostream>
#include<vector>
#include<ctime>

using namespace std;
int bin(int n, int k) {
	if (k == 0 || n == k) {
		return 1;
	}
	else {
		return bin(n - 1, k - 1) + bin(n - 1, k);
	}
}
int bin2(int n, int k) {
	int i, j;
	vector<vector<int>> matrix(n+1, vector<int>(k+1,0));
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= min(i, k); j++) {
			if (j == i || j == 0) {
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
			}
		}
	}
	return matrix[n][k];
}
int main() {
	int n = 30, k = 15;

	clock_t begin1 = clock();
	int nCk_1 = bin(n, k);
	cout << nCk_1 << "\n";
	clock_t end1 = clock();
	double elapsed_sec1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	cout << "nCk_1 경과된 시간 초" << elapsed_sec1 << '\n';

	clock_t begin2 = clock();
	int nCk_2 = bin2(n, k);
	cout << nCk_2 << "\n";
	clock_t end2 = clock();
	double elapsed_sec2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	cout << "nCk_1 경과된 시간 초" << elapsed_sec2 << '\n';

	return 0;
}