#include <sys/time.h>

#include <unistd.h>

#include <stdio.h>

#include <string.h>

int	main(void)
{
	struct timeval mytime;

	gettimeofday(&mytime, NULL);
	printf("%ld : %d\n", mytime.tv_sec, mytime.tv_usec);
    printf("%ld : %d\n", mytime.tv_sec, mytime.tv_usec * 1000000);
    printf("realtive time is : %ld\n", mytime.tv_sec * 1000000 + mytime.tv_usec);

    return (0);
} 
