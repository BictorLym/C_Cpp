/**************************************
36. 삽입정렬
N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요. 
정렬하는 방법은 삽입정렬입니다.

▣ 입력설명 
첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다. 
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 
각 자연수는 정수형 범위 안에 있습니다. 

▣ 출력설명 
오름차순으로 정렬된 수열을 출력합니다.

▣ 입력예제 1                                  
6 
11 7 5 6 10 9
▣ 출력예제 1
5 6 7 9 10 11
***************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

void insertion_sort(int *arr, int n);
void print_array(int *arr, int n);
int main()
{
	int n;
	scanf("%d", &n);
	int a[100];
	for(int i =0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	insertion_sort(a, n);
	print_array(a, n);

	return 0;
}
void insertion_sort(int *arr, int n)
{
	int i, j, temp;

	for(i = 0; i<n; i++)
	{
		temp = *(arr+i);
		for(j = i-1; j>=0; j--)
		{
			if( *(arr+j) > temp )
			{
				*(arr+j+1) = *(arr+j);
			}
			else break;
		}
		*(arr+j+1) = temp;
	}

}
void print_array(int *arr, int n)
{
	for(int i = 0; i<n ; i++)
	{
		printf("%d ", *(arr+i));
	}
}

/*
//정답
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int a[100], n, tmp, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=1; i<n; i++){
		tmp=a[i];
		for(j=i-1; j>=0; j--){
			if(a[j]>tmp) a[j+1]=a[j];
			else break;
		}
		a[j+1]=tmp;
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}	
	return 0;
}
*/