/**************************************
32. 선택정렬
N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
정렬하는 방법은 선택정렬입니다.

▣ 입력설명 
첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다. 두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 
각 자연수는 정수형 범위 안에 있습니다. 
▣ 출력설명 
오름차순으로 정렬된 수열을 출력합니다.

▣ 입력예제 1                                  
6 
13 5 11 7 23 15
▣ 출력예제 1
5 7 11 13 15 23
***************************************/
//#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

#define MAX_ELEMENT 214700000
int a[MAX_ELEMENT];
void bubble_sort(int arr[], int count);

int main()
{
	//freopen("input.txt", "rt", stdin);
	int a[100], n, idx, i, j, temp;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i=0; i<n-1; i++)
	{
		idx = i;
		for(j = i+1; j<n; j++)
		{
			if(a[j]<a[idx])		idx = j;
		}
		temp = a[i];
		a[i] = a[idx];
		a[idx] = temp;
	}
	for(i = 0; i<n; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}






/*
//버블정렬
int main(void)
{
	//freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	bubble_sort(a, n);
	for(int i = 0; i<n; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}
void bubble_sort(int arr[], int count)
{
	int temp;
	for(int i = 0; i<count; i++)
	{
		for(int j = 0; j<count-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
*/