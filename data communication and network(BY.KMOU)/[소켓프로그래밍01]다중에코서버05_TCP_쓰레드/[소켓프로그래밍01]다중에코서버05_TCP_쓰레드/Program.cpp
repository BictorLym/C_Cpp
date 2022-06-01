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
#define MAX_MSG_LEN	1024
IN_ADDR GetDefaultMyIP();
DWORD WINAPI ProcessClient(LPVOID arg);
int cnt = 0;
//void err_quit
int main() {
	int retval;
	/*���� �ʱ�ȭ********************************/
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata)!=0) {
		return 1;
	}
	/*socket�ʱ�ȭ*******************************/
	SOCKET listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_sock == INVALID_SOCKET) {
		//err_quit("socket()");
	}
	/*bind()************************************/
	//�����ּ�
	SOCKADDR_IN servAddr = { 0, };
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr = GetDefaultMyIP();
	servAddr.sin_port = htons(PORT_NUM);
	//��Ʈ��ũ �������̽��� ���� ����
	retval = bind(listen_sock, (SOCKADDR*)&servAddr, sizeof(servAddr));
	if (retval == SOCKET_ERROR) {
		//err_quit("bind()")
		perror("bind() ����");
		return -1;
	}
	/*listen()**********************************/
	//��α� ť ũ�� ����
	retval = listen(listen_sock, BLOG_SIZE);
	
	//retval = listen(listen_sock, SOMAXCONN);
	if (retval == SOCKET_ERROR) {
		//err_quit("listen()")
		perror("listen() ����");
		return -1;
	}
	//���� ���� ���
	printf("TCPserver Setup\n");
	printf("IP:%s   PORT_NUM:%d\n", inet_ntoa(servAddr.sin_addr), PORT_NUM);
	/*������ ��ſ� ����� ����*****************/
	SOCKET client_sock;
	SOCKADDR_IN clientAddr;
	int addrlen;
	HANDLE hThread;
	while (true) {
		/*accept()************************************/
		addrlen = sizeof(clientAddr);
		client_sock = accept(listen_sock, (SOCKADDR*)&clientAddr, &addrlen);
		if (client_sock == INVALID_SOCKET) {
			//err_display("accept()");
			break;
		}
		//������ Ŭ���̾�Ʈ ���� ���
		printf("%s:%d�� ���� ��û ����\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));;
		/*������ ����********************************/
		//_beginthread();
		hThread = CreateThread(NULL, 0, ProcessClient, (LPVOID)client_sock, 0, NULL);
		if (hThread == NULL) {
			closesocket(client_sock);
		}
		else {
			CloseHandle(hThread);
		}
	}
	/*closesocket()*****************************/
	closesocket(listen_sock);
	/*��������**********************************/
	WSACleanup();

	return 0;
}
/*Ŭ���̾�Ʈ�� ���������*********************************/
DWORD WINAPI ProcessClient(LPVOID arg)
{
	SOCKET client_sock = (SOCKET)arg;
	int retval;
	SOCKADDR_IN clientaddr;
	int addrlen;
	

	char msg[MAX_MSG_LEN]="";
	char buf1[10]="";
	char buf2[22]="";
	//Ŭ���̾�Ʈ���� �۽Ź��� ����
	char buf3[BUF_SIZE+1]="";
	
	/*Ŭ���̾�Ʈ ���� ���*********************************/
	addrlen = sizeof(clientaddr);
	getpeername(client_sock, (SOCKADDR*)&clientaddr, &addrlen);

	while (true) {
		//������ �ޱ�
		retval = recv(client_sock, buf3, BUF_SIZE, 0);
		if (retval == SOCKET_ERROR) {
			//err_display("recv()");
			perror("display����");
			break;
		}
		else if (retval == 0) {
			break;
		}
		//���� ������ ���
		//buf3[retval] = '\0';
		cnt++;
		itoa(cnt, buf1, 10);
		strcpy(buf2, "th message received: ");
		strcat(msg, buf1); strcat(msg, buf2); strcat(msg, buf3);
		//printf("%s:%d => ", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
		//printf("th message received: %s\n", buf3);
		printf("%s:%d => ", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
		printf("%dth message received: %s\n", cnt, buf3);
		//sprintf(msg, "%dth message received: %s\n", cnt, buf3);
		printf("%s", msg);
		//������ ������
		retval = send(client_sock, msg, sizeof(msg), 0);
		if (retval == SOCKET_ERROR) {
			//err_display("send()");
			perror("send����");
			break;
		}
		strcpy(msg, "");
		strcpy(buf1, ""); strcpy(buf2, ""); strcpy(buf3, "");
	}
	/*closesocket()*****************************/
	closesocket(client_sock);
	printf("%s:%d�� ��� ����\n",
		inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

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