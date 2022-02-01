

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
11. 숫자의 총 개수(small)
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였을까요?
예를 들어 1부터 15까지는 1,2,3,4,5,6,7,8,9,1,0,1,1,1,2,1,3,1,4,1,5으로 총 21개가 쓰였음을 알 수 있습니다.
자연수 N이 입력되면 1부터 N까지의 각 숫자는 몇개가 사용되었는지를 구하는 프로그램을 작성하세요. 
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
