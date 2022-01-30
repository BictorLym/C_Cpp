

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
05. 나이 계산 
주민등록증의 번호가 주어지면 주민등록증 주인의 나이와 성별을 판단하여 출력하는 프로그램을 작성하세요.
주민등록증의 번호는 -를 기준으로 앞자리와 뒷자리로 구분된다.
뒷자리의 첫 번째 수가 1이면 1900년대생 남자이고, 2이면 1900년대생 여자, 3이면 2000년대생 남자, 4이면 2000년대생 여자이다.
올해는 2019년입니다. 해당 주민등록증 주인의 나이와 성별을 출력하세요 
입력설명: 첫 줄에 주민등록증 번호가 입력됩니다. 
출력설명: 첫 줄에 나이와 성별을 공백을 구분으로 출력하세요. 성별은 남자M(man), 여자는 W(Woman)로 출력한다. 
첫줄에 최대 나이차이를 출력합니다. 
***************************************/
#include <stdio.h>
using namespace std;

int main(){
	//freopen("input.txt", "rt", stdin);
	char a[20];
	int year, age;
	scanf("%s", &a);
	if(a[7]=='1' || a[7]=='2') year=1900+((a[0]-48)*10+(a[1]-48));
	else year=2000+((a[0]-48)*10+(a[1]-48));
	age=2019-year+1;
	printf("%d ", age);
	if(a[7]=='1' || a[7]=='3') printf("M\n");
	else printf("W\n");
	return 0;
}

