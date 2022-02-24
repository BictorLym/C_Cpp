/**************************************
42. 이분검색
임의의 N개의 숫자가 입력으로 주어집니다. 
N개의 수를 오름차순으로 정렬한 다음 N개의 수 중 한 개의 수인 M이 주어지면 
이분검색으로 M이 정렬된 상태에서 몇 번째에 있는지 구하는 프로그램을 작성하세요.

▣ 입력설명 
첫 줄에 한 줄에 자연수 N(3<=N<=1,000,000)과 M이 주어집니다. 두 번째 줄에 N개의 수가 공백을 사이에 두고 주어집니다.
▣ 출력설명 
첫 줄에 정렬 후 M의 값의 위치 번호를 출력한다.

▣ 입력예제 1                                  
8 32
23 87 65 12 57 32 99 81
▣ 출력예제 1
3
***************************************/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m, i, idx = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	vector<int> a(n);
	for(i =0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());

	//12 23 32 57 65 81 87 99
	//for(idx = 0; a[idx]<m; idx++)	//틀림
	while(a[idx]<m)
	{
		++idx;
	}
	printf("%d", idx+1);

	return 0;
}
/*
//정답
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, i, key, lt=0, rt, mid, tmp;
	scanf("%d %d", &n, &key);
	vector<int> a;
	for(i=0; i<n; i++){
		scanf("%d", &tmp);
		a.push_back(tmp);	
	}
	sort(a.begin(), a.end());
	rt=n-1;
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(a[mid]==key){
			printf("%d\n", mid+1);
			return 0;
		}
		else if(a[mid]>key) rt=mid-1;
		else lt=mid+1;
	}
	return 0;
}
*/