#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
�ڿ��� N�� �ԷµǸ� 1���� N������ �� �� M�� ������� ����ϴ� ���α׷��� �ۼ��ϼ���.
�Է¼���: ù �ٿ� �ڿ��� N�� M�� ���ʴ�� �Էµ˴ϴ�.(3<=M<N<=1000)
��¼���: ù �ٿ� M�� ������ ����Ѵ�.
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

