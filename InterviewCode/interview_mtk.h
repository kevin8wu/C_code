//2020/02/18 聯發科
#include <math.h>

struct point
{
    int x,y;
};
struct circle
{
    int r;
    struct point center;
};
void printCircle(struct circle A)
{
    int px,py;
    int dx=A.center.x;
    int dy=A.center.y;
    for(int i=0;i<=A.r;i++)
    {
        px=i;
        py=sqrt(A.r*A.r-i*i);
        printf("%d %d\n",dx+px,dy+py);
        //printf("%d %d\n",dx+px,dy-py);
        //printf("%d %d\n",dx-px,dy-py);
        //printf("%d %d\n",dx-px,dy+py);
    }
}
