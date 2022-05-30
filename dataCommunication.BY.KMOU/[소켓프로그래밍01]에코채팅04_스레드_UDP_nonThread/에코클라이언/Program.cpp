#include<WinSock2.h>
#pragma comment(lib, "ws2_32")
#include<stdio.h>
#pragma warning(disable:4996)

#define PORT_NUM	10200
#define BLOG_SIZE	5
#define MAX_MSG_LEN 256

IN_ADDR GetDefaultMyIP();
int main() {
	WSADATA wsadata;
	//윈속 초기화
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	char server_ip[40] = "";
	printf("서버 IP:");
	gets_s(server_ip, sizeof(server_ip));
	//소켓 생성
	SOCKET sock;
	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	//서버주소
	SOCKADDR_IN servAddr = { 0, };
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(server_ip);
	servAddr.sin_port = htons(PORT_NUM);
	int len1 = sizeof(servAddr);

	char msg[MAX_MSG_LEN] = "";
	//클라이언트 주소
	SOCKADDR_IN cliAddr = { 0, };
	cliAddr.sin_family = AF_INET;
	cliAddr.sin_addr = GetDefaultMyIP();
	cliAddr.sin_port = htons(PORT_NUM);
	int len2 = sizeof(cliAddr);

	while (true) {
		gets_s(msg, MAX_MSG_LEN);
		sendto(sock, msg, sizeof(msg), 0, (SOCKADDR*)&cliAddr, len1);
		if (strcmp(msg, "exit") == 0) {
			break;
		}
		recvfrom(sock, msg, sizeof(msg), 0, (sockaddr*)&cliAddr, &len2);
		printf("수신:%s\n", msg);
	}

	//소켓해제
	closesocket(sock);
	//윈속 해제화
	WSACleanup();
	return 0;
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
