/**************************************
31. 탄화수소 질량
탄소(C)와 수소(H)로만 이루어진 화합물을 탄화수소라고 합니다. 
탄소(C) 한 개의 질량은 12g, 수소(H) 한 개의 질량은 1g입니다. 
에틸렌(C2H4)의 질량은 12*2+1*4=28g입니다. 
메탄(CH4)의 질량은 12*1+1*4=16g입니다. 
탄화수소식이 주어지면 해당 화합물의 질량을 구하는 프로그램을 작성하세요.

▣ 입력설명 
첫 줄에 탄화수소식이 주어집니다. 
식의 형태는 CaHb 형태이며 (1<=a, b<=100)이다. 단 a 나 b 가 1이면 숫자가 식에 입력되지 않는다. 예) CH4

▣ 출력설명 
첫 줄에 탄화수소의 질량을 출력합니다.

▣ 입력예제 1                                  
C2H4
▣ 출력예제 1
28

▣ 입력예제 2
CH4
▣ 출력예제 2
16
***************************************/
#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;



int main(void)
{
	//freopen("input.txt", "rt", stdin);
	char a[10];
	int c = 0, h = 0, pos, i;
	
	scanf("%s", &a);

	//탄소(C) 한 개의 질량은 12g, 수소(H) 한 개의 질량은 1g
	if(a[1]=='H')
	{
		c = 1;
		pos = 1;	
	}
	else
	{
		for(i = 1; a[i]!='H'; i++)
		{
			c = c*10 + (a[i] - 48);
		}
		pos = i;
	}
	if(a[pos+1]=='\0')		h=1;
	else
	{
		for(i=pos+1; a[i]!='\0' ; i++)
		{
			h = h*10 + (a[i]-48);
		}
	}
	printf("%d", (12*c+1*h));

	return 0;
}

