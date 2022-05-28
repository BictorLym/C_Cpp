#include<WinSock2.h>
#pragma comment(lib, "ws2_32")
#include<iostream>
using namespace std;
#include<process.h>
#include<Windows.h>
#pragma warning(disable:4996)
IN_ADDR GetDefaultMyIP();
#define PORT_NUM	10200
#define BLOG_SIZE	5
#define MAX_MSG_LEN 256
SOCKET SetTCPServer(short pnum, int blog);
void AcceptLoop(SOCKET sock);
//void DoIt(SOCKET dosock);
void DoIt(void* param);
int main() {
	//윈속 초기화
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);

	//소켓 셋업
	SOCKET serverSock = SetTCPServer(PORT_NUM, BLOG_SIZE);

	//ACCEPT
	AcceptLoop(serverSock);
	//소켓 해제
	closesocket(serverSock);
	//윈속 해제
	WSACleanup();
	return 0;
}
SOCKET SetTCPServer(short pnum, int blog)
{
	//소켓 생성
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//서버주소
	SOCKADDR_IN servAddr = { 0, };
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr = GetDefaultMyIP();
	servAddr.sin_port = htons(pnum);

	int re = 0;
	//네트워크 인터페이스와 소켓 결합
	bind(sock, (SOCKADDR*)&servAddr, sizeof(servAddr));
	if (re == -1) {
		return -1;	//-1=>0xFFFFFFFF => SOCKET_ERROR
	}
	//백로그 큐 크기 설정
	re = listen(sock, blog);
	if (re == -1) {
		return -1;	//-1=>0xFFFFFFFF => SOCKET_ERROR
	}
	printf("%s:%d Setup\n", inet_ntoa(servAddr.sin_addr), pnum);
	return sock;
}
void AcceptLoop(SOCKET sock)
{
	SOCKET dosock;
	SOCKADDR_IN clientAddr = { 0, };
	int len = sizeof(clientAddr);
	while (1) {
		//연결 수락
		dosock = accept(sock, (SOCKADDR*)&clientAddr, &len);
		if (dosock == -1) {
			perror("accept 실패");
			break;
		}
		printf("%s:%d의 연결 요청 수락\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
		//DoIt(dosock);
		_beginthread(DoIt, 0, (void*)dosock);
	}
}
//void DoIt(SOCKET dosock)
void DoIt(void* param)
{
	SOCKET dosock = (SOCKET)param;
	SOCKADDR_IN cliaddr = { 0 };
	int len = sizeof(cliaddr);
	getpeername(dosock, (SOCKADDR*)&cliaddr, &len);
	char msg[MAX_MSG_LEN] = "";
	int cnt = 0;
	char msg1[10];
	char msg2[22];
	char msg3[MAX_MSG_LEN]="";
	
	while (recv(dosock, msg3, sizeof(msg3), 0) > 0)
	{
		cnt++;
		itoa(cnt, msg1, 10);
		strcpy(msg2, "th message received: ");

		strcat(msg, msg1);
		strcat(msg, msg2);
		strcat(msg, msg3);
		printf("%s(%s:%d로부터 )\n", msg, inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
		//클라이언트로 송신
		send(dosock, msg, sizeof(msg), 0);
		
		strcpy(msg1, "");
		strcpy(msg2, "");
		strcpy(msg3, "");
		strcpy(msg, "");
	}
	//while (recv(dosock, msg3, sizeof(msg3), 0) > 0)
	//{
	//	cnt++;
	//	
	//	printf("%dth message received :%s(%s:%d로부터 )\n",
	//		cnt,
	//		msg3,
	//		inet_ntoa(cliaddr.sin_addr),
	//		ntohs(cliaddr.sin_port)
	//	);
	//	//클라이언트로 송신
	//	send(dosock, msg3, sizeof(msg3), 0);
	//}
	printf("%s:%d와 통신 종료:%s\n",
		inet_ntoa(cliaddr.sin_addr),
		ntohs(cliaddr.sin_port),
		msg3);
	closesocket(dosock);
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