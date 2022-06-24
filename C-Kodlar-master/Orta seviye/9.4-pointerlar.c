#include<stdio.h>
// Fonksiyonlarda pointer kullanýmý
int f(int *);
int main(){
	int a = 10;
	int *p;
	p = &a;
	printf("%d",a);
	
	*p = 15;
	printf("\n%d",a);	// Burada a deðeri 15 oldu.
	
	// fonksiyona direk deðer deðil , deðiþken adresi verilir.
	f(&a);
	printf("\n%d",a); 
}
int f(int *a){	// Call by Reference
	*a = 20;	
	// Fonksiyona gelen 15 deðeri 20 yapýldý ve adres de deðiþtiði için main fonksiyonunda da 20 gözükecek.
}
	

