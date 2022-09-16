#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t mutex;
int cnt = 0;

typedef struct s_info
{
	int id;
	char *name;
	pthread_t *thread;
}				t_info;


void *count(void *arg)
{
    int i;
    char *name = (char *)arg;

    pthread_mutex_lock(&mutex);
    //============critical section===========//
    cnt = 0;
	if (!strcmp("thread2", name))
	{
		printf("thread2\n");
		usleep(1000);
	}
    for (i = 0; i < 10; i++)
    {
        printf("%s cnt: %d\n", name, cnt);
        cnt++;
        usleep(1);
    }

    //============critical section===========//
    pthread_mutex_unlock(&mutex);
}

int main()
{

	pthread_t thread1, thread2, thread3;

    pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
    pthread_create(&thread1, NULL, count, (void *)"thread1");
    pthread_create(&thread2, NULL, count, (void *)"thread2");
    pthread_create(&thread3, NULL, count, (void *)"thread3");
	pthread_mutex_unlock(&mutex);
    pthread_join(thread2, NULL);
    // printf("i bet thread222 after thread1\n");
    pthread_join(thread1, NULL);
    pthread_join(thread3, NULL);
    pthread_mutex_destroy(&mutex);
    return (0);
}
