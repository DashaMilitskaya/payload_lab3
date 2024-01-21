#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#pragma once

#include <winsock2.h>
#include <stdio.h>



int ReverseShell(const char* ip, short port);