#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
/*
	commentaire
*/
#define C(fd) close(fd);
#define P "#include<unistd.h>%1$c#include<fcntl.h>%1$c#include<stdio.h>%1$c/*%1$c%4$ccommentaire%1$c*/%1$c#define C(fd) close(fd);%1$c#define P %2$c%3$s%2$c%1$c#define M int main(void){char*a=P;int fd=open(%2$cGrace_kid.c%2$c,O_WRONLY|O_CREAT);dprintf(fd,a,10,34,a,9);C(fd);return(0);}%1$cM%1$c"
#define M int main(void){char*a=P;int fd=open("Grace_kid.c",O_WRONLY|O_CREAT);dprintf(fd,a,10,34,a,9);C(fd);return(0);}
M
