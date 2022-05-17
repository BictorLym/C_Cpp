#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int size1 = 7;
vector<vector<int>> W(size1, vector <int>(size1, 0));
vector<int> vcolor(size1, 0);
void printMatrix(vector<vector<int>>& matrix);
void printColor() {
	for (int i = 1; i < size1; i++) {
		cout << vcolor[i] << " ";
	}
	cout << endl;
}
int m = 3;
bool promising(int i) {
	int j;
	bool switch1;

	switch1 = true;
	j = 1;
	while (j < i && switch1) {
		if (W[i][j] && vcolor[i] == vcolor[j]) {
			switch1 = false;
		}
		j++;
	}
	return switch1;
}
void m_coloring(int i) {
	int color;
	int n = size1 - 1;
	if (promising(i)) {
		if (i == n) {
			printColor();
		}
		else {
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				m_coloring(i + 1);
			}
		}
	}
}

int main() {
	
	
	W[1][2] = 1; W[1][4] = 1;
	W[2][1] = 1; W[2][3] = 1; W[2][5] = 1;
	W[3][2] = 1; W[3][6] = 1;
	W[4][1] = 1; W[4][5] = 1;
	W[5][2] = 1; W[5][4] = 1; W[5][6] = 1;
	W[6][3] = 1; W[6][5] = 1;
	
	//printMatrix(W);

	m_coloring(0);
	
}
void printMatrix(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	//cout << n;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}