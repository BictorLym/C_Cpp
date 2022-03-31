/******************************************************************************************
<백준 1157> 단어 공부


문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 
단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 
주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 
단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

예제 입력 1 
Mississipi
예제 출력 1 
?
예제 입력 2 
zZa
예제 출력 2 
Z
예제 입력 3 
z
예제 출력 3 
Z
예제 입력 4 
baaa
예제 출력 4 
A
******************************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
	string str;
	cin >> str;
	vector<int> cnt(26+1);
	int n = str.size();
	for(int i = 0; i < n; i++)
	{
		int numeric_alpha = str[i];
		if(numeric_alpha >= 65 && numeric_alpha <= 90)
			numeric_alpha = numeric_alpha - 64;
		else if (numeric_alpha >= 97 && numeric_alpha <=122)
			numeric_alpha = numeric_alpha - 96;
		cnt[numeric_alpha]++;
	}
	// for(int i = 1; i <=26; i++)
	// {
	// 	cout << cnt[i] << " ";
	// }
	//sort(cnt.begin(), cnt.end());
	int idx, max = 0;
	int idx_1, max_1 = 0;
	int check = 0;
	//bubble sort변형
	for(int i = 1; i <= 26; i++)
	{
		if(max < cnt[i])
		{
			idx=i;
			max = cnt[i];
			check = 0;
		}
		if(max == cnt[i])
		{
			check++;
		}
	}
	if(check > 1)	cout << "?";
	else			cout << (char)(idx+64);
	// max = cnt[idx];
	// sort(cnt.begin(), cnt.end());
	// idx_1 = 25;
	// max_1 = cnt[idx_1];
	// if(max==max_1)	cout << "?";
	// if(max>max_1){
	// 	char ch = idx + 64;
	// 	cout << ch;
	// }	
	return 0;
}

