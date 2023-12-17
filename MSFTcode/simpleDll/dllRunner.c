#include <Windows.h>

//x64 Native Tools Command Prompt
//cl dllRunner.c

void main()
{
    LoadLibraryA("myDLL.dll");
}
