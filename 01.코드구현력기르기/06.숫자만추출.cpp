

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
06. ���ڸ� ���� 
���ڿ� ���ڰ� �����ִ� ���ڿ��� �־����� �� �� ���ڸ� �����Ͽ� �� ������� �ڿ����� ����ϴ�.
������� �ڿ����� �� �ڿ����� ��� ������ ����մϴ�.
����"t0e0a1c2her"���� ���ڸ� �����ϸ� 0, 0, 1, 2�̰� �̰��� �ڿ����� ����� 12�� �˴ϴ�.
�� ù�ڸ� 0�� �ڿ���ȭ �� �� �����մϴ�. ����� 12�� ����ϰ�, ���� �ٿ� 12�� ����� ������ ����ϸ� �˴ϴ�.
�����Ͽ� ��������� �ڿ����� 100,000,000�� ���� �ʽ��ϴ�. 
***************************************/
#include <stdio.h>
using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);
	char a[100];
	scanf("%s", &a);
	int res = 0, cnt = 0;
	for(int i = 0;a[i]!='\0' ; i++)
	{
		if(a[i]>=48 && a[i]<=57)
		{
			res = (res * 10) + (a[i]-48);
		}
	}
	printf("%d\n", res);
	
	for(int j = 1; j<=res ; j++)
	{
		if(res%j==0)	cnt++;
	}
	printf("%d", cnt);
	return 0;
}

