

/**************************************
20. ���� ���� ��
A, B �� ����� ���������� ������ �մϴ�. 
�� N���� ������ �Ͽ� A�� �̱�� A�� ����ϰ�, B�� �̱�� B�� ����մϴ�. 
��� ��쿡�� D�� ����մϴ�. 
����, ����, ���� ������ 1:����, 2:����, 3:���� ���ϰڽ��ϴ�. 

���� ��� N=5�̸�
ȸ�� 			1 2 3 4 5
A�� ���� 		2 3 3 1 3
B�� ���� 		1 1 2 2 3
���� 			A B A B D
�� ����� �� ȸ�� ����, ����, �� ������ �־����� �� ȸ�� ���� �̰���� ����ϴ� ���α׷� �� �ۼ��ϼ���.

�� �Է¼��� 
ù ��° �ٿ� ���� Ƚ���� �ڿ��� N(1<=N<=100)�� �־����ϴ�. 
�� ��° �ٿ��� A�� �� ����, ����, �� ������ N�� �־����ϴ�. 
�� ��° �ٿ��� B�� �� ����, ����, �� ������ N�� �־����ϴ�.

�� ��¼��� 
�� �ٿ� �� ȸ�� ���ڸ� ����մϴ�. 
����� ���� D�� ����մϴ�.

�� �Է¿��� 1                                  
5 
2 3 3 1 3 
1 1 2 2 3
�� ��¿��� 1
A 
B 
A 
B 
D
��ó : �ѱ������ø��Ǿ�
***************************************/
#include <stdio.h>
int scissor_rock_paper(int x, int y);
int main()
{
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	int z;
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &b[i]);
	}
	for(int i = 0; i<n; i++)
	{
		z = scissor_rock_paper(a[i], b[i]);
		
		if(z==-1)
		{
			printf("A\n" );
		}
		else if(z==0)
		{
			printf("D\n" );
		}
		else if(z==1)
		{
			printf("B\n");
		}
		else;
	}
	
	return 0;
}
int scissor_rock_paper(int x, int y)
{
	int res;
	//A�� �̱�� ���
	if			(x==1&&y==3)				return -1;
	else if		(x==2&&y==1)				return -1;
	else if		(x==3&&y==2)				return -1;
	
	//A�� B�� ���� ��� 
	else if(x==y)
	{
		res = 0;
	}
	
	//B�� �̱�� ��� 
	if			(y==1&&x==3)				return 1;
	else if		(y==2&&x==1)				return 1;
	else if		(y==3&&x==2)				return 1;
	
	else;
	
	return res; 
}
