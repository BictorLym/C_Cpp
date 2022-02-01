

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
13. 가장 많이 사용된 자릿수
N자리의 자연수가 입력되면 입력된 자연수의 자릿수 중 가장 많이 사용된 숫자를 출력하는 프로그램을 작성하세요.
예를 들어, 1230565625라는 자연수가 입력되면 5가 3번 상용되어 가장 많이 사용된 숫자입니다.
답이 여러 개일 경우 그 중 가장 큰 수를 출력하세요. 
 ***************************************/
#include <stdio.h>
//using namespace std;
int ch[10];
int main()
{
	//freopen("input.txt", "rt", stdin);s
	int i, digit, max = -2147000000, res;
	char a[101];
	scanf("%s", &a);
	for(i = 0; a[i]!='\0';i++)
	{
		digit = a[i]-48;
		ch[digit]++;
	}
	for(i = 0; i<=9; i++)
	{
		if(ch[i]>=max)
		{
			max = ch[i];
			res = i;
		}
	}
	printf("%d\n", res);
	return 0;
}














/*
void bubble_sort(int arr[], int count)    // 매개변수로 정렬할 배열과 요소의 개수를 받음
{
    int temp;

    for (int i = 0; i < count; i++)    // 요소의 개수만큼 반복
    {
        for (int j = 0; j < count - 1; j++)   // 요소의 개수 - 1만큼 반복
        {
            if (arr[j] > arr[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
            {                                 // 큰 값을
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;            // 다음 요소로 보냄
            }
        }
    }
}
int main()
{
	//freopen("input.txt", "rt", stdin);
	int n, a;
	int cnt[9] = {0,};
	scanf("%d", &n);
	int i;
	while(i>0)
	{
		i = n;
		a = i%10;
		switch(a)
		{
			case(0):
				cnt[0] = cnt[0] + 1;
				break;
			case(1):
				cnt[1] = cnt[1] + 1;
				break;
			case(2):
				cnt[2] = cnt[2] + 1;
				break;
			case(3):
				cnt[3] = cnt[3] + 1;
				break;
			case(4):
				cnt[4] = cnt[4] + 1;
				break;
			case(5):
				cnt[5] = cnt[5] + 1;
				break;
			case(6):
				cnt[6] = cnt[6] + 1;
				break;
			case(7):
				cnt[7] = cnt[7] + 1;
				break;
			case(8):
				cnt[8] = cnt[8] + 1;
				break;
			case(9):
				cnt[9] = cnt[9] + 1;
				break;
		}
		i = i/10;
	}
	bubble_sort(cnt, 10);
	printf("%d", cnt[9]);
	return 0;
}
*/
