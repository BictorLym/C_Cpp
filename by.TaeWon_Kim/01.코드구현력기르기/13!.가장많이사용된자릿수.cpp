

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
13. ���� ���� ���� �ڸ���
N�ڸ��� �ڿ����� �ԷµǸ� �Էµ� �ڿ����� �ڸ��� �� ���� ���� ���� ���ڸ� ����ϴ� ���α׷��� �ۼ��ϼ���.
���� ���, 1230565625��� �ڿ����� �ԷµǸ� 5�� 3�� ���Ǿ� ���� ���� ���� �����Դϴ�.
���� ���� ���� ��� �� �� ���� ū ���� ����ϼ���. 
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
void bubble_sort(int arr[], int count)    // �Ű������� ������ �迭�� ����� ������ ����
{
    int temp;

    for (int i = 0; i < count; i++)    // ����� ������ŭ �ݺ�
    {
        for (int j = 0; j < count - 1; j++)   // ����� ���� - 1��ŭ �ݺ�
        {
            if (arr[j] > arr[j + 1])          // ���� ����� ���� ���� ����� ���� ���Ͽ�
            {                                 // ū ����
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;            // ���� ��ҷ� ����
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
