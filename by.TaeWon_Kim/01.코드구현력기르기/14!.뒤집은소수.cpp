

/**************************************
14. ������ �Ҽ�
N�ڸ��� �ڿ����� �ԷµǸ� �� �ڿ����� ������ �� �� ������ ���� �Ҽ��̸� �� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
���� ��� 32�� �������� 23�̰�, 23�� �Ҽ��̴�. �׷��� 23�� ����Ѵ�. �� 910�� �������� 19�� ����ȭ �ؾ��Ѵ�.
ù�ڸ����� ���ӵ� 0�� �����Ѵ�.
������ �Լ��� int reverse(int x)�� �Ҽ������� Ȯ���ϴ� �Լ� bool isPrime(int x)�� �ݵ�� �ۼ��Ͽ� ���α׷��� �Ѵ�. 
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




