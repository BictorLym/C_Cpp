/**************************************
30. 3의 개수는?(large)
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자 중 3의 개수가 몇 개 있는지 구하려고 합니다. 
예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로 3의 개수는 2개입니다. 
자연수 N이 입력되면 1부터 N까지 숫자를 적을 때, 3의 개수가 몇 개인지 구하여 출력하는 프로그램을 작성하세요.
▣ 입력설명 
첫 줄에 자연수의 개수 N(3<=N<=1,000,000,000)이 주어집니다.
▣ 출력설명 
3의 개수를 출력하세요.
▣ 입력예제 1                                  
15
▣ 출력예제 1
2
***************************************/
#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;



int main(void)
{
	//freopen("input.txt", "rt", stdin);
	int n, left=77, right, cur, cnt = 0, k = 1;
	scanf("%d", &n);
	while(left!=0)
	{
		left = n/(k*10);
		right = n%k;
		cur = (n/k)%10;

		if(cur>3)
		{
			cnt = cnt + ((left+1) * k);
		}
		else if(cur == 3)
		{
			cnt = cnt + ((left*k) + (right+1));
		}
		else if(cur<3)
		{
			cnt = cnt + (left * k);
		}
		k = k*10;
	}


	printf("%d", cnt);

	return 0;
}

/*
//틀림
int main()
{
	//freopen("input.txt", "rt", stdin);
	int n, cnt = 1, digit = 0, most_left_number;
	scanf("%d", &n);
	int temp = n;
	while(temp>0)
	{
		//temp = n;
		temp = temp/10;
		digit++;
	}
	//digit = digit - 1;
	if(digit == 1)
	{
		if(n<3)			cnt = 0;
		else if(n>=3)	cnt = 1;	
	}
	else if(digit > 1)
	{
		for(int i = 1; i<digit-1; i++)
		{
			cnt = cnt + cnt*9 + pow(10, i);
		}
		most_left_number = n / (10 * (cnt - 1));

		if(most_left_number == 1 || most_left_number == 2 || most_left_number == 3)
		{
			cnt = cnt + cnt*(most_left_number - 1);

			int original_of_most_left_number = most_left_number * pow(10, digit);

			for(int i = original_of_most_left_number; i<=n; i++)
			{
				temp = i;
				while(1)
				{
					if(temp%10 == 3)	cnt ++;

					temp = temp/10;
					if(temp == 0)	break;
				}
			}
		}
		else if(most_left_number>3)
		{
			cnt = cnt + cnt * (most_left_number - 1) + pow(10, digit);

			int original_of_most_left_number = most_left_number * pow(10, digit);

			for(int i = original_of_most_left_number; i<=n; i++)
			{
				temp = i;
				while(1)
				{
					if(temp%10 == 3)	cnt ++;

					temp = temp/10;
					if(temp == 0)	break;
				}
			}
		}
	}

	printf("%d", cnt);

	return 0;
}

*/