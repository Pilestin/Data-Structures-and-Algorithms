#include <stdio.h>

int main(){
	int *p ;
	int a = 10 ;
	p = &a;
	printf("%d \n",*p);   // 	a n�n de�eri 10'u basar. 					:10
	printf("%d \n",&p);   //		p'nin adresini basar.					:6487576
	printf("%d \n",p);	  //  	p nin de�erini basar.Yani a 'n�n adresi		:6487572
	
	printf("%d \n",a);	  //  	a 'n�n de�erini basar.						:10
	printf("%d \n",&a);	  //		a'n�n adresini basar.					:6487572
	
	
}
