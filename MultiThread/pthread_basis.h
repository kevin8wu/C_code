void* child1(void* data)
{
    char* str = (char*)data;
    for(int i=0; i<4; i++)
    {
        printf("%s\n", str);
        sleep(1); //1 sec
    }
    printf("-----\n");

    //exit sub-thread here or execute until done
    pthread_exit(NULL);
}

void* child2(void* arg)
{
    for(int i=0; i<6; i++)
    {
        printf("%s\n", "Child_2");
        sleep(1); //1 sec
    }
    printf("-----\n");

    int* input = (int*)arg;
    int* result = malloc(sizeof(int) * 1);
    *result = input[0] + input[1];
    printf("%x %x %d\n", (void*)result, result, *result);

    //exit sub-thread and return result
    pthread_exit((void*)result);
}