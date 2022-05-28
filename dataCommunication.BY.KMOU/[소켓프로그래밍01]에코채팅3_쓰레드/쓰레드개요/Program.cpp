#include<iostream>
using namespace std;
#include<process.h>
#include<Windows.h>
void ProcA(void* param) {
	for (int i = 0; i < 100; i++) {
		Sleep(rand() % 100);
		cout << "A" << i << endl;
	}
}
void ProcB(void* param) {
	for (int i = 0; i < 100; i++) {
		Sleep(rand() % 100);
		cout << "B" << i << endl;
	}
}
int main()
{
	//ProcA(0);
	//ProcB(0);
	_beginthread(ProcA, 0, 0);
	_beginthread(ProcB, 0, 0);

	for (int i = 0; i < 200; i++) {
		Sleep(rand() % 100);
		cout << "main" << i << endl;
	}
	return 0;
}