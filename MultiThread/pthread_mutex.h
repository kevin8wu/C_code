#ifdef USING_MUTEX_METHOD
//pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex1;
#endif

int direct_counter=0;
int indirect_counter=0;

void* counting(void* arg)
{
    int* index = (int*)arg;
    for(int i=0; i<3; i++)
    {
        //simulate non-optimized global variable
        printf("%d before indirect_counter = %d\n", *index, indirect_counter);
#ifdef USING_MUTEX_METHOD        
        pthread_mutex_lock(&mutex1); //lock section below
#endif        
        int tmp = indirect_counter;
        sleep(1);
        indirect_counter = tmp + 1;
#ifdef USING_MUTEX_METHOD        
        pthread_mutex_unlock(&mutex1); //unlock section above
#endif        
        printf("%d after indirect_counter = %d\n", *index, indirect_counter);

        printf("%d before direct_counter = %d\n", *index, direct_counter);
        direct_counter++;
        printf("%d after direct_counter = %d\n", *index, direct_counter);
    }
    pthread_exit(NULL);
}