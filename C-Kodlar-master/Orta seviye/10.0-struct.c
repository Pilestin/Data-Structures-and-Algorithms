#include<stdio.h>
/*-----------Struct----------

	struct etiketad� {
	
		de�i�kentipi de�i�kenad� ;
		de�i�kentipi de�i�kenad� ;
		de�i�kentipi de�i�kenad� ;
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
	//struct Ogrenci Yasin = {"Yasin" , "Unal", 19060381}; �eklinde de kullanabiliriz.
	struct Ogrenci Yasin = {
		"Yasin","Unal",19060381
	};
	printf("%s %s %d",Yasin.ad , Yasin.soyad , Yasin.numara);
}




