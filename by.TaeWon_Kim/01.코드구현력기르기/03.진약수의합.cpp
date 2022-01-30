

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
03. 진약수의 합 
자연수 N이 주어지면 자연수 N의 진약수의 합을 수식과 함께 출력하는 프로그램을 작성하세요 
입력설명: 첫 줄에 자연수 N이 주어집니다.(3<N<=100) 
출력설명: 첫 줄에 더하는 수식과 함께 합을 출력합니다. 
***************************************/
#include <iostream>
using namespace std;
int main()
{
	int n, sum = 1;
	cin>>n;
	cout<<"1";
	for (int i = 2; i<n; i++)
	{
		if(n%i==0)
		{
			cout<<"+"<<i;
			sum += i;
		}
	}
	cout <<"="<< sum;
	return 0;
}

