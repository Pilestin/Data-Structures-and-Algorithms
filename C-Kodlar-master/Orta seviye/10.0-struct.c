#include<stdio.h>
/*-----------Struct----------

	struct etiketadı {
	
		değişkentipi değişkenadı ;
		değişkentipi değişkenadı ;
		değişkentipi değişkenadı ;
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
	//struct Ogrenci Yasin = {"Yasin" , "Unal", 19060381}; şeklinde de kullanabiliriz.
	struct Ogrenci Yasin = {
		"Yasin","Unal",19060381
	};
	printf("%s %s %d",Yasin.ad , Yasin.soyad , Yasin.numara);
}




