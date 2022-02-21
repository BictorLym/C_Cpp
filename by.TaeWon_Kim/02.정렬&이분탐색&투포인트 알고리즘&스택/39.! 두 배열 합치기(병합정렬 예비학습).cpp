/**************************************
39. 두 배열 합치기
오름차순으로 정렬이 된 두 배열이 주어지면 두 배열을 오름차순으로 합쳐 출력하는 프로그램 을 작성하세요.
▣ 입력설명 
첫 번째 줄에 첫 번째 배열의 크기 N(1<=N<=100)이 주어집니다. 
두 번째 줄에 N개의 배열 원소가 오름차순으로 주어집니다. 
세 번째 줄에 두 번째 배열의 크기 M(1<=M<=100)이 주어집니다. 
네 번째 줄에 M개의 배열 원소가 오름차순으로 주어집니다. 
각 배열의 원소는 int형 변수의 크기를 넘지 않습니다.
▣ 출력설명 
오름차순으로 정렬된 배열을 출력합니다.
▣ 입력예제 1                                  
3 
1 3 5 
5 
2 3 6 7 9
▣ 출력예제 1
1 2 3 3 5 6 7 9
***************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
void print_array(int *arr, int count);
int main()
{
	int n, m, i, j;
	scanf("%d", &n);
	int *arr1 = (int *)malloc(sizeof(int)* n);
	for(i = 0; i<n; i++)
	{
		scanf("%d", &arr1[i]);
	}
	
	scanf("%d", &m);
	int *arr2 = (int *)malloc(sizeof(int) * m);
	for(j = 0; j<m; j++ )
	{
		scanf("%d", &arr2[j]);
	}
	
	int *res_arr = (int *)malloc(sizeof(int) * (n+m));
	int p1=0, p2=0, p3=0;
	while(p1<n&&p2<m)
	{
		if(arr1[p1]<arr2[p2])	res_arr[p3++] = arr1[p1++];
		else					res_arr[p3++] = arr2[p2++];
	}
	while(p1<n)				res_arr[p3++] = arr1[p1++];
	while(p2<m)				res_arr[p3++] = arr2[p2++];

	print_array(res_arr, n+m);
	return 0;
}
void print_array(int *arr, int count)
{
	for(int i =0; i<count; i++)
	{
		printf("%d ", arr[i]);
	}
}