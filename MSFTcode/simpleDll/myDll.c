#include <Windows.h>
#include <stdio.h>

//cl /LD  myDll.c

BOOL WINAPI DllMain(HINSTANCE hinstDLL,
                    DWORD fdwReason,
                    LPVOID lpvReason)
{
    if(fdwReason == DLL_PROCESS_ATTACH)
    {
        printf("Hello from my DLL");
    }

    return TRUE;
}