#include<stdio.h>
int main(){
	
	int *p;
	int a = 10;
	p = &a;
	printf("%d",*p);   		// 10 de�erini yazd�r�r.
	
	*p = 30;
	printf("\n%d",a);		// 30 de�erini basar.
	
	// a de�erine iki yerden de eri�ebilir ve de�erini de�i�tirebiliriz.
	
}
