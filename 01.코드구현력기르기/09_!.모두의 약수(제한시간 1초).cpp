

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
09. ����� ��� 

�ڿ��� N�� �ԷµǸ� 1���� N������ �� ���ڵ��� ����� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
���� N�� 8�� �Էµȴٸ� 1(1��), 2(2��), 3(2��), 4(3��), 5(2��), 6(4��), 7(2��), 8(4��)�� ���� �� ������ ����� ������ �������ϴ�.
����� ������ ���� 1���� ���ʴ�� ����� ������ ����ϸ� �˴ϴ�.
1 2 2 3 2 4 2 4 �� ���� ����Ѵ�. 
***************************************/
#include <stdio.h>
//using namespace std;
int cnt[50001];
int main()
{
	//freopen("input.txt", "rt", stdin);
	int n, i, j;
	scanf("%d", &n);
	for(i = 1; i<=n ; i++)
	{
		for(j = i; j<=n; j=j+i)
		{
			cnt[j]++;
		}
	}
	for(i =1; i<=n; i++)
	{
		printf("%d ", cnt[i]);
	}
	
	return 0;
}

