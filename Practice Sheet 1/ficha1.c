#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/*
// ex 1
int main(int argc, char *argv[]){
	char input;
	while(read(0,&input,1) > 0){
		write(1,&input,1);
	}
	return 0;
}
*/


/*
// ex 2

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

	for(i = 0; i < 10*1024; i++){
		write(file,&c,1);
	}

	close(file);
	return 0;
}

*/

// ex 3

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Numero de argumentos invalido.\n");
		return 1;
	}

	int size = atoi(argv[1]);

	char *input;
	input = malloc(sizeof(char) * size);

	while(read(0,&input,sizeof(char) * size) > 0){
		write(1,&input,sizeof(char) * size);
		input = "";
	}

	return 0;
}

