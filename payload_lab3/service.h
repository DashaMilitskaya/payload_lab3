#pragma once
#include "shell.h"
#include <Windows.h>

#define SVCNAME TEXT("persistence")



extern SERVICE_STATUS          gSvcStatus;
extern SERVICE_STATUS_HANDLE   gSvcStatusHandle;
extern HANDLE                  ghSvcStopEvent;

VOID WINAPI SvcMain(DWORD dwArgc, LPTSTR* lpszArgv);
VOID WINAPI SvcCtrlHandler(DWORD dwCtrl);
VOID SvcInit(DWORD dwArgc, LPTSTR* lpszArgv);
VOID ReportSvcStatus(DWORD dwCurrentState,
    DWORD dwWin32ExitCode,
    DWORD dwWaitHint);

