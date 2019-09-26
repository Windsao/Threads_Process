#include <stdlib.h>  
#include <pthread.h>
#include "fibonacci.h"

int result[10];

void* passArg(void* n){
    int result = fibonacci(*(int*)n);
    return (void*)&result;
}

int main(void){
    void* status;
    int n = 10;
    pthread_t thread[10];
    for (int i = 0; i < n; i++)
	if (pthread_create(&thread[i], NULL, passArg((int*)&n), (void*)&n))
		printf("create thread fail");
		
    for (int i = 0; i < n; i++)
	if(pthread_join(thread[i], status) != 0)
	    printf("fail to end thread");
	else
	    result[i] = *(long*)status;
    for (int i = 0; i < n; i++)
	printf("the value of %d is %d", i, result[i]);
}
