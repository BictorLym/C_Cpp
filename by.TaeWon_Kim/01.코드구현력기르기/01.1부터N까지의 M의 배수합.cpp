#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
자연수 N이 입력되면 1부터 N까지의 수 중 M의 배수합을 출력하는 프로그램을 작성하세요.
입력설명: 첫 줄에 자연수 N과 M이 차례대로 입력됩니다.(3<=M<N<=1000)
출력설명: 첫 줄에 M의 붓합을 출력한다.
***************************************/

using namespace std;
int main()
{
	int m, n, sum = 0;
	
	cin>>n>>m;
	for(int i = 0; i<=n; i++)
	{
		if(i%m==0)
		{
			sum += i;
		}
	}
	cout<<sum;
	return 0;
}

