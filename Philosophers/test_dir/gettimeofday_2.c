#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    struct timeval startTime, endTime;
    double diff_tv_sec;
    double diff_tv_usec;

    gettimeofday(&startTime, NULL);
    usleep(1000 * 1000);
    gettimeofday(&endTime, NULL);
    diff_tv_sec = endTime.tv_sec - startTime.tv_sec;
    diff_tv_usec = endTime.tv_usec - startTime.tv_usec;

    printf("%f seconds\n", diff_tv_sec);
    printf("%f micro seconds\n", diff_tv_usec);
    return (0);
}