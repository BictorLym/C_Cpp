

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
02. �ڿ����� �� 
�ڿ��� A, B�� �־����� A���� B������ ���� ���İ� �Բ� ����ϼ���. 
�Է¼���: ù �ٿ� ���ϴ� ���İ� �Բ� ���� ����մϴ�.(1<=A<B<=100) 
��¼���: ù �ٿ� ���ϴ� ���İ� �Բ� ���� ����մϴ�. 
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

