/******************************************************************************************
<백준 23320> 홍익 절대평가


문제
2021년, 홍익대학교는 절대평가를 시행한다. 착한 도현이는 A학점을 받는 사람이 최대한 많았으면 한다.

시험을 응시한 학생의 수 N, 상대평가 시 A학점의 비율 X%와 절대평가 시 A학점을 받기 위한 최소 점수 Y점이 주어질 때, 
상대평가 시 A학점을 받는 인원의 수와 절대평가 시 A학점을 받는 인원의 수를 구하는 프로그램을 작성해보자.

입력
첫째 줄에 시험을 응시한 학생의 수 정수 N (10 <= N <= 100, N은 10의 배수) 이 주어진다.

둘째 줄에 길이가 N인 정수 수열 A (1 <= A_i <= 100)가 공백을 기준으로 주어진다. 
i번째로 주어지는 수 A_i는 i번째 학생의 점수이다. 모든 학생의 점수는 다르다.

셋째 줄에 상대평가 시 A학점의 비율 X (10 <= X <= 100, X는 10의 배수)와 절대평가 시 A학점을 받기 위한 최소 점수 Y (1 <= Y <= 100)가 정수로 주어진다.

출력
첫째 줄에 상대평가 시 A학점을 받는 인원의 수와 절대평가 시 A학점을 받는 인원의 수를 공백으로 구분해 출력한다.

예제 입력 1 
10
1 2 3 4 5 6 7 8 9 10
50 3
예제 출력 1 
5 8
예제 입력 2 
10
1 2 3 4 5 6 7 8 9 10
50 6
예제 출력 2 
5 5

******************************************************************************************/
#include<iostream>
#include<vector>

using namespace std;
int relativeEval(/*vector<int> a,*/ int percent, int n);
int absoluteEval(vector<int> a, int cutOffScore, int n);
int main()
{
	int n;
	int percentage, cutOffScore;
	int i, j;
	cin >> n;
	vector<int> a(n);
	for( i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> percentage >> cutOffScore;
	cout << relativeEval(percentage, n) << ' ';
	cout << absoluteEval(a, cutOffScore, n);
	return 0;
}
int relativeEval(/*vector<int> a,*/ int percent, int n)
{
	int cnt = 0;
	//sort(a.begin(), a.end());
	cnt = n * percent / 100;
	return cnt;
}
int absoluteEval(vector<int> a, int cutOffScore, int n)
{
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] >= cutOffScore )	cnt++;
	}

	return cnt;
}