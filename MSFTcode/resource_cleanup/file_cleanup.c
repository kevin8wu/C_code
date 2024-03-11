/*
> man 2 open
> man 2 close
> man 3 sleep
*/

#include <fcntl.h>
#include <unistd.h>

int main()
{
    for(;;)
    {
        //int open(const char* pathname, int flags, mode_t mode);
        int fd = open("./asdf", O_RDONLY);

        //unsigned int sleep(unsigned int seconds);
        sleep(5);

        int fd2 = open("./asdf2", O_RDONLY);
        if(fd2 == -1) goto cleanup;

cleanup:
        if(fd != -1)
        {
            //int close(int fd);
            close(fd);
        }
        if(fd2 != -1)
        {
            close(fd2);
        }
    }
    
}