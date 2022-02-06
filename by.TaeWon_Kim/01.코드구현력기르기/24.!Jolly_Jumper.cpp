

/**************************************
24. Jolly Jumpers
N���� ������ �̷���� ������ ���� ���� ������ �ִ� �� ���� ���� 1���� N-1������ ���� ��� ������
�� ������ ������ ����(jolly jumper)��� �θ���.
���� ��� ������ ���� ������ �� 1 4 2 3 �� �ڿ� �ִ� ���� ���� ���� ���� ���� 3 ,2, 1�̹Ƿ�
 �� ������ ������ ���۰� �ȴ�. � ������ ������ �������� �Ǵ��� �� �ִ� ���α׷��� �ۼ��϶�.

�� �Է¼��� 
ù ��° �ٿ� �ڿ��� N(3<=N<=100)�� �־�����. 
�� ���� �ٿ� N���� ������ �־�����. 
������ ũ��� int �� �����ȿ� ������, ������ �� ���� ���� ������ ������ �ֽ��ϴ�.
�� ��¼��� 
������ �����̸� ��YES"�� ����ϰ�, �׷��� ������ ��NO"�� ����Ѵ�.

�� �Է¿��� 1                                  
5 
1 4 2 3 7
�� ��¿��� 1
YES
***************************************/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, i, now, pre, pos;
	scanf("%d", &n);
	vector<int> ch(n);
	scanf("%d", &pre);
	for(i=1; i<n; i++){
		scanf("%d", &now);
		pos=abs(pre-now);
		if(pos>0 && pos<n && ch[pos]==0) ch[pos]=1;
		else{
			printf("NO\n");
			return 0;
		}
		pre=now;
	}
	printf("YES\n");
	return 0;
}
/*
#include <stdio.h>
#include <math.h>
int bubble_sort(int x[], int n);
int is_Jolly_Jumper(int x[], int n);
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	int b[n-1];
	for(int i = 0; i<n-1; i++)
	{
		b[i] = abs(a[i]-a[i+1]);
	}
	if(is_Jolly_Jumper(b, n))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	
	return 0;
}
int bubble_sort(int x[], int n)
{
	int temp;
	for(int i = 0; i<n ; i++)
	{
		for(int j = 0; j<n-1; j++)
		{
			if (x[j]>x[j+1])
			{
				temp = x[j];
				x[j]=x[j+1];
				x[j+1] = temp;
			}
			
		}
	}
}
int is_Jolly_Jumper(int x[], int n)
{
	int res;
	bubble_sort(x, n);
	for(int i = 0; i<n-1; i++)
	{
		if(x[i]==i+1)
		{
			res = 1;
		}
		else
		{
			res = 0;
			break;
		}
		
	}	
	return res;
}
*/
