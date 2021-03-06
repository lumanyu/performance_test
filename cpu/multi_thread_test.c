#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <time.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    while (1) {
        //sleep(1);
    }
    printf("Printing GeeksQuiz from Thread End\n");
    return NULL;
}

void *myThreadFun2(void *vargp)
{
    sleep(1);
    time_t start, end, run_time;
    start = time(NULL);
    printf("Printing GeeksQuiz from Thread2 \n");
    int i = 0;
    while (++i<10) {
        int j = 0;
        time_t small_start, small_end, small_run_time;
        small_start = time(NULL);
        while (++j < 1000000000) {
        }
        small_end = time(NULL);
        small_run_time = (small_end - small_start);
        printf("small_run_time: %d second\n", small_run_time);
        sleep(1);
    }

    end = time(NULL);
    run_time = (end - start);
    printf("Printing GeeksQuiz from Thread2 End, run_time: %d second\n", run_time);
    return NULL;
}

int main()
{
    pthread_t thread_id;
    pthread_t thread_id2;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun2, NULL);

    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);                                                                                                                                                                                                
}


/*** doc ****/
/* myThreadFun: exhaust 100% cpu time */
/* myThreadFun2: exhause about 2/3 cpu time*/
/* 10 second passed, myThreadFun2 exit*/
/* myThreadFun take all cpu time*/
/***********/
