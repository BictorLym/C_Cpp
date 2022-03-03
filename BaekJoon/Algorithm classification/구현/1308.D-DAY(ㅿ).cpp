/******************************************************************************************
<백준 1308> D-DAY
문제
캠프에 오게 된 송유진은 캠프가 너무 지루해서 오늘로부터 캠프가 끝날 때 까지 며칠이나 남았는지 알아보고 싶었다. 그런데 캠프는 비상식적으로 길지도 몰라서 (윤년을 포함할지도 모른다) 손으로 하나하나 세기에는 힘들어 보였다.

더욱 정확한 계산을 위해, 유진이는 윤년이 정해지는 기준을 찾아보았고, 그것은 다음과 같았다.

서력기원 연수가 4로 나누어떨어지는 해는 우선 윤년으로 한다. (2004년, 2008년, …)
100으로 나누어떨어지는 해는 평년으로 한다. (2100년, 2200년, …)
400으로 나누어떨어지는 해는 다시 윤년으로 한다. (1600년, 2000년, …)
그런데 캠프가 너무 길 경우, 사춘기인 유진이는 캠프에 무단으로 빠질지도 모른다.

입력
첫째 줄에 오늘의 날짜가 주어지고, 두 번째 줄에 D-Day인 날의 날짜가 주어진다. 날짜는 연도, 월, 일순으로 주어지며, 공백으로 구분한다. 입력 범위는 1년 1월 1일부터 9999년 12월 31일 까지 이다. 오늘의 날짜는 항상 D-Day보다 앞에 있다.

출력
오늘부터 D-Day까지 x일이 남았다면, "D-"를 출력하고 그 뒤에 공백 없이 x를 출력한다. 
만약 캠프가 천년 이상 지속된다면 (오늘이 y년 m월 d일이고, D-Day가 y+1000년 m월 d일과 같거나 늦다면) 대신 "gg"를 출력한다. 
오늘이 2월 29일인 경우는 주어지지 않는다.

예제 입력 1 
2008 12 27
2009 1 22
예제 출력 1 
D-26
******************************************************************************************/

#include <iostream>

using namespace std;
int isLeap(int year);
int callDay(int year, int month, int day);
int main()
{
	int year, month, day;
	int d_year, d_month, d_day;
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	cin >> year >> month >> day;
	cin >> d_year >> d_month >> d_day;
	if(  (d_year - year> 1000) 
	|| (d_year-year == 1000 && d_month<month)
	|| (d_year-year==1000 && month==d_month && day<=d_day)  )
	{
		cout << "gg";
		return 0;
	}
	int result1, result2;
	result1 = callDay(year, month, day);
	result2 = callDay(d_year, d_month, d_day);
	int answer = result2 - result1;
	cout << "D-" << answer;
	
	return 0;
}
int callDay(int year, int month, int day)
{
	int res=0;
	int i;
	for(i = 0; i<year; i++)
	{
		res = res + (365 + isLeap(i));
	}
	for(i = 1; i<month; i++)
	{
		if		(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
		{
			res = res + 31;
		}
		else if	(i==4||i==6||i==9||i==11)
		{
			res = res + 30;
		}
		else if (i==2)
		{
			res = res + (28 + isLeap(year));
		}
	}
	res = res + day;
	return res;
}
int isLeap(int year)
{
	// if (year % 4 != 0) 		return false;
	// if (year % 100 != 0) 	return true;
	// if (year % 400 == 0) 	return true;
	// return false;
	if( (year%400==0) || (year%4==0&&year%100!=0) )	 	return 1;
	
	return 0;
}