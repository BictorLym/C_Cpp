#include<WinSock2.h>
#pragma comment(lib, "ws2_32")
#include<stdio.h>
#pragma warning(disable:4996)
IN_ADDR GetDefaultMyIP();
#define PORT_NUM	10200
#define BLOG_SIZE	5
#define MAX_MSG_LEN 256
SOCKET setTCPServer(short pnum, int blog);
int main() {
	WSADATA wsadata;
	//���� �ʱ�ȭ
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	char server_ip[40] = "";
	printf("���� IP:");
	gets_s(server_ip, sizeof(server_ip));
	//���� ����
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//�����ּ�
	SOCKADDR_IN servAddr = { 0, };
	servAddr.sin_family = AF_INET;
	//servAddr.sin_addr.s_addr = inet_addr(server_ip);
	servAddr.sin_addr = inet_addr(server_ip);
	servAddr.sin_port = htons(PORT_NUM);

	//���� �õ�
	int re;
	re = connect(sock, (SOCKADDR*)&servAddr, sizeof(servAddr));
	if (re == SOCKET_ERROR) {
		return -1;
	}
	//Do it
	char msg[MAX_MSG_LEN] = "";
	while (true) {
		gets_s(msg, MAX_MSG_LEN);
		send(sock, msg, sizeof(msg), 0);
		if (strcmp(msg, "exit") == 0) {
			break;
		}
		recv(sock, msg, sizeof(msg), 0);
		printf("����:%s\n", msg);
	}
	closesocket(sock);
	//���� ����ȭ
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