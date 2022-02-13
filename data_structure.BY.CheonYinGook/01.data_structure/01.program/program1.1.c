/**************************************
최고 성적을 구하는 프로그램을 작성하세요.
배열 scores가 자료구조, 변수 largest를 첫 번째 요소로 초기화하라
***************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_ELEMENT 214700000
int scores[MAX_ELEMENT];
int get_max_score(int n);
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &scores[i]);
    }
    int res;
    res = get_max_score(n);

    printf("%d", res);
}
int get_max_score(int n)    //n은 학생의 수
{
    int largest = -2147000000;

    for (int i = 0; i < n; i++)
    {
        if (largest < scores[i])
        {
            largest = scores[i];
        }
    }

    return largest;
}