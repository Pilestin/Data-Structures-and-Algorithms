#include<stdio.h>
#include<stdlib.h>

typedef enum {
	pazartesi,	//	0
	sali,		//	1
	carsamba,	//	2
	persembe,	//	3
	cuma,		//	4
	cumartesi,	//	5
	pazar		//	6	
}gunler;

typedef struct{
	char *isim;				// Pointer tipinde yapmazsak null oluyor.
	int yas ;				// Direk enum tipini burada yaz�nca hata veriyor. Bu y�zden ayr�ca �stte tan�mlad�k
	gunler en_sevdigi_gun;	// �stte tan�mlanan "gunler" enumundan "en_sevdigi_gun" nesnesi olu�turduk.
}Insan;						
int main(){
	
	Insan yasin;
	yasin.isim = ("Yasin");
	yasin.yas = 20;
	yasin.en_sevdigi_gun = cumartesi;
	
	printf("Benim adim %s , %d yasindayim. En sevdigim gun %u .",yasin.isim , yasin.yas , yasin.en_sevdigi_gun);	// 5 yani cumartesi
	

}
