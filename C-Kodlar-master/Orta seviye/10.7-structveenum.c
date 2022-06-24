// Pointer struct ve pointer fonksiyon kullanmak
#include<stdio.h>
#include<stdlib.h>
typedef enum{		// enum tipini önce tanýmlamassan hata veriyor.
	bay,  //0
	bayan //1
}cinsiyet;

typedef struct{
	int yas;
	char *isim;
	cinsiyet c;
}Insan;

int main(){
	
	Insan ali;
	
	Insan *yasin; 
	yasin = (Insan *)malloc(sizeof(Insan) ) ;
	
	//Ýsim  
	yasin->isim = ("Yasin");
	ali.isim = ("Ali");
	//Yas 
	yasin -> yas = 20;
	ali.yas = 58;
	//Cinsiyet
	yasin -> c = bay;
	ali.c = bay ;
	//Emekli mi kontrol için foksiyon çaðýrma 
	emekli_mi(&ali);						// Normal struct olduðu için adres bilgisi gönderilir.
	emekli_mi(yasin);						// Pointer struct olduðu için direk gönderilir.
	

	printf("\n\n Ali'nin  yasi %d , cinsiyeti %u ",ali.yas , ali.c);
	printf("\n Yasin'in yasi %d , cinsiyeti %u",yasin->yas , yasin->c);

}

int emekli_mi (Insan *birey){					// Pointer fonksiyon olduðu için pointer olmayanlar adres bilgisi ile gönderilmelidir.
	
	if (birey -> c == bay && birey -> yas > 55)
		printf("\n %s emeklidir.",birey->isim);
	
	else if (birey -> c == bayan && birey -> yas > 50)
		printf("\n %s emeklidir.",birey->isim);
		
	else
		printf("\n %s emekli degildir." , birey->isim);
		
	return 0 ;
}
