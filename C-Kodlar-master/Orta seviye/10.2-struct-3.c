#include<stdio.h>

struct Ogrenci{
	char name[30];
	struct address *adresim;
};
struct address{
	char mahalle[20];
	char sokak[20];
	char kapi[10];
};

int main(){
	
	struct Ogrenci ilk = {"Yasin Unal"};
	struct address adresim = {"71 Evler Mahallesi","Akagaclar Sokak","No:11/3"};
	printf("Adim %s \n%s %s %s adresinde oturuyorum.",ilk.name,adresim.mahalle,adresim.sokak,adresim.kapi);
} 
