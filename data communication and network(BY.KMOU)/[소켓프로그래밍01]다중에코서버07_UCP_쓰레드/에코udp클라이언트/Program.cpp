#include<WinSock2.h>
#pragma comment(lib, "ws2_32")
#include<stdio.h>
#pragma warning(disable:4996)

#define SERVER_PORT	10200
#define BLOG_SIZE	5
#define MAX_MSG_LEN 1024

int main() {
	WSADATA wsadata;
	//���� �ʱ�ȭ
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	char server_ip[40] = "";
	printf("���� IP:");
	gets_s(server_ip, sizeof(server_ip));
	//���� ����
	SOCKET sock;
	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	//�����ּ�
	SOCKADDR_IN servAddr = { 0, };
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(server_ip);
	servAddr.sin_port = htons(SERVER_PORT);

	//������ ��ſ� ����� ����
	SOCKADDR_IN peeraddr;
	int addrlen;
	char buf[MAX_MSG_LEN];
	int len;
	int retval;
	while (true) {
		printf("\n[����������]:");
		if (fgets(buf, MAX_MSG_LEN, stdin) == NULL) {
			break;
		}
		
		//'\n'���� ����
		len = strlen(buf);
		if (buf[len - 1] == '\n') {
			buf[len - 1] == '\0';
		}
		if (strlen(buf) == 0) {
			break;
		}

		retval = sendto(sock, buf, strlen(buf), 0,
			(SOCKADDR*)&servAddr, sizeof(servAddr));
		if (retval == SOCKET_ERROR) {
			perror("sendto() error");
			continue;
		}
		printf("[UDP Ŭ���̾�Ʈ] %d����Ʈ�� ���½��ϴ�.\n", retval);

		//�����͹ޱ�
		addrlen = sizeof(peeraddr);
		retval = recvfrom(sock, buf, MAX_MSG_LEN, 0,
			(SOCKADDR*)&peeraddr, &addrlen);
		if (retval == SOCKET_ERROR) {
			perror("recvfrom(), error");
			continue;
		}
		//�۽����� IP�ּ� üũ
		if (memcmp(&peeraddr, &servAddr, sizeof(peeraddr))) {
			printf("[����] �߸��� �������Դϴ�.\n");
			continue;
		}
		//���� ������ ���
		buf[retval] = '\0';
		printf("[UDP Ŭ���̾�Ʈ] %d����Ʈ�� �޾ҽ��ϴ�.\n", retval);
		printf("[���� ������] %s\n", buf);
	}
	
	closesocket(sock);
	//���� ����ȭ
	WSACleanup();
	return 0;
}

