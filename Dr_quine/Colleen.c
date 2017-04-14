#include<stdio.h>
int func(){return(0);}
/*
	un commentaire
*/
int main(){
	/*
		un autre commentaire
	*/
	char*a="#include<stdio.h>%1$cint func(){return(0);}%1$c/*%1$c%4$cun commentaire%1$c*/%1$cint main(){%1$c%4$c/*%1$c%4$c%4$cun autre commentaire%1$c%4$c*/%1$c%4$cchar*a=%2$c%3$s%2$c;%1$c%4$cprintf(a,10,34,a,9);%1$c%4$creturn(0);%1$c}%1$c";
	printf(a,10,34,a,9);
	return(0);
}
