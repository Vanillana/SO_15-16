#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define RAND_MAX 9

// ex 1
/*
int main(){
	printf("PID do processo: %d\n",getpid());
	printf("PID do pai %d\n",getppid());
	return 0;
}
*/


// ex 2
/*
int main(){
	int fpid, status;
	if((fpid = fork()) == 0){
		printf("FILHO: tenho pid %d e o meu pai tem pid %d\n",getpid(),getppid());
		_exit(4);
	}
	wait(&status);
	printf("PAI: tenho pid %d, o meu pai tem pid %d e o meu filho tem pid %d\n",getpid(), getppid(),fpid);
	return 0;
}
*/

// ex 3
/*
int main(){
	int fpid, status, i;
	for(i = 0; i < 10; i++){
		if((fpid = fork()) == 0){
			printf("O  meu pid é %d e o do meu pai é %d.\n",getpid(),getppid());
			_exit(i+1);
		}
		wait(&status);
		printf("O filho %d morreu com código %d.\n",fpid,WEXITSTATUS(status));

	}
	return 0;
}
*/

// ex 4
/*
int main(){
	int fpid[10], status, exit_values[10], i;

	for (i = 0; i < 10; i++){
		if((fpid[i] = fork()) == 0){
			printf("FILHO: Filho %d tem código %d.\n",i+1,getpid());
			_exit(i+1);
		}
	}
	for(i = 0; i < 10; i++){
		waitpid(fpid[i],&status,0);
		exit_values[i] = WEXITSTATUS(status);
	}
	for(i = 0; i < 10; i++){
		printf("PAI: Filho %d terminou com código %d.\n",fpid[i],exit_values[i]);
	}
	return 0;
}
*/

// ex 5
/*
int main(){
	int fpid, status, i;

	for(i = 0; i < 10; i++){
		if((fpid = fork()) == 0){
			printf("FILHO %d: o meu pid é %d e o do meu pai é %d.\n",i+1,getpid(),getppid());
		}
		else{
			wait(&status);
			_exit(i+1);
		}
	}

	return 0;
}
*/


// ex 6

int main(int argc, char *argv[]){
	// Matrix
	int i, j, lines, columns, number, count;
	if(argc != 4){
		printf("Tem de introduzir numero de linhas, o numero de colunas e o numero a procurar.\n");
		return 1;
	}

	lines = atoi(argv[1]);
	columns = atoi(argv[2]);
	number = atoi(argv[3]);
	int matrix[lines][columns];
	count = 0;

	// Create matrix
	srand(time(NULL));
	for(i = 0; i < lines; i++){
		for(j = 0; j < columns; j++){
			matrix[i][j] = rand();
		}
	}
	// Print matrix
	for(i = 0; i < lines; i++){
		for(j = 0; j < columns; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	// Search each column with one process and increment count when number is found
	int fpid[columns];
	for(i = 0; i < columns; i++){
		if((fpid[i] = fork()) == 0){
			for(j = 0; j < lines; j++){
				if(matrix[i][j] == number){
					count++;
				}
			}
		}
	}
	return 0;
}