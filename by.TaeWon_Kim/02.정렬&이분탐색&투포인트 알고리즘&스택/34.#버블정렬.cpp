/**************************************
34. 버블정렬
N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요. 
정렬하는 방법은 버블정렬입니다.
▣ 입력설명 
첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다. 
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 각 자연수는 정수형 범위 안에 있습니다. 
▣ 출력설명 
오름차순으로 정렬된 수열을 출력합니다.
▣ 입력예제 1                                  
6 
13 23 11 7 5 15
▣ 출력예제 1
5 7 11 13 15 23
***************************************/
#define CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>


void bubble_sort(int *arr, int count);
void print_array(int arr[], int count);

int main()
{
	int a[100];
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	bubble_sort(a, n);
	print_array(a, n);



	return 0;
}
void bubble_sort(int *arr, int count)
{
	int temp;
	for(int i = 0; i<count; i++)
	{
		for(int j = 0; j<count-1; j++)
		{
			if(*(arr+j)>*(arr+j+1))
			{
				temp = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = temp;
			}
		}
	}
}
void print_array(int arr[], int count)
{
	for(int i = 0; i<count; i++)	
	{
		printf("%d ", arr[i]);
	}
}
/*
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
*/
/*
void bubble_sort(int arr[], int count)
{
	int temp;
	for(int i =0 ; i<count; i++)
	{
		for(int j = 0; j<count-1; j++)
		{
			if(arr[j]<arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
*/
/*
void selection_sort(int arr[], int count)
{
	int i, j;
	for(i = 0; i<count-1; i++)
	{
		int idx = i;
		for(j = i+1; j<count; j++)
		{
			if(arr[j]>arr[idx]);
		}
		int temp;
		temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}
}
*/

/*
//정답
#include <stdio.h>
int main() {
	freopen("input.txt", "rt", stdin);
	int a[101], n, i, j, tmp;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}	
	return 0;
}
*/