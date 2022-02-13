/**************************************
수행시간 측정방법
***************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ELEMENT 214700000

int main()
{
    clock_t start, stop;
    double duration;
    start = clock();

    for (int i = 0; i < MAX_ELEMENT; i++)
    {
        ;
    }
    stop = clock();

    duration = (double)(stop - start);
    printf("수행시간은%f초입니다.\n",duration);
    

    return 0;
}