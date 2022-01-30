

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
02. 자연수의 합 
자연수 A, B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하세요. 
입력설명: 첫 줄에 더하는 수식과 함께 합을 출력합니다.(1<=A<B<=100) 
출력설명: 첫 줄에 더하는 수식과 함께 합을 출력합니다. 
***************************************/
#include <iostream>
using namespace std;
int main()
{
	int a, b, i , sum = 0;
	
	cin>>a>>b;
	
	for(i = a; i<b; i++)
	{
		cout<<i<<" + ";
		sum +=i;
	}
	cout << b << " = "<<sum+i;

	return 0;
}

