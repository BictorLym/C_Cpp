

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
08. �ùٸ� ��ȣ 

��ȣ�� �ԷµǸ� �ùٸ� ��ȣ�̸� "YES", �ùٸ��� ������ "NO"�� ����մϴ�.
(())() �̰��� ��ȣ�� ���� �ùٸ��� ��ġ�ϴ� ������, (()()))�� �ùٸ� ��ȣ�� �ƴϴ�. 
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

