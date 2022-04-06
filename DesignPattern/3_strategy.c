#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SORT(x) sort_##x##_() //using token pasting as macro

void sort_quick_(){ printf("Quick sort is selected.\n"); }
void sort_bubble_(){ printf("Bubble sort is selected.\n"); }

int main()
{
    char input = '!';

    while(input != 'q')
    {
        system("cls"); //clear infor on console

        printf("Choose a kind of sorting:\n(a) Quick sort\n(b) Bubble sort\n(q) Quit\n");
        input = getchar();

        if(input == 'a')
        {
            SORT(quick);
        }
        else if(input == 'b')
        {
            SORT(bubble);
        }
        else 
        {
            continue;
        }

        system("pause");
    }

    return 0;
}