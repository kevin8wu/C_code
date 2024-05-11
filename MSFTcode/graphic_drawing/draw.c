#include <windows.h>

int main()
{
    /*To build this source code :
    cl Gdi32.lib User32.lib draw.c
    */

    /* get device content object, if input NULL, it retrieve DC for entire screen */
    HDC screen = GetDC(NULL);

    /*HBRUSH CreateSolidBrush(
        COLORREF color
    );
    */
    HBRUSH redBrush = CreateSolidBrush(RGB(0,25,0));

    /*HGDIOBJ SelectObject(
        HDC hdc,
        HGDIOBJ h
    )*/
    SelectObject(screen, redBrush);

    /*
    BOOL Rectangle(
        HDC hdc,
        int left,
        int top,
        int right,
        int bottom
    );
    */
    for(int counter = 0; counter < 10; counter++)
    {
        //the green rectangle will grow slowly as processing bar
        Rectangle(screen, 50, 50, 500 + counter, 500);
        Sleep(20);
    }
    
}