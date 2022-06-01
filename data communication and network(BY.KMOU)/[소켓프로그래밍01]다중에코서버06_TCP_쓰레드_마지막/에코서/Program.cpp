#include<WinSock2.h>
#pragma comment(lib, "ws2_32")
//#include<iostream>
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


//void err_quit
void Communication(void* param);
char* MakeMessage(char buf3[], int cnt);

int main() {
	int retval = 0;
	/*���� �ʱ�ȭ********************************/
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
		return 1;
	}
	else {
		printf("���� success\n");
	}
	/*socket�ʱ�ȭ*******************************/
	SOCKET serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSock == INVALID_SOCKET) {
		//err_quit("socket()");
	}
	else {
		printf("socket() success\n");
	}
	/*bind()************************************/
	//�����ּ�
	SOCKADDR_IN servAddr = { 0, };
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr = GetDefaultMyIP();
	servAddr.sin_port = htons(PORT_NUM);
	//��Ʈ��ũ �������̽��� ���� ����
	retval = bind(serverSock, (SOCKADDR*)&servAddr, sizeof(servAddr));
	if (retval == SOCKET_ERROR) {
		//err_quit("bind()")
		perror("bind() ����");
		return -1;
	}
	else {
		printf("bind() success\n");
		retval = -1;
	}
	/*listen()**********************************/
	//��α� ť ũ�� ����
	retval = listen(serverSock, BLOG_SIZE);

	//retval = listen(serverSock, SOMAXCONN);
	if (retval == SOCKET_ERROR) {
		//err_quit("listen()")
		perror("listen() ����");
		return -1;
	}
	else {
		printf("listen() success\n");
		retval = -1;
	}
	//���� ���� ���
	printf("TCPserver Setup\n");
	printf("IP:%s   PORT_NUM:%d\n", inet_ntoa(servAddr.sin_addr), PORT_NUM);
	/*������ ��ſ� ����� ����*****************/
	SOCKET client_sock;
	SOCKADDR_IN clientAddr = { 0, };
	int addrlen = sizeof(clientAddr);

	while (true) {
		/*accept()************************************/
		//addrlen = sizeof(clientAddr);
		client_sock = accept(serverSock, (SOCKADDR*)&clientAddr, &addrlen);
		if (client_sock == INVALID_SOCKET) {
			//err_display("accept()");
			perror("accept() ����");
			break;
		}
		else {
			printf("accept() success\n");
			retval = -1;
		}
		//������ Ŭ���̾�Ʈ ���� ���
		printf("%s:%d�� ���� ��û ����\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));;
		/*������ ����********************************/
		_beginthread(Communication, 0, (void*)client_sock);
	}
	/*closesocket()*****************************/
	closesocket(serverSock);
	/*��������**********************************/
	WSACleanup();

	return 0;
}
/*Ŭ���̾�Ʈ�� ���������*********************************/
void Communication(void* param)
{
	SOCKET dosock = (SOCKET)param;
	SOCKADDR_IN cliaddr = { 0 };
	int len = sizeof(cliaddr);
	getpeername(dosock, (SOCKADDR*)&cliaddr, &len);
	char msg[MAX_MSG_LEN]="";
	int cnt = 0;
	
	char buf3[MAX_MSG_LEN]="";
	int retval = 0;
	while (1)
	{
		retval = recv(dosock, buf3, sizeof(buf3), 0);
		if (retval == SOCKET_ERROR) {
			perror("recv() ����");
			break;
		}
		else if(retval==0){
			break;
		}
		else {
			printf("   recv() success\n");
		}
		cnt++;
		//strcpy(msg, buf3);
		//msg = MakeMessage(buf3, cnt);
		strcpy(msg, MakeMessage(buf3, cnt));
		printf("(%s:%d�κ��� )", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
		printf("%s\n", msg);
		
		//Ŭ���̾�Ʈ�� �۽�
		retval = send(dosock, msg, sizeof(msg), 0);
		if (retval == SOCKET_ERROR) {
			perror("send() ����");
			break;
		}
		else if (retval == 0) {
			break;
		}
		else {
			printf("   send() success\n");
		}
		
	}

	printf("%s:%d�� ��� ����:%s\n",
		inet_ntoa(cliaddr.sin_addr),
		ntohs(cliaddr.sin_port),
		buf3);
	closesocket(dosock);
}
char* MakeMessage(char buf3[], int cnt)
{
	char message[MAX_MSG_LEN];
	sprintf(message, "%dth message received: %s", cnt, buf3);
	/*char buf1[MAX_MSG_LEN];
	char buf2[MAX_MSG_LEN];
	itoa(cnt, buf1, MAX_MSG_LEN);
	strcpy(buf2, "th message received: ");

	strcat(message, buf1); strcat(message, buf2); strcat(message, buf3);*/
	return message;
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