//�˰��� ������ȹ������ ���װ�� ���ϱ⸦ �̿��Ͽ� �͵����� 0���� k������ �迭 �ϳ��� ����ϵ��� ����.

#include<iostream>
#include<vector>

using namespace std;
int bin2(int n, int k);
int bin3(int n, int k);
void printArray(vector<int>& arr, int& k);
int main() {
	int n = 6, k = 4;
	int ans = bin2(n, k);
	cout << ans << '\n';
	int ans3 = bin3(n, k);
	cout << ans3;
	return 0;
}
/*�����Բ� �����غ���*/
int bin3(int n, int k) {
	int i, j;
	int tmp1, tmp2=0;
	vector<int> dp(k + 1, 0);
	//vector<int>::iterator it = dp.begin() + 1;
	
	for (i = 0; i <= n; i++) 
	{
		for (j = 0; j <= min(i, k); j++) {
			tmp1 = tmp2;
			if (j == 0 || j == i) {
				dp[j] = 1;
				tmp2 = dp[j];
			}
			else {
				tmp2 = dp[j];
				dp[j] = tmp1 + dp[j];
				
			}
			cout << i << "��" << j << "��";
			printArray(dp, k);
//if (j == 0) {
//	dp[j] = 1;
//	tmp = dp[1];
//}
//else if (j == i) {
//	dp[j] = 1;
//	//tmp = dp[1];
//}
//else if(j==1){
//	dp[j] = dp[j - 1] + dp[j];
//}

//else {
//	dp[j] = tmp + dp[j];
//	tmp = dp[++j];
//}
		}
	}
	return dp[k];
}
int bin2(int n, int k) {
	int i, j;
	int tmp;
	vector<int> dp(k + 1, 0);
	dp[0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = k; j > 0; j--) {
			dp[j] = dp[j] + dp[j - 1];
		}
	}
	return dp[k];
}
void printArray(vector<int>& arr, int& k) {
	for (int i = 0; i <= k; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}