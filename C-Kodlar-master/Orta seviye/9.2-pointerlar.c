#include<stdio.h>
int main(){
	
	int *p;
	int a = 10;
	p = &a;
	printf("%d",*p);   		// 10 değerini yazdırır.
	
	*p = 30;
	printf("\n%d",a);		// 30 değerini basar.
	
	// a değerine iki yerden de erişebilir ve değerini değiştirebiliriz.
	
}
