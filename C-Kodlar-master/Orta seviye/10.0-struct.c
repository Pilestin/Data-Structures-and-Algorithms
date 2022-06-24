#include<stdio.h>
/*-----------Struct----------

	struct etiketadý {
	
		deðiþkentipi deðiþkenadý ;
		deðiþkentipi deðiþkenadý ;
		deðiþkentipi deðiþkenadý ;
		...
		...
		...
	}
*/
struct Ogrenci {
	char ad[20];
	char soyad[20];
	int numara;
	
};

int main(){
	//struct Ogrenci Yasin = {"Yasin" , "Unal", 19060381}; þeklinde de kullanabiliriz.
	struct Ogrenci Yasin = {
		"Yasin","Unal",19060381
	};
	printf("%s %s %d",Yasin.ad , Yasin.soyad , Yasin.numara);
}




