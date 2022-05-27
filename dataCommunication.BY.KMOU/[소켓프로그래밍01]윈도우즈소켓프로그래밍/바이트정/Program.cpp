#include<WinSock2.h>
#pragma comment(lib, "ws2_32")
#include<stdio.h>

int main() {
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);

	u_int idata = 0x12345678;
	u_short sdata = 0x1234;
	printf("host:%#x network:%#x\n", idata, htonl(idata));
	printf("host:%#x network:%#x\n", sdata, htons(sdata));

	WSACleanup();
	return 0;
}