

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
12. 숫자의 총 개수(large)
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였을까요?
예를 들어 1부터 15까지는 1,2,3,4,5,6,7,8,9,1,0,1,1,1,2,1,3,1,4,1,5으로 총 21개가 쓰였음을 알 수 있습니다.
자연수 N이 입력되면 1부터 N까지의 각 숫자는 몇개가 사용되었는지를 구하는 프로그램을 작성하세요. 
 ***************************************/
#include <stdio.h>
//using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);
	/**************
	index는 첫째 자리, 둘쨰 자리, 셋째 자리......
	cnt는 순수한 첫째자리 갯수(9개), 순수한 둘째자리 갯수(90개),  순수한 셋째자리 개수(900개)....... 
	max은 cnt를 통해  첫째자리 최대개수(9개), 둘째자리 최대갯수(99개), 셋째자리 갯수(999개) ..........
	res = 1*9 + 2*90 + 3*900 + .....
	***************/
	int n, index = 1, cnt = 9, max = 0, res = 0;
	scanf("%d", &n);
	while(max+cnt<n)
	{
		res = res + (index*cnt);
		max = max + cnt;
		index++;
		cnt = cnt * 10;
	}
	res = res + index*(n-max);
	printf("%d", res);
	return 0;
	
	
	
}
