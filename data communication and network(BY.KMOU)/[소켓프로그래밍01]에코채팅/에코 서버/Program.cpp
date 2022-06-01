#include<WinSock2.h>
#pragma comment(lib, "ws2_32")
#include<stdio.h>
#pragma warning(disable:4996)
IN_ADDR GetDefaultMyIP();
#define PORT_NUM	10200
#define BLOG_SIZE	5
#define MAX_MSG_LEN 256
SOCKET SetTCPServer(short pnum, int blog);
void AcceptLoop(SOCKET sock);
void DoIt(SOCKET dosock);
int main() {
	//윈속 초기화
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);

	//소켓 셋업
	SOCKET serverSock = SetTCPServer(PORT_NUM, BLOG_SIZE);

	//ACCEPT

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
		printf("%s:%d의 연결 요청 수락", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
		DoIt(dosock);
	}
}
void DoIt(SOCKET dosock)
{
	char msg[MAX_MSG_LEN] = "";
	while (recv(dosock, msg, sizeof(msg), 0) > 0) 
	{
		printf("recv:%s\n", msg);
		send(dosock, msg, sizeof(msg), 0);
	}
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