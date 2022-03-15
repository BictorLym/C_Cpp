#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fibo_recursive(int n);
int fibo_iterative(int n);
void print_time(int n, const char *name, int(*func)(int));
#define N_FUNC 2
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);	cout.tie(NULL);
	//std::cout << "hello World!";
	struct {
		const char* name;
		int(*func)(int);
	}fibo[] = {
		{"fibo_recursive", fibo_recursive},
		{"fibo_iterative", fibo_iterative}
	};
	int n = 20;
	for (int i = 0; i < N_FUNC; i++)
	{
		print_time(n, fibo[i].name, fibo[i].func);
	}
	


	return 0;
}
int fibo_recursive(int n)
{
	if (n == 0)	return 0;
	else if (n == 1) return 1;
	else if (n > 1)
	{
		return fibo_recursive(n - 1) + fibo_recursive(n - 2);
	}
	return 0;
}
int fibo_iterative(int n)
{
	//int f[MAX_SIZE];
	//int* f = (int*)malloc(sizeof(int) * n);
	vector<int> f;
	//f[0] = 0;
	//f[1] = 1;
	f.push_back(0);
	f.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		//f[i] = f[i - 1] + f[i - 2];
		f.push_back(f[i - 1] + f[i - 2]);
	}
	return f[n];
}
void print_time(int n, const char* name, int(*func)(int))
{
	clock_t begin = clock();
	int fvalue1 = func(n);
	printf("f(%d) = %d\n", n, fvalue1);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	printf("%s: 경과시간은 %f(초)\n", name, elapsed_secs);


	//clock_t begin1 = clock();
	//int fvalue2 = fibo_iterative(n);
	//printf("f(%d) = %d\n", n, fvalue2);
	////cout << fvalue;
	//clock_t end1 = clock();
	//double elapsed_secs1 = double(end1 - begin1) / CLOCKS_PER_SEC;
}
/*
* //01주차 복붙
#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
int fibo_recursive(int n);
int fibo_iterative(int n);
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);	cout.tie(NULL);
	//std::cout << "hello World!";
	int n = 20;
	clock_t begin = clock();
	int fvalue1 = fibo_recursive(n);
	printf("f(%d) = %d\n", n, fvalue1);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	printf("경과시간은 %f(초)\n", elapsed_secs);


	clock_t begin1 = clock();
	int fvalue2 = fibo_iterative(n);
	printf("f(%d) = %d\n", n, fvalue2);
	//cout << fvalue;
	clock_t end1 = clock();
	double elapsed_secs1 = double(end1 - begin1) / CLOCKS_PER_SEC;

	return 0;
}
int fibo_recursive(int n)
{
	if (n == 0)	return 0;
	else if (n == 1) return 1;
	else if (n > 1)
	{
		return fibo_recursive(n - 1) + fibo_recursive(n - 2);
	}
	return 0;
}
int fibo_iterative(int n)
{
	int* f = (int*)malloc(sizeof(int)*n);
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}
*/
