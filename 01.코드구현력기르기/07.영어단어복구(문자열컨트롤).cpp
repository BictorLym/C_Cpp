

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/**************************************
07. ����ܾ� ����

������ ��ǻ�Ͱ� ���̷����� �ɷ� ����ܾ �پ��� ��ҹ��ڰ� ȥ�յǾ� ǥ���ȴ�.
���� ��� �Ƹ��ٿ� �̶� ���� ������ �ִ� beautiful �ܾ "bE au T I fu   L "�� ���� ��ǻ�Ϳ� ǥ�õǰ� �ֽ��ϴ�.
���� ���� ������ ǥ�õǴ� ����ܾ ������ ǥ����� ������ �����ϰ� �ҹ���ȭ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
***************************************/
#include <stdio.h>
using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);
	char a[100], b[100];
	int p=0;
	gets(a);
	//scanf("%s", &a);
	for(int i = 0; a[i]!='\0' ; i++)
	{
		if(a[i] != ' ')
		{
			if (a[i] >= 65 && a[i] <= 90){
				b[p++]=a[i]+32;
			}
			else b[p++]=a[i];
		}
		
		/*
		if(a[i]!=' ')
		{
			if (a[i] >= 97 && a[i] <= 122)	printf("%c", a[i]);
			else if (a[i] >= 65 && a[i] <= 90)	printf("%c", a[i] + 32);
			else;
		}
		*/
	}
	b[p]='\0';
	printf("%s\n",b );
	return 0;
}

