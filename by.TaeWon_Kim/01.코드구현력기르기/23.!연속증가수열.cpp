

/**************************************
23. ���� �κ� ��������
N���� ���ڰ� ������ ������ �־����ϴ�. 
�� ���� �� ���������� �����ϴ� �κ� ������ �ִ� ���̸� ���Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
���� N=9�̰� 5 7 3 3 12 12 13 10 11 �̸� ��3 3 12 12 13���κ��� �ִ� ���� ���������̹Ƿ� �� ������ 5�� ����մϴ�. 
���� ���� ���� �����ϴ� �ɷ� �����մϴ�.

�� �Է¼��� 
ù �ٿ� �ڿ����� ���� N(5<=N<=100,000)�� �־����ϴ�. 
�� ��° �ٿ� N���� ���ڿ��� �־����ϴ�. �� ���ڴ� 100,000������ �ڿ����Դϴ�.
�� ��¼��� 
�ִ� �κ� ���������� ���̸� ����ϼ���.
�� �Է¿��� 1                                  
9 
5 7 3 3 12 12 13 10 11
�� ��¿��� 1
5
***************************************/
#include <stdio.h>
#include <vector>



int main(){
	//freopen("input.txt", "rt", stdin);
	int n, i, pre, now, cnt, max;
	scanf("%d", &n);
	scanf("%d", &pre);
	cnt=1;
	max=1;
	for(i=2; i<=n; i++){
		scanf("%d", &now);
		if(now>=pre){
			cnt++;
			if(cnt>max) max=cnt;
		}
		else cnt=1;
		pre=now;
	}
	printf("%d\n", max);	
	return 0;
}

/*
int main()
{
	//freopen("input.txt", "rt", stdin);
	int n, max=-2147000000, length;
	scanf("%d" , &n);
	int a[n];
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &a[n]);
	}
	max = 1;
	length=1;
	
	for(int i = 0; i<n; i++)
	{
		a[n] = -2147000000;
		if(a[i+1]>=a[i])
		{
			length++;
			if(max<length)
			{
				max=length;
			}
		}
		else
		{
			length=1;
		}
	}
	printf("%d\n", max);
	
	return 0;
}
*/
