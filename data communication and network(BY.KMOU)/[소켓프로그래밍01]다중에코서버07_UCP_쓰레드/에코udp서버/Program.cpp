#include<WinSock2.h>
#pragma comment(lib, "ws2_32")
#include<iostream>
#include<vector>
using namespace std;
#include<process.h>
#include<Windows.h>
#pragma warning(disable:4996)
#define PORT_NUM	10200
#define BLOG_SIZE	5
#define BUF_SIZE	256
/*고정형에서는 버퍼크기가 같아야함*/
#define MAX_MSG_LEN	1024
IN_ADDR GetDefaultMyIP();
int cnt = 0;
void err_quit(const char* msg);
void setWinsock(WSADATA& wsadata);
void setUDPServer(SOCKET& serverSock);
void ComunicationLoop(SOCKET& serverSock);
void Communication(void* arg);
char* MakeMessage(char buf3[], int cnt);

int main() {
	int retval = 0;
	/*윈속 초기화********************************/
	WSADATA wsadata;
	setWinsock(wsadata);

	/*socket초기화*******************************/
	SOCKET serverSock;

	setUDPServer(serverSock);


	ComunicationLoop(serverSock);

	/*closesocket()*****************************/
	closesocket(serverSock);
	/*윈속종료**********************************/
	WSACleanup();

	return 0;
}
void setWinsock(WSADATA& wsadata)
{
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		err_quit("윈속 실패");
		/*perror("윈속 error\n");
		exit(1);*/
		//return 1;
	}
	else {
		printf("윈속 success\n");
	}
}
void setUDPServer(SOCKET& serverSock)
{
	/*socket초기화*******************************/
	serverSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (serverSock == INVALID_SOCKET) {
		err_quit("socket() 실패");
	}
	else {
		printf("socket() success\n");
	}
	/*bind()************************************/
	/*데이터 통신에 사용할 변수*****************/
	//서버주소
	SOCKADDR_IN servAddr = { 0, };
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr = GetDefaultMyIP();
	servAddr.sin_port = htons(PORT_NUM);
	//네트워크 인터페이스와 소켓 결합
	int retval = bind(serverSock, (SOCKADDR*)&servAddr, sizeof(servAddr));
	if (retval == SOCKET_ERROR) {
		err_quit("bind() 실패");
		/*perror("bind() 실패");
		exit(1);*/
		//return -1;
	}
	else {
		printf("bind() success\n");
	}
	
	//서버 정보 출력
	printf("UDPserver Setup\n");
	printf("IP:%s   PORT_NUM:%d\n", inet_ntoa(servAddr.sin_addr), PORT_NUM);
}
void ComunicationLoop(SOCKET& serverSock)
{
	SOCKET client_sock = { 0, };
	SOCKADDR_IN clientAddr = { 0, };
	int addrlen;
	char msg[MAX_MSG_LEN];
	char buf3[MAX_MSG_LEN];
	int retval;
	while (true) {
		cnt++;
		addrlen = sizeof(clientAddr);
		//데이터 수신
		retval = recvfrom(serverSock, buf3, MAX_MSG_LEN, 0, (sockaddr*)&clientAddr, &addrlen);
		if (retval == SOCKET_ERROR) {
			perror("recvfrom()");
			continue;
		}
		buf3[retval] = '\0';
		//msg = MakeMessage(buf3, cnt);
		strcpy(msg, MakeMessage(buf3, cnt));
		printf("(%s:%d로부터 )", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
		printf("%s\n", msg);
		//데이터 수신
		retval = sendto(serverSock, msg, retval+22, 0, 
			(SOCKADDR*)&clientAddr, addrlen);
		if (retval == SOCKET_ERROR) {
			perror("sendto()");
			continue;
		}
	}
}
/*클라이언트와 데이터통신*********************************/
void Communication(void* arg)
{
	SOCKET clisock = (SOCKET)arg;
	SOCKADDR_IN cliaddr = { 0 };
	int len = sizeof(cliaddr);
	getpeername(clisock, (SOCKADDR*)&cliaddr, &len);
	char msg[MAX_MSG_LEN] = "";


	char buf3[MAX_MSG_LEN] = "";
	int retval = 0;
	while (1)
	{
		retval = recv(clisock, buf3, sizeof(buf3), 0);
		if (retval == SOCKET_ERROR) {
			perror("recv() 실패");
			break;
		}
		else if (retval == 0) {
			break;
		}
		else {
			printf("   recv() success\n");
		}
		cnt++;
		//strcpy(msg, buf3);
		//msg = MakeMessage(buf3, cnt);
		strcpy(msg, MakeMessage(buf3, cnt));
		printf("(%s:%d로부터 )", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
		printf("%s\n", msg);

		//클라이언트로 송신

		retval = send(clisock, msg, sizeof(msg), 0);
		if (retval == SOCKET_ERROR) {
			perror("send() 실패");
			break;
		}
		else if (retval == 0) {
			break;
		}
		else {
			printf("   send() success\n");
		}

	}

	printf("%s:%d와 통신 종료:%s\n",
		inet_ntoa(cliaddr.sin_addr),
		ntohs(cliaddr.sin_port),
		buf3);
	closesocket(clisock);
}
char* MakeMessage(char buf3[], int cnt)
{
	char message[MAX_MSG_LEN];
	sprintf(message, "%dth message received: %s", cnt, buf3);
	
	return message;
}
void err_quit(const char* msg)
{
	printf("%s", msg);
	exit(1);
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