#include<stdio.h>
typedef enum{
	bay,	//0 yazdırır
	bayan	//1 yazdırır
}cinsiyet;

typedef struct{
	int yas;
	char *isim;
	cinsiyet c ; // cinsiyet tipinden yeni bir değişken yarattı.	
	
}/*typedef burada da olabilirdi*/ Insan;
//typedef silinirse hata verir.

int main(){
	
	Insan ali; //Insan tipinde yani bir nesne yaratıldı.
	
	ali.yas = 30; 
	ali.isim = ("Alivelideli") ;
	ali.c = bay; // 0 döndürür.
	
	printf("Ali'nin yasi : %d",ali.yas);
	printf("\nAli'nin adi : %s",ali.isim);
	printf("\nAli'nin cinsiyeti : %u",ali.c);	//enum'u %u ile bastırırız.
	



}
