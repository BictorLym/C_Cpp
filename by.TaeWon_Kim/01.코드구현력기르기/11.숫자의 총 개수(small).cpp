

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
11. ������ �� ����(small)
�ڿ��� N�� �ԷµǸ� 1���� N������ �ڿ����� ���̿� ���� �� �� ���ڴ� �� �� ���������?
���� ��� 1���� 15������ 1,2,3,4,5,6,7,8,9,1,0,1,1,1,2,1,3,1,4,1,5���� �� 21���� �������� �� �� �ֽ��ϴ�.
�ڿ��� N�� �ԷµǸ� 1���� N������ �� ���ڴ� ��� ���Ǿ������� ���ϴ� ���α׷��� �ۼ��ϼ���. 
***************************************/
#include <stdio.h>
//using namespace std;
int digit_sum(int x);
int main()
{
	//freopen("input.txt", "rt", stdin);
	int n, cnt = 0, tmp;
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
	{
		tmp = i;
		while(tmp>0)
		{
			tmp = tmp/10;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
	/*
	int n, cnt = 0;
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
	{
		if		(i>0&&i<10)						cnt++;
		else if	( i>=10 && i<100 )				cnt = cnt +2;
		else if	( i>=100 && i<1000 )			cnt = cnt +3;
		else if	( i>=1000 && i<10000 )			cnt = cnt +4;
		else if	( i>=10000 && i<100000 )		cnt = cnt +4;
		else;
	}
	printf("%d", cnt);
	*/
	
	
}
