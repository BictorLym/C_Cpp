

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
03. ������� �� 
�ڿ��� N�� �־����� �ڿ��� N�� ������� ���� ���İ� �Բ� ����ϴ� ���α׷��� �ۼ��ϼ��� 
�Է¼���: ù �ٿ� �ڿ��� N�� �־����ϴ�.(3<N<=100) 
��¼���: ù �ٿ� ���ϴ� ���İ� �Բ� ���� ����մϴ�. 
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

