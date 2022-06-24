// Struct ve pointer struct 
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int yas;
	char *isim;

}Insan;

int main(){
	
	Insan ali;
	
	Insan *yasin; // structlarda pointer kullan�labilir. Ayn� pointerda oldu�u gibi malloc kullan�m� vard�r.
	yasin = (Insan *)malloc(sizeof(Insan) ) ; // Insan nesnesinden bir adet olu�turuldu ve yasin de�i�kenine atand�.void olarak gelecek degiskeni Insan * tipine �evirdik.
	
	ali.yas = 30;
	yasin -> yas = 20;   					 // pointer-struct da bu �ekilde kullan�l�yor.
	
	printf("%d",ali.yas);
	printf("\n%d",yasin -> yas);			// pointer-struct da bu �ekilde kullan�l�yor.
	
}
