

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
10. 자릿수의 합
N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력하는 프로그램을 작성하세요.
각 자연수의 자릿수의 합을 구하는 함수를 int digit_sum(int x)를 꼭 작성해서 프로그래밍하세요. 
***************************************/
#include <stdio.h>
//using namespace std;
int digit_sum(int x);
int main()
{
	//freopen("input.txt", "rt", stdin);
	int n, num, i, sum, max=-2147000000, res;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &num);
		sum=digit_sum(num);
		if(sum>max){
			max=sum;
			res=num;
		}
		else if(sum==max){
			if(num>res) res=num;
		}
	}
	printf("%d\n", res);
	return 0;
}
int digit_sum(int x){
	int sum=0, tmp;
	while(x>0){
		tmp=x%10;
		sum=sum+tmp;
		x=x/10;
	}
	return sum;
}
/*
int digit_sum(int x)
{
	int tmp, sum =0;
	while(x>0)
	{
		sum += x%10;
		x=x/10;
	}
	
	return sum;
}
*/
