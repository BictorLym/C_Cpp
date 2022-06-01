#include<WinSock2.h>
#pragma comment(lib, "ws2_32")
#include<stdio.h>
#pragma warning(disable:4996)

#define SERVER_PORT	10200
#define BLOG_SIZE	5
#define MAX_MSG_LEN 1024

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
	servAddr.sin_port = htons(SERVER_PORT);

	//데이터 통신에 사용할 변수
	SOCKADDR_IN peeraddr;
	int addrlen;
	char buf[MAX_MSG_LEN];
	int len;
	int retval;
	while (true) {
		printf("\n[보낼데이터]:");
		if (fgets(buf, MAX_MSG_LEN, stdin) == NULL) {
			break;
		}
		
		//'\n'문자 제거
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
		printf("[UDP 클라이언트] %d바이트를 보냈습니다.\n", retval);

		//데이터받기
		addrlen = sizeof(peeraddr);
		retval = recvfrom(sock, buf, MAX_MSG_LEN, 0,
			(SOCKADDR*)&peeraddr, &addrlen);
		if (retval == SOCKET_ERROR) {
			perror("recvfrom(), error");
			continue;
		}
		//송신자의 IP주소 체크
		if (memcmp(&peeraddr, &servAddr, sizeof(peeraddr))) {
			printf("[오류] 잘못된 데이터입니다.\n");
			continue;
		}
		//받은 데이터 출력
		buf[retval] = '\0';
		printf("[UDP 클라이언트] %d바이트를 받았습니다.\n", retval);
		printf("[받은 데이터] %s\n", buf);
	}
	
	closesocket(sock);
	//윈속 해제화
	WSACleanup();
	return 0;
}

