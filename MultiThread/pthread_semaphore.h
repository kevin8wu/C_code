#ifdef USING_SEMAPHORE_METHOD
sem_t semaphore;
#endif

int counter=0;

void* countings()
{
    for(int i=0;i<5;i++) 
    {
#ifdef USING_SEMAPHORE_METHOD
        sem_wait(&semaphore); //wait for work, minus 1 task
#endif

        counter++;
        printf("Counter = %d\n", counter);
        sleep(1);
    }
    pthread_exit(NULL);
}