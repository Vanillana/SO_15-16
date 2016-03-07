
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>



/* Prof
 Não temos maneira de saber se foi o pai ou filho que fez o primeiro Bop
int main(){
	printf("Be\n");
	fork();
	printf("Bop\n");
	return 0;
}
*/

/*Prof

int main(){
	printf("Be\n");
	fork();
	printf("Bop\n");
	fork();
	printf("Bap\n");
	return 0;
}

|
| BE
|_____
|     |
|     | Bop
|     |_______
|     |       | 
|     |       |
|     |Bap    |Bap
|Bop
|
|______
|      |
|      |
|Bap   |Bap

*/


/*Prof
int main(){
	int status;
	int fpid;

	if((fpid=fork()) == 0){
		printf("Filho\n");
		_exit(4);
	}
	else{
		printf("Pai teve filho %d.\n",fpid);
		wait(&status);
		printf("Filho morreu com %d.\n",WEXITSTATUS(status));
	}
	printf("Só Pai.\n");

	return 0;
}
*/

/* Ex 2
int main(){
	int status;
	int fpid;

	if((fpid=fork()) == 0){
			printf("Filho: própio pid é %d\n", getpid());
			printf("Filho: pid do pai é %d",getppid());
			_exit(4);
	}

	else{
			printf("Pai: própio pid é %d.\n",getpid());
			printf("Pai: pid do pai é %d.\n", getppid());
			printf("Pai: pid do filho é %d.\n", fpid);
			wait(&status);
			printf("Filho morreu com %d.\n",WEXITSTATUS(status));
	}

	return 0;
}
*/

/*
 //Ex 3
int main(){
	int fpid, status, i;
	for(i = 0; i < 10; i++){
			if((fpid = fork()) == 0){
					printf("Filho %d: própio pid é %d\n", i+1, getpid());
					printf("Filho %d: pid do pai é %d", i+1, getppid());
					_exit(i+1);	
			}
			else{
					wait(&status);
					printf("Pai: filho %d morreu com %d.\n",fpid,WEXITSTATUS(status));
			}
	}
	return 0;
}
*/

// Ex:4

int main(){
	int fpid, status, i;
	for(i = 0; i < 10; i++){
			if((fpid = fork()) == 0){
					printf("Filho %d: própio pid é %d\n", i+1, getpid());
					printf("Filho %d: pid do pai é %d", i+1, getppid());
					_exit(i+1);	
			}
		}
			else{
					wait(&status);
					printf("Pai: filho %d morreu com %d.\n",fpid,WEXITSTATUS(status));
			}
	
	return 0;
}

