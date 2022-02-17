/**************************************
35. Special Sort(구글 인터뷰)
N개의 정수가 입력되면 당신은 입력된 값을 정렬해야 한다. 
음의 정수는 앞쪽에 양의정수는 뒷쪽에 있어야 한다. 
또한 양의정수와 음의정수의 순서에는 변함이 없어야 한다.
▣ 입력설명 
첫 번째 줄에 정수 N(5<=N<=100)이 주어지고, 그 다음 줄부터 음수를 포함한 정수가 주어진다. 숫자 0은 입력되지 않는다.
▣ 출력설명 
정렬된 결과를 출력한다.
▣ 입력예제 1                                  
8 
1 2 3 -3 -2 5 6 -6
▣ 출력예제 1
-3 -2 -6 1 2 3 5 6
***************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

void special_sort(int *arr, int n);
void print_array(int *arr, int n);
int main()
{
	int n;
	scanf("%d", &n);
	int a[101];
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	special_sort(a, n);
	print_array(a, n);

	return 0;
}
void special_sort(int *arr, int n)
{
	int neg_tmp[101];
	int a = 0;
	for(int i = 0; i<n; i++)
	{
		if(*(arr+i)<0)
		{
			neg_tmp[a] = *(arr+i);
			*(arr+i) = -1;
			a++;
		}
	}
	int pos_tmp[101];
	int b = 0;
	for(int i = 0; i<n; i++)
	{
		if(*(arr+i)>0)
		{
			pos_tmp[a] = *(arr+i);
			*(arr+i) = 1;
			a++;
		}
	}
	//버블정렬
	for(int i = 0; i<n; i++)
	{
		int temp;
		for(int j = 0; j<n-1; j++)
		{
			if( *(arr+j) > *(arr+j+1) )
			{
				temp = *(arr+j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
	int i = 0;
	while(*(arr+i)==-1)
	{
		*(arr+i) = neg_tmp[i];
		i++;
	}
	while(*(arr+i)==1)
	{
		*(arr+i) = pos_tmp[i];
		i++;
	}
}

void print_array(int *arr, int n)
{
	for(int i =0; i<n; i++)
	{
		printf("%d ", *(arr+i));
	}
}
/*
//정답
#include<stdio.h>
int main() {
	freopen("input.txt", "rt", stdin);
	int a[101], n, tmp, min, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(a[j]>0 && a[j+1]<0){
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












#include<stdio.h>
void Special_Sort(int temp[], int len){
	int i, j, t;
	for(i=0; i<len; i++){
		for(j=0; j<len-i-1; j++){
			if(temp[j]>0 && temp[j+1]<0){
				t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
		}	
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int n, i;
	scanf("%d", &n);
	int *a=new int[n];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	Special_Sort(a, n);
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	delete[] a;
	return 0;
}

*/



/*
//틀림
void special_sort(int *arr, int n)
{
	
	int neg_tmp[101];
	int k = 0;
	for(int i = 0; i<n; i++)
	{
		if(*(arr+i)<0)
		{
			neg_tmp[k] = *(arr+i);
			*(arr+i) = 0;
			k++;
		}
	}
	//버블정렬
	for(int i = 0; i<n; i++)
	{
		int temp;
		for(int j = 0; j<n-1; j++)
		{
			if( *(arr+j) > *(arr+j+1) )
			{
				temp = *(arr+j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
	
	int i = 0;
	while(*(arr+i)==0)
	{
		*(arr+i) = neg_tmp[i];
		i++;
	}

}
*/