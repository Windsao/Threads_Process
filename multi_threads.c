#include <stdlib.h>  
#include <pthread.h>
#include "fibonacci.h"

int result;

void* passArg(void* n){
    result = fibonacci(*(int*)n);
    return (void*)&result;
}

int main(void){
    void* status;
    int n = 10;
    int values[10];
    pthread_t thread[10];
    for(int i = 0; i < 10; i++)
    	values[i] = i;
    
    for (int i = 0; i < n; i++)
		if (pthread_create(&thread[i], NULL, passArg((int*)&n), &values[i]) != 0)
			printf("create thread fail");
		
    for (int i = 0; i < n; i++)
		if(pthread_join(thread[i], &status) != 0)
	    	printf("fail to end thread");
		else
	    	values[i] = *(long*)status;
    
    for (int i = 0; i < n; i++)
		printf("the value of %d is %d", i, values[i]);
}
