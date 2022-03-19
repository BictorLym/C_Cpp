/******************************************************************************************
<백준 10816> 숫자 카드2


문제
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 
상근이는 숫자 카드 N개를 가지고 있다. 
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 
둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 
숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 
넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 
이 수는 공백으로 구분되어져 있다. 
이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.

예제 입력 1 
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10
예제 출력 1 
3 0 0 1 2 0 0 2
******************************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//원하는 값이 처음 나오는 인덱스 반환
int lowerBinarySearch(vector<int> arr, int key);
//원하는 값이 마지막으로 나오는 인덱스+1 반환
int upperBinarySearch(vector<int> arr, int key);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	//n은 상근이의 카드 갯수
	int n;
	cin >> n;
	//상근이가 가지고 있는 카드
	vector<int> cardSangkyuen(n);
	for(int i = 0; i < n; i++)
	{
		cin >> cardSangkyuen[i];
	}
	sort(cardSangkyuen.begin(), cardSangkyuen.end());

	//m은 주어진 정수의 갯수
	int m;
	cin >> m;
	int key;
	for(int i = 0; i < m; i++)
	{
		cin >> key;
		int ans = ( 
			upper_bound(cardSangkyuen.begin(), cardSangkyuen.end(), key) - 
			lower_bound(cardSangkyuen.begin(), cardSangkyuen.end(), key)
			 );
		cout << ans << " ";
	}
	return 0;
}

int lowerBinarySearch(vector<int> arr, int key)
{
	int low = 0, high = arr.size()-1;
	int mid;
	while(low < high)
	{
		mid = (low + high) /2;
		if(key <= arr[mid])			
		{
			high = mid;
		}
		else if (key > arr[mid])	low = mid + 1;
		
	}
	return high;
}
int upperBinarySearch(vector<int> arr, int key)
{
	int low = 0, high = arr.size()-1;
	int mid;
	while(low < high)
	{
		mid = (low + high) /2;
		if(key < arr[mid])			
		{
			high = mid;
		}
		else if (key >= arr[mid])	low = mid + 1;
		
	}
	return high;
}
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void binarySearch(vector<int> arr, int key);
//int binarySearch1(vector<int> arr, int key);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	//n은 상근이의 카드 갯수
	int n;
	cin >> n;
	//상근이가 가지고 있는 카드
	vector<int> cardSangkyuen(n);
	for(int i = 0; i < n; i++)
	{
		cin >> cardSangkyuen[i];
	}
	sort(cardSangkyuen.begin(), cardSangkyuen.end());

	//m은 주어진 정수의 갯수
	int m;
	cin >> m;
	int key;
	for(int i = 0; i < m; i++)
	{
		cin >> key;
		binarySearch(cardSangkyuen, key);
	}
	return 0;
}

void binarySearch(vector<int> arr, int key)
{
	int low = 0, high = arr.size()-1;
	int mid;
	while(low <= high)
	{
		mid = (low + high) /2;
		if(key == arr[mid])			//return mid;
		{
			int i = mid;
			int midMin = i, midMax = i;
			for(i = mid; arr[i]==key ; i++){
				midMax = i;
			}
			for(i = mid; arr[i]==key ; i--){
				midMin = i;
			}
			cout << ((midMax - midMin) + 1) << " ";
			return;
		}
		else if (key > arr[mid])	low = mid + 1;
		else if (key < arr[mid])	high = mid -1;
	}
	cout << 0 << " ";
	return;
}
*/
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void binarySearch(vector<int> arr, int key);
//int binarySearch1(vector<int> arr, int key);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	//n은 상근이의 카드 갯수
	int n;
	cin >> n;
	//상근이가 가지고 있는 카드
	vector<int> cardSangkyuen(n);
	for(int i = 0; i < n; i++)
	{
		cin >> cardSangkyuen[i];
	}
	sort(cardSangkyuen.begin(), cardSangkyuen.end());

	//m은 주어진 정수의 갯수
	int m;
	cin >> m;
	int key;
	for(int i = 0; i < m; i++)
	{
		cin >> key;
		//cout << "index" << binarySearch1(cardSangkyuen, key) << " ";
		binarySearch(cardSangkyuen, key);
	}
	// for(int i = 0; i < n; i++)
	// {
	// 	cout << cardSangkyuen[i] << " ";
	// }
	return 0;
}

void binarySearch(vector<int> arr, int key)
{
	int low = 0, high = arr.size()-1;
	int mid;
	while(low <= high)
	{
		mid = (low + high) /2;
		if(key == arr[mid])			//return mid;
		{
			int i = mid;
			int midMin = i, midMax = i;
			for(i = mid; arr[i]==key ; i++){
				midMax = i;
			}
			for(i = mid; arr[i]==key ; i--){
				midMin = i;
			}
			// while(arr[i]==key){
			// 	midMin = i;
			// 	i--;
			// }
			// i = mid;
			// while(arr[i]==key){
			// 	midMax = i;
			// 	i++;
			// }
			cout << ((midMax - midMin) + 1) << " ";
			return;
		}
		else if (key > arr[mid])	low = mid + 1;
		else if (key < arr[mid])	high = mid -1;
	}
	cout << 0 << " ";
	return;
}
// int binarySearch1(vector<int> arr, int key)
// {
// 	int low = 0, high = arr.size()-1;
// 	int mid;
// 	while(low <= high)
// 	{
// 		mid = (low + high) / 2;
// 		if		(key == arr[mid])	return mid;
// 		else if (key > arr[mid])	low = mid + 1;
// 		else if (key < arr[mid])	high = mid -1;
// 	}
// 	return -1;
// }
*/