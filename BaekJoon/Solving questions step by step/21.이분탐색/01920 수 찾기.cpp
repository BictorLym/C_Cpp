/******************************************************************************************
<백준 01920> 수 찾기


문제
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 
다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 
다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 
모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

출력
M개의 줄에 답을 출력한다. 
존재하면 1을, 존재하지 않으면 0을 출력한다.

예제 입력 1 
5
4 1 5 2 3
5
1 3 7 9 5
예제 출력 1 
1
1
0
0
1
******************************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int A[100010];
int n, m;
int binarySearch(int key);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> n;
	//key값
	for(int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	cin >> m;
	// vector<int> B(m+1, -1000);
	// for(int i = 1; i <= m; i++)
	// {
	// 	cin >> B[i];
	// }
	
	
	//cout <<  A.front()  << A.back() <<"zz" << A.size();
	sort(A+1, A+n+1);
    
	// for(int i = 0; i <=n ; i++){
	// 	cout << A[i] << '\t';
	// }
	int key;
	//M개의 수들(B)이 A안에 존재하는지 확인하는 알고리즘
	for(int i = 1; i <= m; i++)
	{
		cin >> key;
		binarySearch(key);
	}
	

	return 0;
}

int binarySearch(int key)
{
	int low = 1, high = n;
	int mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if		(key == A[mid]){
			cout << 1 << "\n";
			return 1;
		}
		else if (key > A[mid])		low = mid + 1;
		else if (key < A[mid])		high = mid - 1;
	}
	cout << 0 << "\n";
	return 0;
}


// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int binarySearch(vector<int> A, int key);
// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL), cout.tie(NULL);
// 	int n, m;
// 	cin >> n;
// 	//key값
// 	vector<int> A(n+1, -1000);
// 	for(int i = 1; i <= n; i++)
// 	{
// 		cin >> A[i];
// 	}

// 	cin >> m;
// 	vector<int> B(m+1, -1000);
// 	for(int i = 1; i <= m; i++)
// 	{
// 		cin >> B[i];
// 	}
	
	
// 	//cout <<  A.front()  << A.back() <<"zz" << A.size();
// 	sort(A.begin()+1, A.end());
    
// 	// for(int i = 0; i <=n ; i++){
// 	// 	cout << A[i] << '\t';
// 	// }
	
// 	//M개의 수들(B)이 A안에 존재하는지 확인하는 알고리즘
// 	for(int i = 1; i <= m; i++)
// 	{
// 		if( binarySearch(A, B[i]) )		cout << 1 << "\n";
// 		else							cout << 0 << "\n";
// 	}
	
// 	// for(int i = 1; i <= m; i++)
// 	// {
// 	// 	int low = 1, high = n;
// 	// 	int mid, key = B[i];
// 	// 	int idx = 0;
// 	// 	while(low <= high)
// 	// 	{
// 	// 		mid = (low + high) / 2;
// 	// 		if		(key == A[mid])		idx = mid;
// 	// 		else if (key > A[mid])		low = mid + 1;
// 	// 		else if (key < A[mid])		high = mid - 1;
// 	// 	}
// 	// 	if( idx )		cout << 1 << "\n";
// 	// 	else			cout << 0 << "\n";
// 	// }
// 	return 0;
// }

// int binarySearch(vector<int> A, int key)
// {
// 	int low = 1, high = A.size()-1;
// 	int mid;
// 	while(low <= high)
// 	{
// 		mid = (low + high) / 2;
// 		if		(key == A[mid])		return mid;
// 		else if (key > A[mid])		low = mid + 1;
// 		else if (key < A[mid])		high = mid - 1;
// 	}
// 	return 0;
// }

/*
int low = 0, high = m-1;
		int key = B[i], mid;
		while(low<=high)
		{
			mid = (low + high) / 2;
			if		(key == A[mid])		cout << 1 << '\n';
			else if (key > A[mid])		low = mid + 1;
			else if (key < A[mid])		high = mid - 1;
			else;
		}
		cout << 0 << '\n';
		*/