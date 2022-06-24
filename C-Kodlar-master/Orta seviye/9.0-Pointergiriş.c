#include <stdio.h>

int main(){
	int *p ;
	int a = 10 ;
	p = &a;
	printf("%d \n",*p);   // 	a nýn deðeri 10'u basar. 					:10
	printf("%d \n",&p);   //		p'nin adresini basar.					:6487576
	printf("%d \n",p);	  //  	p nin deðerini basar.Yani a 'nýn adresi		:6487572
	
	printf("%d \n",a);	  //  	a 'nýn deðerini basar.						:10
	printf("%d \n",&a);	  //		a'nýn adresini basar.					:6487572
	
	
}
