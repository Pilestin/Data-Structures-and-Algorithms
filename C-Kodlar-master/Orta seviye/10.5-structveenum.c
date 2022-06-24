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
	int yas ;				// Direk enum tipini burada yazınca hata veriyor. Bu yüzden ayrıca üstte tanımladık
	gunler en_sevdigi_gun;	// Üstte tanımlanan "gunler" enumundan "en_sevdigi_gun" nesnesi oluşturduk.
}Insan;						
int main(){
	
	Insan yasin;
	yasin.isim = ("Yasin");
	yasin.yas = 20;
	yasin.en_sevdigi_gun = cumartesi;
	
	printf("Benim adim %s , %d yasindayim. En sevdigim gun %u .",yasin.isim , yasin.yas , yasin.en_sevdigi_gun);	// 5 yani cumartesi
	

}
