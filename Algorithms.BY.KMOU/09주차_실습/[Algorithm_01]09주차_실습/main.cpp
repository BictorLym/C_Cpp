#include<iostream>
#include<string>
#include<vector>
#include"edge.h"
using namespace std;


typedef struct job {
	int deadline;
	int profit;
}JOB;
void schedule(int n, JOB jobs[], int J[]);
void print_schedule(int J[], int n);

int feasible(int J[], int deadline);
#define N 7
int main() {
	JOB jobs[] = {
		{ 3, 40 }, { 1, 35 }, { 1, 30 }, { 3, 25 },
		{ 1, 20 }, { 3, 15 }, { 2, 10 }
	};
	int n = N;
	//int J[7] = { -1, };
	int J[N+1];
	for (int i = 0; i < N+1; i++) {
		J[i] = -1;
	}
	schedule(n, jobs, J);
	print_schedule(J, n);

	

	


	return 0;
}
void print_schedule(int J[], int n)
{
	int i = 1;
	while (J[i] >= 0) {
		printf("%d ", J[i]);
		i++;
	}
	printf("\n");
}
void schedule(int n, JOB jobs[], int J[])
{
	//J[0] = 1;
	J[jobs[0].deadline] = 0;
	for (int i = 1; i < n; i++) {
		int loc = feasible(J, jobs[i].deadline);
		//feasible üũ
		if (loc >= 0) {
			J[loc] = i;
		}
	}
}
int feasible(int J[], int deadline)
{
	for (int loc = deadline; loc > 0; loc--) {
		if (J[loc] < 0)	return loc;
	}
	return -1;
}