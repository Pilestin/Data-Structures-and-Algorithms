#include<stdio.h>

struct Ogrenci{
	char ad[20];
	char soyad[20];
	char numara[8];
	struct Adress *adresim;	// Yeni structý pointer gibi yapmalýyýz.

	
};
struct Adress{
	char mahalle[20];
	char sokak[20];
	char no[10];
}adresim;

int main(){
	struct Adress adresim = {"71Evler Mahallesi ,","Akagaclar Sokak ,", "no : 11/3"};
	struct Ogrenci Yasin = {"Yasin","Unal\n","1906038\n"};
	printf("Isim\t: %s %sNumara\t: %s",Yasin.ad , Yasin.soyad , Yasin.numara);
	printf("Adresim\t: %s %s %s",adresim.mahalle , adresim.sokak , adresim.no);
}







