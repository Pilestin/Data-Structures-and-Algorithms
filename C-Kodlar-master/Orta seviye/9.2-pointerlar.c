#include<stdio.h>
int main(){
	
	int *p;
	int a = 10;
	p = &a;
	printf("%d",*p);   		// 10 deðerini yazdýrýr.
	
	*p = 30;
	printf("\n%d",a);		// 30 deðerini basar.
	
	// a deðerine iki yerden de eriþebilir ve deðerini deðiþtirebiliriz.
	
}
