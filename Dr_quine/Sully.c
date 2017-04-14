#include<strings.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#define P "#include<strings.h>%3$c#include<unistd.h>%3$c#include<stdlib.h>%3$c#include<stdio.h>%3$c#include<fcntl.h>%3$c#define P %4$c%5$s%4$c%3$cint main(){int i = %1$d;char*a=P;char f[64];char e[64];bzero(f,64);bzero(e,64);sprintf(f,%4$cSully_%6$cd.c%4$c,i);int fd=open(f,O_RDWR|O_CREAT,0666);dprintf(fd,a,i-1,9,10,34,a,37);close(fd);if(i>0){sprintf(e,%4$cclang %6$c1$s -o Sully_%6$c2$d && ./Sully_%6$c2$d%4$c,f,i);system(e);}else if(i==0){sprintf(e,%4$cclang %6$cs -o Sully_%6$cd%4$c,f,i);system(e);}return(0);}%3$c"
int main(){int i = 5;char*a=P;char f[64];char e[64];bzero(f,64);bzero(e,64);sprintf(f,"Sully_%d.c",i);int fd=open(f,O_RDWR|O_CREAT,0666);dprintf(fd,a,i-1,9,10,34,a,37);close(fd);if(i>0){sprintf(e,"clang %1$s -o Sully_%2$d && ./Sully_%2$d",f,i);system(e);}else if(i==0){sprintf(e,"clang %s -o Sully_%d",f,i);system(e);}return(0);}
