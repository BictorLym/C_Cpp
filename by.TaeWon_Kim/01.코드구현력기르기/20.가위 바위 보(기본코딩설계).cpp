

/**************************************
20. 가위 바위 보
A, B 두 사람이 가위바위보 게임을 합니다. 
총 N번의 게임을 하여 A가 이기면 A를 출력하고, B가 이기면 B를 출력합니다. 
비길 경우에는 D를 출력합니다. 
가위, 바위, 보의 정보는 1:가위, 2:바위, 3:보로 정하겠습니다. 

예를 들어 N=5이면
회수 			1 2 3 4 5
A의 정보 		2 3 3 1 3
B의 정보 		1 1 2 2 3
승자 			A B A B D
두 사람의 각 회의 가위, 바위, 보 정보가 주어지면 각 회를 누가 이겼는지 출력하는 프로그램 을 작성하세요.

▣ 입력설명 
첫 번째 줄에 게임 횟수인 자연수 N(1<=N<=100)이 주어집니다. 
두 번째 줄에는 A가 낸 가위, 바위, 보 정보가 N개 주어집니다. 
세 번째 줄에는 B가 낸 가위, 바위, 보 정보가 N개 주어집니다.

▣ 출력설명 
각 줄에 각 회의 승자를 출력합니다. 
비겼을 경우는 D를 출력합니다.

▣ 입력예제 1                                  
5 
2 3 3 1 3 
1 1 2 2 3
▣ 출력예제 1
A 
B 
A 
B 
D
출처 : 한국정보올림피아
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
	//A가 이기는 경우
	if			(x==1&&y==3)				return -1;
	else if		(x==2&&y==1)				return -1;
	else if		(x==3&&y==2)				return -1;
	
	//A와 B가 비기는 경우 
	else if(x==y)
	{
		res = 0;
	}
	
	//B가 이기는 경우 
	if			(y==1&&x==3)				return 1;
	else if		(y==2&&x==1)				return 1;
	else if		(y==3&&x==2)				return 1;
	
	else;
	
	return res; 
}
