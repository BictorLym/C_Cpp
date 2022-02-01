

/**************************************
14. 뒤집은 소수
N자리의 자연수가 입력되면 각 자연수를 뒤집은 후 그 뒤집은 수가 소수이면 그 수를 출력하는 프로그램을 작성하세요.
예를 들어 32를 뒤집으면 23이고, 23은 소수이다. 그러면 23을 출력한다. 단 910을 뒤집으면 19로 숫자화 해야한다.
첫자리부터 연속된 0은 무시한다.
뒤집은 함수인 int reverse(int x)와 소수인지를 확인하는 함수 bool isPrime(int x)를 반드시 작성하여 프로그래밍 한다. 
 ***************************************/
#include <stdio.h>
//using namespace std;
int reverse(int x);
bool isPrime(int x);
int main()
{
	//freopen("input.txt", "rt", stdin);s
	int n, num, i, tmp;
	scanf("%d", &n);
	for(i = 1; i<=n; i++)
	{
		scanf("%d", &num);
		tmp=reverse(num);
		if(isPrime(tmp))	printf("%d ", tmp);
	}
	return 0;
}
int reverse(int x) 
{
	int res = 0, tmp;
	while(x>0)
	{
		tmp = x%10;
		res = res*10 + tmp;
		x=x/10;
	}
	return res;
}
bool isPrime(int x)
{
	int i;
	if(x==1) return false;
	bool flag = true;
	for(i = 2; i<x; i++)
	{
		if(x%i==0)
		{
			flag = false;
			break;
		}
	
	}
	return flag;
}




