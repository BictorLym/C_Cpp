

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
04. ���� ���� 
N(2<=N<=100)���� ���̰� �Էµ˴ϴ�. �� N���� ��� �� ���� �������̰� ���� ���� ���� �� ���ϱ��?
�ִ� �������̸� ����ϴ� ���α׷��� �ۼ��ϼ���. 
�Է¼���: �Է������� input.txt�� �Ѵ�.
ù �ٿ� �ڿ��� N(2<=N<=100)�� �Էµǰ�, �� ���� �ٿ� N���� ���̰� �Էµȴ�. 
��¼���: ��������� output.txt�� �Ѵ�.
ù�ٿ� �ִ� �������̸� ����մϴ�. 
***************************************/
#include <iostream>
using namespace std;
int main()
{
	//freopen("input.txt", "rt", stdin);
	int n, i, a, min = 2147000000, max = -2147000000;
	cin >> n ;
	for(i = 0; i<n; i++)
	{
		cin >> a;
		if(a>max) max = a;
		if(a<min) min = a;
	}
	cout << max - min;
	
	return 0;
}

