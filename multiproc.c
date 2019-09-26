#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "fibonacci.h"

pid_t cal_fib(int n){
    pid_t newPro = fork();
    if(newPro == -1){
	printf("fail to create process");
	return -1;
    }
    int result = 0;
    if(newPro == 0){
	result = fibonacci(n);
	exit(result);
    }
    else
	return newPro;
}

int main(void){
    pid_t pid;
    int status;
    int r;
    pid = cal_fib(10);
    
}
