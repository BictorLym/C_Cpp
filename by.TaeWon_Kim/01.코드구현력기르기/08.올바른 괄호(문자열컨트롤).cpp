

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
08. 올바른 괄호 

괄호가 입력되면 올바른 괄호이면 "YES", 올바르지 않으면 "NO"를 출력합니다.
(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다. 
***************************************/
#include <stdio.h>
using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);
	char a[29] ;
	//gets(a);
	scanf("%s", &a);
	int cnt = 0;
	
	for(int i = 0; a[i]!='\0' ; i++)
	{
		if( a[i]=='(' )		cnt++;
		else if	(a[i]==')')	cnt--;
		if(cnt<0)			break;
	}
	if(cnt == 0)	printf("%s", "YES");
	else			printf("%s", "NO");
	return 0;
}

