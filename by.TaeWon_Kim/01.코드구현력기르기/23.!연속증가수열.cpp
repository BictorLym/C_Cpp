

/**************************************
23. 연속 부분 증가수열
N개의 숫자가 나열된 수열이 주어집니다. 
이 수열 중 연속적으로 증가하는 부분 수열을 최대 길이를 구하여 출력하는 프로그램을 작성하세요.
만약 N=9이고 5 7 3 3 12 12 13 10 11 이면 “3 3 12 12 13”부분이 최대 길이 증가수열이므로 그 길이인 5을 출력합니다. 
값이 같을 때는 증가하는 걸로 생각합니다.

▣ 입력설명 
첫 줄에 자연수의 개수 N(5<=N<=100,000)이 주어집니다. 
두 번째 줄에 N개의 숫자열이 주어집니다. 각 숫자는 100,000이하의 자연수입니다.
▣ 출력설명 
최대 부분 증가수열의 길이를 출력하세요.
▣ 입력예제 1                                  
9 
5 7 3 3 12 12 13 10 11
▣ 출력예제 1
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
