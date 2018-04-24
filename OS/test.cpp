#include <cstdio>
#include <unistd.h>

int main() {
	pid_t fpid;
	fpid = fork();
	int count = 0;
	if (fpid < 0) {
		printf("error in fork!");
	}
	else if (fpid == 0) {
		printf("i am the child process, my process id is %d\n",getpid());
		count++;
		printf("2 : \n");
	}
	else {
		printf("i am the parent process, my process id is %d\n",getpid());
		count++;
		printf("3 : \n");
	}
	printf("count = %d\n", count);
	return 0;
}
