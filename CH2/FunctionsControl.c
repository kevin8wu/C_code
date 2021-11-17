#include <stdio.h>

int main()
{
    printf("HI\n");
    int score=89;
    if(score!=100 && score>=89){printf("Not so excellent\n");}
    if(score>75){printf("You passed\n");}
    else if(score>60){printf("You fail\n");}
    else{printf("you down\n");}
    int y,x=3;
    y=(x>=5)?5:x; //if(x>=5){y=5;}else{y=x;}
    printf("%d\n",y);

    /******************************************/

    switch(x)
    {
        case 1:printf("one\n");break;
        case 2:printf("two\n");break;
        case 3:printf("three\n");break;
        case 4:
        case 5:
        case 6:printf("four, five or six\n");break;
        default:printf("Not above number\n");
    }

    /******************************************/

    while(x<5)
    {
        printf("while x=%d\n",x);
        x++;
    }
    do{
        printf("do while x=%d\n",x);
        x--;
    }while(x>3);

    /******************************************/

    for(int i=0;i<4;i++){printf("%d\n",i);}
    for(;x<7;x++) //initial value, condition, increment can be skipped
    {printf("%d\n",x);}
    for(int i=0,j=5;i<j;i++,j--) //input arg can be multiple
    {printf("%d %d\n",i,j);}

    /******************************************/

    return 0;
}