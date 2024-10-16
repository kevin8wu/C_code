#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //for thread
#include <unistd.h> //for sleep
#include <semaphore.h> //for semaphore

#include "pthread_basis.h"

/*
互斥鎖 (Mutex): 確保一次只有一個執行緒可以存取共享資源。
信號量 (Semaphore): 控制同時存取共享資源的執行緒數量。
條件變數 (Condition Variable): 允許執行緒等待特定條件發生。
無鎖數據結構 (Lock-free data structures): 設計不需要鎖的數據結構，以提高性能和避免死鎖。
謹慎使用原子操作: 對於簡單的讀寫操作，可以使用原子操作來避免鎖的開銷。
*/

/* Mutex
   to make sure the specific section of code can
   only be executed at one between multi-threads
 */
#define USING_MUTEX_METHOD
#include "pthread_mutex.h"

/* Semaphore
   use flags to indicate each state
 */
#define USING_SEMAPHORE_METHOD
#include "pthread_semaphore.h"

int main() 
{
    /* Basis */
    void* return_value;
    int input[2] = {1, 2};

    /*  
        compile including specific library
        > gcc pthread_test.c -lpthread -o pthread_test
    */
    pthread_t thread1,thread2;

    //create sub-thread
    //pthread_create(pthread_t *th, const pthread_attr_t *attr, void*(*func)(void*), (void*)input_arg);
    pthread_create(&thread1, NULL, child1, "Child_1");
    pthread_create(&thread2, NULL, child2, (void*)input);

    for(int i=0; i<2; i++)
    {
        printf("Master\n");
        sleep(1); //1 sec
    }
    printf("-----\n");

    //wait sub-thread done, otherwise continue
    //pthread_join(pthread_t th, (void**)output_arg);
    pthread_join(thread1, NULL);
    pthread_join(thread2, &return_value);

    printf("%d + %d = %d at %x\n", input[0], input[1], *(int*)return_value, (int*)return_value);
    free(return_value);


    /* Mutex */
    pthread_t thread3,thread4;
    int index1=1;
    int index2=2;
#ifdef USING_MUTEX_METHOD
    /*
        pthread_mutex_init(pthread_mutex_t *m, const pthread_mutexattr_t *a)
        const pthread_mutexattr_t *a: used for const unsigned int *attribute
    */
    pthread_mutex_init(&mutex1, 0);
#endif
    pthread_create(&thread3, NULL, counting, (void*)&index1);
    pthread_create(&thread4, NULL, counting, (void*)&index2);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);


    /* Semaphore */
#ifdef USING_SEMAPHORE_METHOD
    /*
        sem_init(semaphore_ptr, multi_process, initial_value);
        multi_process: used for multi-thread in multi-process, 0 for multi-thread in single process
        initial_value: used for specific semaphore
    */
    sem_init(&semaphore, 0, 0);
#endif
    pthread_t thread5;
    pthread_create(&thread5, NULL, countings, NULL);

    printf("Post 2 jobs.\n");
#ifdef USING_SEMAPHORE_METHOD    
    sem_post(&semaphore); //post for work, add 1 task
    sem_post(&semaphore);
#endif

    sleep(4);

    printf("Post 3 jobs.\n");
#ifdef USING_SEMAPHORE_METHOD    
    sem_post(&semaphore);
    sem_post(&semaphore);
    sem_post(&semaphore);
#endif

    sleep(6);

    printf("Post 1 more jobs.\n");
#ifdef USING_SEMAPHORE_METHOD    
    sem_post(&semaphore); //no effect because of thread end
#endif

    pthread_join(thread5, NULL);

    return 0;
}