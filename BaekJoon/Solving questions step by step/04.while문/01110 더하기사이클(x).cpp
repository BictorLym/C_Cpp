/******************************************************************************************
<백준 1110> 더하기 사이클


문제
0보다 크거나 같고, 99보다 작거나 같은 정수가 주어질 때 다음과 같은 연산을 할 수 있다. 
먼저 주어진 수가 10보다 작다면 앞에 0을 붙여 두 자리 수로 만들고, 각 자리의 숫자를 더한다. 
그 다음, 주어진 수의 가장 오른쪽 자리 수와 앞에서 구한 합의 가장 오른쪽 자리 수를 이어 붙이면 새로운 수를 만들 수 있다. 
다음 예를 보자.

26부터 시작한다. 2+6 = 8이다. 새로운 수는 68이다. 6+8 = 14이다. 
새로운 수는 84이다. 8+4 = 12이다. 새로운 수는 42이다. 4+2 = 6이다. 새로운 수는 26이다.

위의 예는 4번만에 원래 수로 돌아올 수 있다. 따라서 26의 사이클의 길이는 4이다.

N이 주어졌을 때, N의 사이클의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. N은 0보다 크거나 같고, 99보다 작거나 같은 정수이다.

출력
첫째 줄에 N의 사이클 길이를 출력한다.

예제 입력 1 
26
예제 출력 1 
4
예제 입력 2 
55
예제 출력 2 
3
예제 입력 3 
1
예제 출력 3 
60
예제 입력 4 
0
예제 출력 4 
1
예제 입력 5 
71
예제 출력 5 
12

******************************************************************************************/
#include <iostream>
 
using namespace std;
 
int main(int argc, const char *argv[]) {
 
	int init, N;
	int count = 0;
	cin >> init;
 
	N = init;
 
	do {
		// N에 대해 반복하므로 연산된 값도 N으로 덮어써준다.
		N = (N % 10) * 10 + ((N / 10) + (N % 10)) % 10;
 
		count++; // 사이클 수 증가
	} while (init != N);
 
	cout << count;	// 사이클 수 출력
	return 0;
}
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int addCycle(int n);
int calDigitNumber(int n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	//cout << calDigitNumber(n);
	cout << addCycle(n);
	return 0;
}
int addCycle(int n)
{
	int m = n;
	int cnt = 0, sum = 0;
	while(sum!=n)
	{
		//int digit = calDigitNumber(m);
		//cout << digit;
		vector<int> arr(3);
		for(int i = 1; i <= 2; i++)
		{
			arr[i] = m%10;
			m = m/10;
		}
		sum = (arr[1] * 10) + ( (arr[1] + arr[2])%10 );
		m = sum;
		//cout << sum << endl;
		cnt++;
	}
	return cnt;
}
int calDigitNumber(int n)
{
	int result = 0;
	for(int i = 10; n > 0; i*10)
	{
		n = n/i;
		result++;
	}
	return result;
}
*/