/**************************************
28. N!에서 0의 개수
자연수 N이 입력되면 N! 값에서 일의 자리부터 연속적으로 ‘0’이 몇 개 있는지 구하는 프로그램을 작성하세요. 
만약 5! = 5×4×3×2×1 = 120으로 일의자리부터 연속적된 ‘0’의 개수는 1입니다. 
만약 12! = 479001600으로 일의자리부터 연속적된 ‘0’의 개수는 2입니다.

▣ 입력설명 
첫 줄에 자연수 N(10<=N<=1,000)이 입력된다.
▣ 출력설명 
일의 자리부터 연속된 0의 개수를 출력합니다.
▣ 입력예제 1                                  
12
▣ 출력예제 1
2
***************************************/
#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	//freopen("input.txt", "rt", stdin);
	int n, res = 0;
	scanf("%d", &n);
	vector<int> check(n+1);
	
	for(int i =1; i<=n ; i++)
	{
		int temp = i;
		while(1)
		{
			if(temp%2==0)
			{
				temp = temp/2;
				check[2]++;
			}
			else if(temp%5==0)
			{
				temp = temp/5;
				check[5]++;
			}
			else if(temp%2!=0 && temp%5 != 0)
			{
				break;
			}
		}
	}
	if(check[2]>=check[5])
	{
		for(int i =check[5]; i>0; i--)
		{
			res++;
		}
	}
	else if(check[2]<check[5])
	{
		for(int i =check[2]; i>0; i--)
		{
			res++;
		}
	}
	printf("%d", res);

	return 0;
}

/*
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i, j, tmp, cnt1=0, cnt2=0;
	scanf("%d", &n);
	for(i=2; i<=n; i++){
		tmp=i;
		j=2;
		while(1){
			if(tmp%j==0){
				if(j==2) cnt1++;
				else if(j==5) cnt2++;
				tmp=tmp/j;
			}
			else j++;
			if(tmp==1) break;
		}
	}
	if(cnt1<cnt2) printf("%d\n", cnt1);
	else printf("%d\n", cnt2);
	return 0;
}
*/
