#include<stdio.h>
#include<stdlib.h>
int main(){
	int n , i ;
	printf("Kac elemanli bir dizi olusturmak istiyorsun: ");
	scanf("%d",&n);					// Kullan�c�n�n dizi boyutunu belirlemesi i�indir.
	
	int *p = malloc(sizeof(int)*n);	// malloc ba��na (int*) eklemene gerek yok.��nk� bu c++ i�in ge�erli.
	
	for (i=0 ; i<n ; i++){
		int kullanici = 0;
		printf("\nDizinin %d. elemanini gir: ",i+1);
		scanf("%d",&kullanici);
		p[i] = kullanici;					
	}
	for(i=0 ; i<n ; i++)
		printf("\n%d\n",p[i]);
}
