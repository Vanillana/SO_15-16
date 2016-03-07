
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
//ex 1
/*
int main(int argc, char* argv[]){

	char buff; // char, &buff (char *)

	while(read(0,&buff,1) > 0){
		write(1,&buff,1);
	}

}
*/


//------------------------------------------------------------

//ex 2
// prof
/*
int main(int argc, char * argv[]){
	int fdout, i;
	char a='a';

	fdout=open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fdout==-1) exit(1);

	for(i = 0;i<10*1024*1024;i++)
		write(fdout, &a,1);
	close(fdout);
	return 0;
}

*/

//----------------------------------------------------------


// prof
//ex 3
/*
int main(int argc, char * argv[]){
	int fdout, i;
	char a[1024];

	memset(a,'c',1024);
	fdout=open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fdout==-1) _exit(1);

	for(i = 0;i<10*1024*1024;i++)
		write(fdout, a,1024);
	close(fdout);
	return 0;
}
*/

//----------------------------------------------------------

// prof

int main(int argc, char * argv[]){

	char* buff;
	int r, s = 1;

	if (argc >= 2) s = atoi(argv[1]);
	buff = malloc(sizeof(char*) * s);

	while ((r = read(0,buff,s)) > 0)
		write(1,buff,r);
}


//------------------------------------------------------------

// prof
/*
int main(int argc, char * argv[]){

	long r, s=1024;

	if (argc >= 2) s=strtol(argv[1],0,10);

	char buff[s];

	while ((r=read(0,buff,s)) > 0)
		write(1,buff,r);
}
*/

//-------------------------------------------------------------

//ex 5 e 6
/*
ssize_t readln(int fildes, char* buff, size_t nbyte){
	int r;
	while((r=read(fildes,&buff,nbyte)) > 0)
		sprintf(buff, "%d", r);
	return 0;
}


int main(int argc, char* argv[]){
	int fildes;
	size_t nbyte = 1024;
	char buff[nbyte],b[nbyte];

	fildes = open(argv[1],O_RDONLY);
	if(fildes==-1) exit(1);
	while()
		sprintf(buff, "%d", )
		sprintf(buff, "%d", readln(fildes, &buff, nbyte));
	}

	return 0;

}


//prof
ssize_t readln(int fildes, char *buf, size_t nbyte){
	int p=0;
	int r;

	while((r=read(fildes, &buf[p],1))>0 && buf[p]!='\n' && p<nbyte) p++;
	return r= 1 ? p+1: 0;
}

int main(int argc, char* argv[]){
	int r,l=0,fdin=0;
	char buff[1032];

	memset(buff,' ',8);
	if (argc >= 2)
		fdin=open(argv[1],O_RDONLY);
	if(fdin==-1) exit(1);

	while((r=readln(fdin,buff+8,1024))>0){
		sprintf(buff,"%d",++l);
		write(1,buff,r+8);
	}
}
*/