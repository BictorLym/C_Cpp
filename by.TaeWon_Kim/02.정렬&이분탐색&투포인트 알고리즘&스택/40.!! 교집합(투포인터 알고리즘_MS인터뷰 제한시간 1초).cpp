/**************************************
40. 교집합(투포인터 알고리즘)
두 집합 A, B가 주어지면 두 집합의 교집합을 출력하는 프로그램을 작성하세요.
▣ 입력설명 
첫 번째 줄에 집합 A의 크기 N(1<=N<=30,000)이 주어집니다. 
두 번째 줄에 N개의 원소가 주어집니다. 
원소가 중복되어 주어지지 않습니다. 
세 번째 줄에 집합 B의 크기 M(1<=M<=30,000)이 주어집니다. 
네 번째 줄에 M개의 원소가 주어집니다. 
원소가 중복되어 주어지지 않습니다. 
각 집합의 원소는 int형 변수의 크기를 넘지 않습니다.
▣ 출력설명
두 집합의 교집합을 오름차순 정렬하여 출력합니다.

▣ 입력예제 1                                  
5 
2 7 10 5 3
5 
3 10 5 17 12
▣ 출력예제 1
3 5 10
***************************************/
#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//void ascending_sort(int *arr, int count);
void print_array(vector<int> const &input, int count);
int main()
{
	int n, m, i , j;
	scanf("%d", &n);
	//int* A = (int*)malloc(sizeof(int)*n);
	vector<int> A(n);
	for(i=0; i<n;i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A.begin(), A.end());
	

	scanf("%d", &m);
	//int* B = (int*)malloc(sizeof(int)*m);
	vector<int> B(m);
	for(i=0; i<m;i++)
	{
		scanf("%d", &B[i]);
	}
	sort(B.begin(), B.end());
	

	vector<int> C(n+m);
	int pos1 = 0, pos2 = 0, pos3 = 0;

	while(pos1<n && pos2<m)
	{
		if(A[pos1] == B[pos2])
		{
			C[pos3++] = A[pos1++];
			pos2++;
		}
		else if(A[pos1] < B[pos2])	pos1++;
		else if(A[pos1] > B[pos2])	pos2++;
	}
	//print_array(A, n);
	//print_array(B, m);
	print_array(C, pos3);
	return 0;
}

void print_array(vector<int> const &input, int count)
{
	for(int i =0; i<count; i++)
	{
		cout<<input.at(i) <<' ';
	}
}
/*
void ascending_sort(int *arr, int count)
{

}
void print_array(vector<int> *arr, int count)
{
	for(int i = 1; i<=count; i++)
	{
		printf("%d ", (arr+i));
	}
}
*/