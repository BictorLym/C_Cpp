

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
10. �ڸ����� ��
N���� �ڿ����� �ԷµǸ� �� �ڿ����� �ڸ����� ���� ���ϰ�, �� ���� �ִ��� �ڿ����� ����ϴ� ���α׷��� �ۼ��ϼ���.
�� �ڿ����� �ڸ����� ���� ���ϴ� �Լ��� int digit_sum(int x)�� �� �ۼ��ؼ� ���α׷����ϼ���. 
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
