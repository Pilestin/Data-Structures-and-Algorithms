#include<stdio.h>
// Fonksiyonlarda pointer kullan�m�
int f(int *);
int main(){
	int a = 10;
	int *p;
	p = &a;
	printf("%d",a);
	
	*p = 15;
	printf("\n%d",a);	// Burada a de�eri 15 oldu.
	
	// fonksiyona direk de�er de�il , de�i�ken adresi verilir.
	f(&a);
	printf("\n%d",a); 
}
int f(int *a){	// Call by Reference
	*a = 20;	
	// Fonksiyona gelen 15 de�eri 20 yap�ld� ve adres de de�i�ti�i i�in main fonksiyonunda da 20 g�z�kecek.
}
	

