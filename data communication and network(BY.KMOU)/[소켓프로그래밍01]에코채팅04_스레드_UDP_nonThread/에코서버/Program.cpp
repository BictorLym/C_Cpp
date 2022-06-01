#include<Winsock2.h>
#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)
#include<stdio.h>
#include<iostream>
#include<process.h>
#include<Windows.h>
#include <thread>
using namespace std;
#define PORT_NUM	10200
#define BLOG_SIZE	5
#define BUF_SIZE	256

IN_ADDR GetDefaultMyIP();
SOCKET SetUDPServer(short pnum, int blog);
void CommunicationLoop(SOCKET sock);
//void DoIt(SOCKET sock);
//void DoIt(void* param);
int main() {
	//윈속초기화
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	//소켓 셋업
	SOCKET serverSock = SetUDPServer(PORT_NUM, BLOG_SIZE);
	//전송
	CommunicationLoop(serverSock);
	//소켓해제
	closesocket(serverSock);
	//윈속해제
	WSACleanup();

	return 0;
}

void CommunicationLoop(SOCKET sock)
{
	char msg[BUF_SIZE] = "";
	int cnt = 0;
	char msg1[10];
	char msg2[22];
	char msg3[BUF_SIZE] = "";
	SOCKADDR_IN clientAddr = { 0, };
	int len = sizeof(clientAddr);
	while (true) {
		
		while (recvfrom(sock, msg3, sizeof(msg3),
			0, (SOCKADDR*)&clientAddr, &len) > 0) 
		{
			cnt++;
			itoa(cnt, msg1, 10);
			strcpy(msg2, "th message received: ");

			strcat(msg, msg1);
			strcat(msg, msg2);
			strcat(msg, msg3);
			printf("%s(%s:%d로부터 )\n", msg, inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

			//클라이언트로 송신
			sendto(sock, msg, sizeof(msg), 0, (SOCKADDR*)&clientAddr, len);

			strcpy(msg1, "");
			strcpy(msg2, "");
			strcpy(msg3, "");
			strcpy(msg, "");
		}
		printf("%s:%d와 통신 종료:%s\n",
			inet_ntoa(clientAddr.sin_addr),
			ntohs(clientAddr.sin_port),
			msg3);
		break;
	}
}
SOCKET SetUDPServer(short pnum, int blog)
{
	//소켓 생성
	SOCKET sock;
//	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	//서버주소
	SOCKADDR_IN servAddr = { 0, };
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(pnum);
	servAddr.sin_addr = GetDefaultMyIP();
	//네트워크 인터페이스와 소켓 결합
	if (bind(sock, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		perror("소켓에러"); 
		exit(1);
	}
	printf("%s:%d Setup\n", inet_ntoa(servAddr.sin_addr), pnum);
	return sock;
}
IN_ADDR GetDefaultMyIP()
{
	char localhostname[MAX_PATH];
	IN_ADDR addr = { 0, };
	if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR) {
		printf("error");
		return addr;
	}
	HOSTENT* ptr = gethostbyname(localhostname);
	while (ptr && ptr->h_name) {
		if (ptr->h_addrtype == PF_INET) {
			memcpy(&addr, ptr->h_addr_list[0], ptr->h_length);
			break;
		}
		ptr++;
	}
	return addr;
}


//void DoIt(SOCKET dosock)

//void DoIt(void* param)
//{
//	SOCKET dosock = (SOCKET)param;
//	SOCKADDR_IN cliaddr = { 0 };
//	int len = sizeof(cliaddr);
//	getpeername(dosock, (SOCKADDR*)&cliaddr, &len);
//	char msg[BUF_SIZE] = "";
//	int cnt = 0;
//	char msg1[10];
//	char msg2[22];
//	char msg3[BUF_SIZE] = "";
//	int buf_len = recvfrom(dosock, msg3, sizeof(msg3), 0, (SOCKADDR*)&cliaddr, &len);
//	while (1)
//	{
//		//printf("debugging");
//		if (buf_len >= 0) {
//			cnt++;
//			itoa(cnt, msg1, 10);
//			strcpy(msg2, "th message received: ");
//
//			strcat(msg, msg1);
//			strcat(msg, msg2);
//			strcat(msg, msg3);
//			printf("%s(%s:%d로부터 )\n", msg, inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
//			//클라이언트로 송신
//			sendto(dosock, msg, sizeof(msg), 0, (SOCKADDR*)&cliaddr, len);
//
//			strcpy(msg1, "");
//			strcpy(msg2, "");
//			strcpy(msg3, "");
//			strcpy(msg, "");
//
//		}
//
//	}
//
//	printf("%s:%d와 통신 종료:%s\n",
//		inet_ntoa(cliaddr.sin_addr),
//		ntohs(cliaddr.sin_port),
//		msg3);
//	closesocket(dosock);
//}