#include<stdio.h>
#include<stdlib.h>
int main(){
	int n , i ;
	printf("Kac elemanli bir dizi olusturmak istiyorsun: ");
	scanf("%d",&n);					// Kullanýcýnýn dizi boyutunu belirlemesi içindir.
	
	int *p = malloc(sizeof(int)*n);	// malloc baþýna (int*) eklemene gerek yok.Çünkü bu c++ için geçerli.
	
	for (i=0 ; i<n ; i++){
		int kullanici = 0;
		printf("\nDizinin %d. elemanini gir: ",i+1);
		scanf("%d",&kullanici);
		p[i] = kullanici;					
	}
	for(i=0 ; i<n ; i++)
		printf("\n%d\n",p[i]);
}
