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