#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ex 1
/*
int main(int argc, char *argv[]){
	char input;
	while(read(0,&input,1) > 0){
		write(1,&input,1);
	}
	return 0;
}
*/



// ex 2
/*
int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Numero de argumentos invalido.");
		return 1;
	}

	char c = 'a';
	int file, i;

	file = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0666);
	if(file == -1){
		printf("Erro a abrir/criar ficheiro");
		return 1;
	}

	for(i = 0; i < 10*1024*1024; i++){
		write(file,&c,1);
	}

	close(file);
	return 0;
}
*/


// ex 3
/*
int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Numero de argumentos invalido.\n");
		return 1;
	}
	// long type is the backbone
	long size = strtol(argv[1],0,10);

	char input[size];

	while(read(0,input,size) > 0){
		write(1,input,size);
		memset(input,0,size);
	}

	return 0;
}
*/

/*
// ex 4

time ./ficha1 1 < ex2.txt  > lixo.txt 

real	2m15.291s
user	0m0.936s
sys	2m14.340s



time ./ficha1 1024 < ex2.txt  > lixo.txt 

real	0m0.147s
user	0m0.004s
sys	0m0.140s

*/


