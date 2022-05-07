#include"schedule.h"
/*3 # 40
3 # 15
1 # 35
1 # 20
1 # 30
3 # 25
2 # 10*/
void schedule(int n, vector<Job> jobs, int J[]);
int feasible(int J[], int deadline);
void print_schedule(int J[], int n);
int main() {
	const char* fname = "edges.txt";;
	vector<Job> jobs = read_edges(fname);
	print_job(jobs);
	cout << "\n-----------스케줄링알고리즘-----------------" << "\n";	
	int n = jobs.size();
	//int J[7] = { -1, };
	int* J = (int*)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i < n + 1; i++) {
		J[i] = -1;
	}

	schedule(n, jobs, J);
	print_schedule(J, n);
	cout << "===============================================" << "\n";

	return 0;
}
void schedule(int n, vector<Job> jobs, int J[])
{
	//J[0] = 1;
	sort(jobs.begin(), jobs.end(), cmp);
	print_job1(jobs);
	int tmp = stoi(jobs[0].get_deadline());
	J[tmp] = 0;
	for (int i = 1; i < n; i++) {
		tmp = stoi(jobs[i].get_deadline());
		int loc = feasible(J, tmp);
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

void print_schedule(int J[], int n)
{
	int i = 1;
	while (J[i] >= 0) {
		printf("작업번호:%d ", J[i]);
		i++;
	}
	printf("\n");
}

