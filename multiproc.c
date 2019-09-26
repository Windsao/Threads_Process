#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "fibonacci.h"

#define MAX 10

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
	pid_t pidArray[MAX];
    int status;
    int r;
	int i; 
	
	for(i = 0; i < MAX; i++){
		pid = cal_fib(i);
		if (pid == -1) {
			printf("Fail to create child process");
			exit(1);
		}
		pidArray[i] = pid;
	}
	for (i = 0; i < MAX; i++) {
		if (waitpid(pidArray[i], &status, 0) == -1)
			printf("waitpid error");
		if (WIFEXITED(status)) {
			r = WEXITSTATUS(status);
			printf("The fiboncacci value of %d is %i\n", i, r);
		}
	}
    
    
}
