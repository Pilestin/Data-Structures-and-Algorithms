#include<stdio.h>
typedef enum{
	bay,	//0 yazd�r�r
	bayan	//1 yazd�r�r
}cinsiyet;

typedef struct{
	int yas;
	char *isim;
	cinsiyet c ; // cinsiyet tipinden yeni bir de�i�ken yaratt�.	
	
}/*typedef burada da olabilirdi*/ Insan;
//typedef silinirse hata verir.

int main(){
	
	Insan ali; //Insan tipinde yani bir nesne yarat�ld�.
	
	ali.yas = 30; 
	ali.isim = ("Alivelideli") ;
	ali.c = bay; // 0 d�nd�r�r.
	
	printf("Ali'nin yasi : %d",ali.yas);
	printf("\nAli'nin adi : %s",ali.isim);
	printf("\nAli'nin cinsiyeti : %u",ali.c);	//enum'u %u ile bast�r�r�z.
	



}
